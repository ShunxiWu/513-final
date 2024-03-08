import pandas as pd
from sklearn.model_selection import KFold
from sklearn.linear_model import LogisticRegression
from sklearn.neighbors import KNeighborsClassifier
from sklearn.svm import SVC
from sklearn.tree import DecisionTreeClassifier
from sklearn import metrics
import matplotlib.pyplot as plt
import seaborn as sns

# Load your data
# Replace 'data.csv' with the actual path to your CSV file containing the data
data = pd.read_csv('data.csv')

# Split the data into features (X) and labels (y)
X = data.iloc[:, 1:]  # Assuming your label column is the first column
y = data.iloc[:, 0]   # Assuming your label column is named 'Movement'

# Initialize models
models = {
    'Logistic Regression': LogisticRegression(),
    'K-Nearest Neighbors': KNeighborsClassifier(),
    'Support Vector Machine': SVC(),
    'Decision Tree': DecisionTreeClassifier()
}

# Perform K-fold cross-validation for each model
k = 5  # Number of folds
kf = KFold(n_splits=k, shuffle=True)

for name, model in models.items():
    accuracies = []  # To store accuracies for each fold
    for train_index, test_index in kf.split(X):
        X_train, X_test = X.iloc[train_index], X.iloc[test_index]
        y_train, y_test = y.iloc[train_index], y.iloc[test_index]
        
        model.fit(X_train, y_train)
        y_pred = model.predict(X_test)
        accuracy = metrics.accuracy_score(y_test, y_pred)
        accuracies.append(accuracy)
    
    # Calculate average accuracy across all folds
    avg_accuracy = sum(accuracies) / k
    print(f'The average accuracy of {name} using {k}-fold cross-validation is: {avg_accuracy}')

# Additional visualization (optional)
plt.figure(figsize=(8, 4))
sns.heatmap(data.corr(), annot=True, cmap='cubehelix_r')
plt.show()
