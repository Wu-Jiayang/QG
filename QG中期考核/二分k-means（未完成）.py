import pandas as pd
import numpy as np
from matplotlib import pyplot as plt

def k_means(data, k):
    shape = data.shape[1]-1
    trainingSet = data[range(0, shape)]
    trainingSet[shape] = 0
    clusterCenter = data[range(0, shape)].sample(k).reset_index(drop=True)
    end = True
    while end:                                                                      # 结束条件为：所有点的类别未发生变动
        end = False
        for i in range(0, k):
            for j in range(0, shape):  # 计算距离
                if not j:
                    a = (trainingSet[j] - clusterCenter.loc[i][j]) ** 2
                else:
                    a += (trainingSet[j] - clusterCenter.loc[i][j]) ** 2
            if not i:  # 将到各中心的距离组成dataframe形式
                df = pd.DataFrame(a)
            else:
                df = pd.concat([df, a], axis=1, ignore_index=True)
        for i in range(0, len(df)):  # 计算距离最小的聚类中心
            if trainingSet.loc[i, shape] != np.random.choice(
                    df.loc[i][df.loc[i] == df.loc[i].min()].index):
                end = True
                trainingSet.loc[i, shape] = np.random.choice(
                    df.loc[i][df.loc[i] == df.loc[i].min()].index)
        for i in range(0, k):
            for j in range(0, shape):
                clusterCenter.loc[i, j] = trainingSet[trainingSet[shape] == i][j].mean()
    return trainingSet, clusterCenter

def SSE(x):             # 计算距离（即代价函数）
    a = 0
    for i in range(0, len(x)-1):
        a += (x[i] - clusterCenter.loc[x[len(x)-1], i]) ** 2
    return a

data = pd.read_csv('数据集/iris/iris.data', header=None)
trainingSet, clusterCenter = k_means(data, 1)
#while len(clusterCenter) < 3:
for i in range(0, len(clusterCenter)):
    temp1, temp2 = k_means(trainingSet[trainingSet[trainingSet.shape[1]-1] == i], 2)
    print(temp1)