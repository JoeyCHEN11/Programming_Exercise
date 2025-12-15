s = list(input())
n = int(input())
m = len(s)

def fillempty(mid: int) -> int:
    ans = 0
    for i in range(len(s)):
        mask = (n >> (len(s) - 1 - i) & 1)
        ans <<= 1
        if i < mid:
            ans |= (s[i] == '1') | ((s[i] == '?') & mask)
        elif i > mid:
            ans |= (s[i] == '1') | ((s[i] == '?'))
            
    return ans if ans <= n else -1

ans = fillempty(-1)
for m in range(len(s)):
    if s[m] != '1':
        ans = max(ans, fillempty(m))
            
print(ans)
