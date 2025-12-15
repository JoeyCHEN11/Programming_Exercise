n = int(input())
courses = [tuple(map(int, input().split())) for _ in range(n)]
# 0: max tastiness wahtever the state, 1: max with health stomach
# dp[0][i] >= dp[1][i]
dp = [[0] * (n + 1) for _ in range(2)]
for i, (x, y) in enumerate(courses, 1):
    if x == 0:
        # eat or do not eat
        dp[0][i] = max(dp[0][i - 1], dp[0][i - 1] + y)
        dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + y)
    else: # posison
        # eat or do not eat
        dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + y)
        # cannot eat
        dp[1][i] = dp[1][i - 1]
# print(dp)
print(dp[0][n])