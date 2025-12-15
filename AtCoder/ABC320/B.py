t = input()


def longestParlidrome(s: str) ->int:
    n = len(s)
    for l in range(n, 0, -1):
        for i in range(n - l + 1):
            # print(reversed(s))
            if ''.join(reversed(s[i:i + l])) == s[i:i + l]:
                return l
    return 0
# return the longest parlindrome substring
# O(n) time
def manacher(s: str) -> str:
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

# ans = manacher(t)
# # print(ans)
# print(len(ans))
            
print(longestParlidrome(t))