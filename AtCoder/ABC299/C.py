n = int(input())
s = input()
def findDango(t: str) -> int:
    ans, left = 0, n
    for i in range(n):
        if t[i] == '-':
            left = i
        ans = max(ans, i - left)
    return ans

def findDango2(t: str) -> int:
    ans, level = 0, 0
    for i in range(n):
        if t[i] == '-':
            ans = max(ans, level)
            level = 0
        else:
            level += 1
    return ans

ans = max(findDango(s), findDango(s[::-1]))
print(ans if ans > 0 else -1)