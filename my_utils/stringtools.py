# return the longest parlindrome substring
# O(n) time
def longestParlindrome(s: str) -> str:
    maxP, maxPi = 0, 0
    manaS = ['$#']
    for c in s:
        manaS.append(c)
        manaS.append('#')
    manaS.append('@')
    t = ''.join(manaS)
    n = len(t) - 1
    
    f = [0] * n
    rMax, iMax = 0, 0
    for i in range(1, n):
        j = 2 * iMax - i
        f[i] = min(rMax - i + 1, f[j]) if i < rMax else 1
        
        while(t[i + f[i]] == t[i - f[i]]): f[i] += 1

        if(i + f[i] - 1 > rMax):
            rMax = i + f[i] - 1 
            iMax = i
        
        if(f[i] > maxP):
            maxP = f[i]
            maxPi = i
        
    ans = []
    left = maxPi - maxP + 1
    right = maxPi + maxP - 1
    for i in range( left + 1 if t[left] == '#' else left, right + 1, 2):
        ans.append(t[i])
    
    return ''.join(ans)

def edit_distance(s1: str, s2: str) -> int:
    m, n = len(s1), len(s2)
    dp = [[0] * (n + 1) for _ in range(m + 1)]

    for i in range(m + 1):
        dp[i][0] = i
    for j in range(n + 1):
        dp[0][j] = j
            
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if s1[i - 1] == s2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]
            else:
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1
    return dp[m][n]