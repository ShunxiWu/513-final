#include <a513_inferencing.h>
#include <JY901.h>
#include <Wire.h>
#include "TCA9548.h"

CJY901 jy1;
CJY901 jy2;
CJY901 jy3;
#define PCAADDR 0x70

const unsigned long dataCollectionInterval = 100; // 0.1 second
const unsigned long printInterval = 2000; // 1 second
unsigned long lastDataCollectionTime = 0;
unsigned long lastPrintTime = 0;

// to classify 1 frame of data you need EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE values
float features[EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE];
// keep track of where we are in the feature array
size_t feature_ix = 0;

void setup() {
    Serial.begin(115200);
    Serial.println("Started");
    pcaselect(0);
    jy1.startIIC();

    pcaselect(1);
    jy2.startIIC();

    pcaselect(2);
    jy3.startIIC();
    delay(1000);
}

void loop() {
    unsigned long currentTime = millis();

    if (currentTime - lastDataCollectionTime >= dataCollectionInterval) {
        collectData();
        lastDataCollectionTime = currentTime;
    }

    if (currentTime - lastPrintTime >= printInterval) {
        printCollectedData();
        lastPrintTime = currentTime;
    }
}

void collectData() {
    pcaselect(0);
    features[feature_ix++] = jy1.getAccX();
    features[feature_ix++] = jy1.getAccY();
    features[feature_ix++] = jy1.getAccZ();
    features[feature_ix++] = jy1.getGyroX();
    features[feature_ix++] = jy1.getGyroY();
    features[feature_ix++] = jy1.getGyroZ();

    pcaselect(1);
    features[feature_ix++] = jy2.getAccX();
    features[feature_ix++] = jy2.getAccY();
    features[feature_ix++] = jy2.getAccZ();
    features[feature_ix++] = jy2.getGyroX();
    features[feature_ix++] = jy2.getGyroY();
    features[feature_ix++] = jy2.getGyroZ();

    pcaselect(2);
    features[feature_ix++] = jy3.getAccX();
    features[feature_ix++] = jy3.getAccY();
    features[feature_ix++] = jy3.getAccZ();
    features[feature_ix++] = jy3.getGyroX();
    features[feature_ix++] = jy3.getGyroY();
    features[feature_ix++] = jy3.getGyroZ();

    // features buffer full? then classify!
    if (feature_ix == EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE) {
        ei_impulse_result_t result;

        // create signal from features frame
        signal_t signal;
        numpy::signal_from_buffer(features, EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE, &signal);

        // run classifier
        EI_IMPULSE_ERROR res = run_classifier(&signal, &result, false);
        if (res != 0) {
            ei_printf("run_classifier returned error: %d\n", res);
            return;
        }

        // print predictions
        ei_printf("Predictions (DSP: %d ms., Classification: %d ms., Anomaly: %d ms.): \n",
                   result.timing.dsp, result.timing.classification, result.timing.anomaly);

        // print the predictions
        for (size_t ix = 0; ix < EI_CLASSIFIER_LABEL_COUNT; ix++) {
            ei_printf("%s:\t%.5f\n", result.classification[ix].label, result.classification[ix].value);
        }
        #if EI_CLASSIFIER_HAS_ANOMALY == 1
            ei_printf("anomaly:\t%.3f\n", result.anomaly);
        #endif

        // reset features frame
        feature_ix = 0;
    }
}

void printCollectedData() {
    // Optionally, you can print the collected data here
}

void ei_printf(const char *format, ...) {
    static char print_buf[1024] = { 0 };

    va_list args;
    va_start(args, format);
    int r = vsnprintf(print_buf, sizeof(print_buf), format, args);
    va_end(args);

    if (r > 0) {
        Serial.write(print_buf);
    }
}

void pcaselect(uint8_t i) {
    if (i > 7) return;
 
    Wire.beginTransmission(PCAADDR);
    Wire.write(1 << i);
    Wire.endTransmission();  
}
