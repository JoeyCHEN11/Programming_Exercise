s = input()
area_sum = 0
down_slopes, pools = [], []

for i, c in enumerate(s):
    if c == '\\':
        down_slopes.append(i)
    elif c == '/' and down_slopes:
        j = down_slopes.pop()
        new_poll = i - j
        area_sum += new_poll
        while pools and pools[-1][0] > j:
            new_poll += pools.pop()[1]
        pools.append((j, new_poll))

print(area_sum)
print(len(pools), *[x for _, x in pools])