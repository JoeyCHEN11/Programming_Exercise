x, y, z = map(int, input().split())
s = input()
n = len(s)
# dpCap[i][0]: min time to print s[:i] when cap is off
# dpCap[i][1]: ...                                 on
dpCap = [[0] * 2 for _ in range(n + 1)]

dpCap[0][1] = z
dpCap[0][0] = 0

for i, c in enumerate(s, 1):
    if c == 'a':
        dpCap[i][0] = min(dpCap[i - 1][0] + x, dpCap[i - 1][1] + z + x)
        dpCap[i][1] = min(dpCap[i - 1][0] + z + y, dpCap[i - 1][1] + y)
    else:
        dpCap[i][0] = min(dpCap[i - 1][0] + y, dpCap[i - 1][1] + z + y)
        dpCap[i][1] = min(dpCap[i - 1][0] + z + x, dpCap[i - 1][1] + x)
print(min(dpCap[-1]))        