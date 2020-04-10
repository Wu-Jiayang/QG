import pandas as pd
import numpy as np

# 通过numpy数组创建Series
# pd.Series(np.arange(4,10))
# pd.Series([11,12,14], index=['北京','上海','广州'])

#创建一个3行4列的Dataframe数据
data_3_4 = pd.DataFrame(np.arange(10,22).reshape(3,4))
#打印第一行数据
# data_3_4[:1]
#打印第一列数据
# data_3_4[:][0]

#读取
#data = pd.read_csv('pandas_open.csv')
#去除控制
#data.dropna()
