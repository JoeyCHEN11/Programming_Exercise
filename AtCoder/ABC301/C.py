from collections import Counter
s = input()
t = input()
atcoder = {'a', 't', 'c', 'o', 'd', 'e', 'r', '@'}
s_check = Counter(s)

def win() -> bool:
    t_wild = 0
    for c in t:
        if c != '@':
            if s_check[c] > 0:
                s_check[c] -= 1
            elif c in atcoder and s_check['@'] > 0:
                s_check['@'] -= 1
            else:
                return False
        else:
            t_wild += 1

    left = 0
    for c, cnt in s_check.items():
        if cnt > 0 and c not in atcoder:
            return False
        else:
            left += cnt
    # print(left)
    return t_wild == left

print('Yes' if win() else 'No')
