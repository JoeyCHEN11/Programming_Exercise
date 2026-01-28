import operator
expr = input().split()
st = []
ops = {'+': operator.add,
       '-': operator.sub,
       '*': operator.mul
       }

for c in expr:
    if c in ops:
        b, a = int(st.pop()), int(st.pop())
        st.append(ops[c](a, b))
    else:
        st.append(int(c))
        
print(st[0])
