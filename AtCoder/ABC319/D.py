n, m = map(int, input().split())
words = list(map(int, input().split()))

def fillLine(width: int) -> int:
    line_cnt, w = 1, 0
    for l in words:
        # if l > width: return float('inf')
        if w + l > width:
            line_cnt += 1
            w = 0
        w += l + 1  
    return line_cnt

right = sum(words) + n
left = max(words)
while left < right:
    mid = (left + right) // 2
    if fillLine(mid) > m:
        left = mid + 1
    else:
        right = mid
print(right)