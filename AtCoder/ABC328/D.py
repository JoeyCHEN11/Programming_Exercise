s = input()
st = []

for c in s:
    st.append(c)
    if len(st) >= 3 and ''.join(st[-3:]) == 'ABC':
        for i in range(3): st.pop()
    
print(''.join(st))
        
