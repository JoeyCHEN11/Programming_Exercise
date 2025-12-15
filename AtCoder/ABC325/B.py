from collections import defaultdict
n = int(input())
emp_clk = [tuple(map(int, input().split())) for _ in range(n)]
clkCheck = [0] * 24
for emp, clk in emp_clk:
    clkCheck[clk] += emp
    
ans = 0
for i in range(24):
    s = 0
    for j in range(9):
        s += clkCheck[(i + j) % 24]
    ans = max(ans, s)
    
print(ans)