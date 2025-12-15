N = int(input())
cards = [tuple(map(int, input().split())) for _ in range(N)]
MOD = 998244353
# 0: flip cnt when A face up, 1: flip cnt when B face up
dp = [[0] * (2) for _ in range(N + 1)]
dp[1][0], dp[1][1] = 1, 1

for i in range(2, N + 1):
    # concider different faces up:
    for curf in range(2):
        for pref in range(2):
            if cards[i - 1][curf] != cards[i - 2][pref]:
                dp[i][curf] += dp[i - 1][pref]
    
    dp[i][0], dp[i][1] = dp[i][0] % MOD, dp[i][1] % MOD
    
    # if cards[i - 1][0] != cards[i - 2][0]:
    #     dp[i][0] += dp[i - 1][0]
    # if cards[i - 1][0] != cards[i - 2][1]:
    #     dp[i][0] += dp[i - 1][1]
    # if cards[i - 1][1] != cards[i - 2][0]:
    #     dp[i][1] += dp[i - 1][0]
    # if cards[i - 1][1] != cards[i - 2][1]:
    #     dp[i][1] += dp[i - 1][1]

print(sum(dp[N]) % MOD)
    
