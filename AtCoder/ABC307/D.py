n = int(input())
s = input()

st, lcnt = [], 0
for c in s:
    st.append(c)
    if c == '(':
        lcnt += 1 
    elif c == ')' and lcnt > 0:
        while st[-1] != '(':
            st.pop()
        st.pop()
        lcnt -= 1
        
print(''.join(st))