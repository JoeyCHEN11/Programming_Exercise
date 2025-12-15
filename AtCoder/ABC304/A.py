n = int(input())
names, ages = [], []
for _ in range(n):
    name, age = input().split()
    names.append(name)
    ages.append(int(age))

names += names
i = ages.index(min(ages))
for a in names[i: i + n]:
    print(a)

