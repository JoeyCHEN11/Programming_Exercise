from geometry import *
import matplotlib.pyplot as plt

# 示例点数据
points = [Point(0.5, 0.5), Point(1.5, 1.5), Point(2.5, 0.5)]

# 提取x和y坐标
x, y = zip(*points)
# 创建图形和轴对象
fig, ax = plt.subplots()

# 绘制点
ax.scatter(x, y, color='blue', label='Points')

# 设置轴标签和标题
ax.set_xlabel('X-axis')
ax.set_ylabel('Y-axis')
ax.set_title('Scatter Plot of Points')

# 显示图例
ax.legend()

# 显示图形
plt.show()



s = Segment(Point(1, 1), Point(0, 1))
print(isinstance(s, Line))