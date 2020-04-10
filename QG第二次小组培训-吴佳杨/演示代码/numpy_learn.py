import numpy as np
# 创建简单的列表
a = [1, 2, 3, 4]
# 将列表转换为数组
b = np.array(a)

#数组元素的个数
#b.size
#数组形状
#b.shape

#创建一个10行10列的浮点数为1的矩阵
array_one = np.ones([10, 10])
#创建一个10行10列的数值为0.的矩阵
array_zero = np.zeros([10, 10])

# 建立一个两列五行的矩阵
stus_score = np.array([[80, 88], [82, 81], [84, 75], [86, 83], [75, 81]])
# stus_score > 80
#每一列的最大值
result_axis0 = np.amax(stus_score, axis=0)
#每一行的最大值
result_axis1 = np.amax(stus_score, axis=1)

#所有数据都加上5
#stus_score+5

#矩阵乘法
x = np.array([[1., 2.], [4., 5.]])
y = np.array([[6., 23.], [-1, 7]])
#np.dot(x, y)  点乘
#np.linalg.inv(x) #求逆
#x.T  #转置

