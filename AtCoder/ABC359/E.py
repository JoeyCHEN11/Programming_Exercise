n = int(input())
heights = list(map(int, input().split()))
INF = float('inf')
ans = [0] * n
st = [(INF, -1)]
timer = 0
for i in range(n):
    timer += heights[i]
    prev_x = i
    while st[-1][0] <= heights[i]:
        h, x = st.pop()
        timer += (heights[i] - h) * (prev_x - x)
        prev_x = x
    st.append((heights[i], prev_x))
    ans[i] = timer + 1
    
for a in ans:
    print(a, end = ' ')