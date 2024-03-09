# Postoperative rehabilitation exercise recognition for knee replacement surgery

This project demonstrates how to collect data from sensors and input it to show the implementation of different machine learning models for activity classification based on sensor data collected during postoperative rehabilitation exercises for knee replacement surgery.

### Contribution

Utilizing data from three IMUs enables comprehensive knee joint motion representation, while machine learning models trained on this data identify various motions, offering personalized rehabilitation plans.

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




## Data Collection

- **IMU (MPU6050) Configuration**: 6-axis (Accelerometer XYZ, Gyroscope XYZ)
- **Measurement Points**:
  - Measurement Point 1: Thigh
  - Measurement Point 2: Calf
  - Measurement Point 3: Foot
- ** Data Collection and Processing
- Data collection interval: 0.1 second
- Data is collected from three IMU sensors attached to the thigh, calf, and foot.
- Collected sensor data is processed and stored in a data frame for feature extraction and model inference.


## Rehabilitation Moves Recognition

The system recognizes and detects three rehabilitation moves:

1. **M1: Ankle Pump Exercise**
2. **M2: Straight Leg Raise**
3. **M3: Side Leg Raise**

## Data Processing

- **Data Visualization**: Ensure precise monitoring and evaluation of patient exercises during the recovery period.
- **Data Segmentation**: Segments data into 2-second intervals.
- **Applying Filters**: Applying Moving Average Filter and other appropriate filtering techniques to remove noise and improve data quality.

## Feature Engineering

- **Time Series Data**: 20-second time series data collected for each action.
- **Feature Extraction**: Extracts 7 features including Skewness, Average Kurtosis, Minimum, Maximum, RMS, and Standard Deviation.

## Model Training and Evaluation

- **Model**: Decision Tree
- **Accuracy**: 94.96%
- **Comparison with Other Models**:
  - Random Forest: 94.69%
  - K-Nearest Neighbors: 94.17%
  - Support Vector Machine: 93.90%
  - Logistic Regression: 93.90%

## Dataset Information

- **Number of Participants**: 6 individuals
- **Duration of Each Action**: 20 seconds per action
- **Ground Truth**: Camera (Video)
- **Data Composition**:
  - Action 1: 133 samples
  - Action 2: 133 samples
  - Action 3: 110 samples
  - Flattened: 18 axes into a 256-dimensional feature vector within a 2-second interval.
 
## Model Training Deployment
- A pre-trained Edge Impulse model is utilized for inference on the collected sensor data.
- Features extracted from the data frame are used as input to the model.
- Inference results include the predicted exercise and associated confidence scores.


## Conclusion

The system achieves high accuracy in recognizing postoperative rehabilitation exercises for knee replacement surgery, providing valuable insights for personalized rehabilitation plans.

## References

- [MPU6050 Datasheet](https://www.invensense.com/wp-content/uploads/2015/02/MPU-6000-Datasheet1.pdf)
- [Decision Tree Classifier](https://scikit-learn.org/stable/modules/tree.html)
- [Random Forest Classifier](https://scikit-learn.org/stable/modules/generated/sklearn.ensemble.RandomForestClassifier.html)
- [K-Nearest Neighbors Classifier](https://scikit-learn.org/stable/modules/neighbors.html)
- [Support Vector Machine Classifier](https://scikit-learn.org/stable/modules/svm.html)
- [Logistic Regression Classifier](https://scikit-learn.org/stable/modules/generated/sklearn.linear_model.LogisticRegression.html)

## References

- [Edge Impulse](https://www.edgeimpulse.com/) - Official website of the Edge Impulse platform
- [Edge Impulse Arduino Library](https://docs.edgeimpulse.com/docs/arduino-porting) - Official Edge Impulse Arduino library documentation
- [Wire Library](https://www.arduino.cc/en/reference/wire) - Arduino Wire library reference documentation
- [JY901 Library](https://github.com/MengYingjie/JY901) - JY901 IMU sensor Arduino library
