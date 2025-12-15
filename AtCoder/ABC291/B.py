N = int(input())
nums = list(map(int, input().split()))

print(f'{sum(sorted(nums)[N:4*N]) / (3 * N):.6f}')