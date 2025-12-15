n, m = map(int, input().split())
s, t = input(), input()
# print(s,t)
pref, suf = t.startswith(s), t.endswith(s)
# print(pref, suf)
if pref and suf:
    print(0)
elif pref:
    print(1)
elif suf:
    print(2)
else:
    print(3)