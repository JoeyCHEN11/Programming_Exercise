n = int(input())
courses = [tuple(map(int, input().split())) for _ in range(n)]
# 0: healthy max, 1: upset max
dp = [[0] * (n + 1) for _ in range(2)]
for i, (x, y) in enumerate(courses, 1):
    if x == 0:
        # eat or don not eat
        dp[0][i] = max(dp[0][i - 1], dp[0][i - 1] + y, dp[1][i - 1] + y)
        dp[1][i] = dp[1][i - 1]
    else:
        # eat or donnot eat
        dp[1][i] = max(dp[0][i - 1] + y, dp[1][i - 1])
        dp[0][i] = dp[0][i - 1]
print(max(dp[0][n], dp[1][n]))