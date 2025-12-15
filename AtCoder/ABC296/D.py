N, M = map(int, input().split())

def solve() -> int:
    ans = float('inf')
    for a in range(1, N + 1):
        b = (M + a - 1) // a
        if (b <= N): ans = min(a * b, ans)
        if a > b: break
    return ans
        
ans = solve()
print(ans if ans != float('inf') else -1)
        