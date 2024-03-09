# Experiment Overview

This experiment consists of three main stages: Data Visualization and Preprocessing, Data Segmentation, and Data Labeling, followed by Machine Learning Training. Each stage plays a crucial role in the overall process of analyzing and building a predictive model.

## 513.ipynb - Data Visualization and Preprocessing

This notebook focuses on visualizing the data and performing preprocessing tasks before further analysis. It includes the following steps:

1. **Data Visualization**: Visualizes the provided data to gain insights into its characteristics and distributions.

2. **Data Preprocessing**: Preprocesses the data by extracting time and second fractions, converting them to timedelta and float, respectively. It then combines these parts to calculate the total duration. Additionally, it deals with potential duplicate timestamps and reorders the data based on timestamp values.

3. **Segmentation**: Segments the data into smaller time intervals and saves each segment as a separate CSV file for further analysis.

## label.py - Data Labeling

This Python script is responsible for labeling the data by calculating various statistical features for each file. The labeling process involves the following steps:

1. **Feature Calculation**: Calculates statistical features such as mean, minimum, maximum, root mean square (RMS), standard deviation, skewness, and kurtosis for each column in the dataset, excluding the "Time" and "Duration" columns.

2. **Processing Files**: Processes all CSV files in the specified folder, calculating features for each file individually.

3. **Data Aggregation**: Aggregates all calculated features into a single DataFrame.

4. **Output Generation**: Saves the aggregated features to a CSV file for further analysis or model training.

## ML.ipynb - Machine Learning Training

This notebook focuses on training machine learning models using the preprocessed and labeled data. It follows the standard machine learning workflow, including the following steps:

1. **Data Loading**: Loads the preprocessed and labeled data for model training.

2. **Model Initialization**: Initializes various machine learning models such as Logistic Regression, K-Nearest Neighbors, Support Vector Machine, and Decision Tree.

3. **Cross-Validation**: Performs k-fold cross-validation for each model to evaluate their performance using accuracy as the metric.

4. **Model Training and Evaluation**: Trains each model on the training data and evaluates its performance on the test data. Additionally, it prints the average accuracy obtained through cross-validation for each model.

5. **Visualization (Optional)**: Visualizes the correlation matrix of the data using a heatmap.

## Instructions for Running the Code

1. Ensure you have Python and Jupyter Notebook installed on your system.
2. Clone this repository to your local machine.
3. Navigate to the directory containing the notebook or Python script you want to run.
4. Open the notebook/script using Jupyter Notebook or your preferred Python IDE.
5. Run each cell in the notebook/script sequentially to execute the code.
6. Follow any additional instructions provided within the notebook/script for data loading or file paths.

By following these instructions, you can replicate the experiment and analyze your own data using the provided code.
