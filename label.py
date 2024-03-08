import os
import pandas as pd
import numpy as np
from scipy.stats import skew, kurtosis

# 读取CSV文件并计算特征
def calculate_features(file_path):
    # 读取除了 "Time" 和 "Duration" 列之外的所有列，并跳过前两行
    df = pd.read_csv(file_path, usecols=lambda x: x.lower() not in ['time', 'duration'])
    feature_dict = {'Movement': 3}  # 初始化特征字典
    features = []
    
    # 计算每列的特征
    for column in df.columns:
        feature_dict[column + ' Average'] = df[column].mean()
        feature_dict[column + ' Minimum'] = df[column].min()
        feature_dict[column + ' Maximum'] = df[column].max()
        feature_dict[column + ' RMS'] = np.sqrt(np.mean(df[column]**2))
        feature_dict[column + ' Stdev'] = df[column].std()
        feature_dict[column + ' Skewness'] = skew(df[column])
        feature_dict[column + ' Kurtosis'] = kurtosis(df[column])
    features.append(feature_dict)  # 将特征字典添加到列表中
    return features


# 处理所有CSV文件
def process_files_in_folder(folder_path):
    all_files = os.listdir(folder_path)
    all_features = []
    for file_name in all_files:
        if file_name.endswith('.csv'):
            file_path = os.path.join(folder_path, file_name)
            features = calculate_features(file_path)
            all_features.extend(features)  # 使用extend将每个文件的特征合并到一起
    return all_features


# 文件夹路径
folder_path = r"C:\Users\Shun-Xi Wu\Downloads\3"  # 请根据你的实际情况修改路径

# 处理文件夹中的文件并保存结果
all_features = process_files_in_folder(folder_path)

# 转换为DataFrame
df = pd.DataFrame(all_features)

# 保存结果到一个大的CSV文件中
output_path = r"C:\Users\Shun-Xi Wu\Downloads\3output.csv"  # 请根据需要修改输出路径
df.to_csv(output_path, index=False)
