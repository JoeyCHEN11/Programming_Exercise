from sortedcontainers import SortedDict
n = int(input())
size_cnt = [tuple(map(int, input().split())) for _ in range(n)]
st_sc = SortedDict(size_cnt, )
# print(st_sc)

for size, cnt in st_sc.items():
    newSize = size * 2
    addCnt = cnt // 2
    combCnt = 2 * addCnt
    
    if addCnt != 0:
        st_sc[size] -= combCnt
        st_sc[newSize] = st_sc.setdefault(newSize, 0) + addCnt

# print(st_sc)
print(sum(st_sc.values()))