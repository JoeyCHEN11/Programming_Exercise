n = int(input())

# 一口气输入，map是对后面的list里每一个数据进行处理，lambda的x代表单项而不是整个列表
# lis = [ tuple(map(lambda x : int(x) if x.isdigit() else x , input().split())) for _ in range(n)]

names = [''] * n
scores = [0] * n
# print(names)

for i in range(n):
    name, score = input().split()
    names[i], scores[i] = name, int(score)
    
t = sum(scores)
names.sort()
print(names[t % n])
