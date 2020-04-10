import matplotlib.pyplot as plt
import numpy as np

#画个sin函数
x = np.linspace(0, 2 * np.pi, 50)
y = np.sin(x)
# plt.plot(x, y)
# plt.show()

#绘制两个图像
# plt.plot(x, y)
# plt.plot(x, y * 2)
# plt.show()
#
# #构建子图
# ax1 = plt.subplot(2, 1, 1) # （行，列，活跃区）
# plt.plot(x, np.sin(x), 'r')
#
# ax2 = plt.subplot(2, 3, 4)
# plt.plot(x, 2 * np.sin(x), 'g')
#
# ax3 = plt.subplot(2, 3, 5, sharey=ax2)
# plt.plot(x, np.cos(x), 'b')
#
# ax4 = plt.subplot(2, 3, 6, sharey=ax2)
# plt.plot(x, 2 * np.cos(x), 'y')
#
# plt.show()

#散点图
# k = 500
# x = np.random.rand(k)
# y = np.random.rand(k)
# size = np.random.rand(k) * 50 # 生成每个点的大小
# colour = np.arctan2(x, y) # 生成每个点的颜色大小
# plt.scatter(x, y, s=size, c=colour)
# plt.colorbar() # 添加颜色栏
#
# plt.show()

#柱状图
k = 10
x = np.arange(k)
y = np.random.rand(k)
plt.bar(x, y) # 画出 x 和 y 的柱状图
# 增加数值
for x, y in zip(x, y):
    plt.text(x, y , '%.2f' % y, ha='center', va='bottom')
plt.show()