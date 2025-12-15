n = int(input())
cards = [[i + 1] + list(map(int, input().split())) for i in range(n)]
# cards = [(c[0], int(c[1]), int(c[2])) for c in cards]
# print(cards)

st = []
cards.sort(key = lambda c : c[1])

for idx, a, c in cards:
    # mono increasing stack
    while st and st[-1][1] > c:
        st.pop()
    st.append((idx, c))

st.sort(key = lambda c : c[0])

print(len(st))
for (idx, c) in st:
    print(idx, end=' ')