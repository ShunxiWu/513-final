# Using Serial Data for Edge Impulse Model Inference Example

This example demonstrates how to collect data from sensors and input it into an Edge Impulse model for inference using Arduino. We will collect data from sensors and classify it after filling a data frame.

## Requirements

### Hardware

- Arduino board (Arduino Uno is used in this example)
- Sensor compatible with Arduino (JY901 IMU sensor is used in this example)
- I2C Multiplexer for multiple sensors connected via I2C (TCA9548 is used in this example)

### Software

- [Arduino IDE](https://www.arduino.cc/en/software) (or any other Arduino development environment of your choice)
- [Edge Impulse Arduino Library](https://docs.edgeimpulse.com/docs/arduino-porting) (for running Edge Impulse models on Arduino)
- [Wire Library](https://www.arduino.cc/en/reference/wire) (for I2C communication)
- [JY901 Library](https://github.com/MengYingjie/JY901) (for communication with JY901 IMU sensor)

## Usage

1. Make sure you have added all the required libraries to your Arduino IDE and replace `your_project_inference.h` in the code with the inference library of your Edge Impulse project.
2. Connect your sensors to Arduino and adjust the address in the `pcaselect` function to select the sensor you want to read if necessary.
3. Connect Arduino to your computer and upload the code to the Arduino board.
4. Open the serial monitor to view the inference results.

## Notes

- The code in this example assumes you have trained a model on the Edge Impulse platform that can handle accelerometer and gyroscope data, and the input size of the model is `EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE`.
- Ensure that your model configuration matches the feature padding used in the code to ensure proper classification results.
- You can modify and customize according to your specific requirements if needed.

## References

- [Edge Impulse](https://www.edgeimpulse.com/) - Official website of the Edge Impulse platform
- [Edge Impulse Arduino Library](https://docs.edgeimpulse.com/docs/arduino-porting) - Official Edge Impulse Arduino library documentation
- [Wire Library](https://www.arduino.cc/en/reference/wire) - Arduino Wire library reference documentation
- [JY901 Library](https://github.com/MengYingjie/JY901) - JY901 IMU sensor Arduino library
