n, p, q = list(map(int, input().split()))
dishes = list(map(int, input().split()))
print(min(p, q + min(dishes)))