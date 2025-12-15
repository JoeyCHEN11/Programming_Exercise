s = input()

upCnt = 0
for c in s:
    upCnt += c.isupper()
    
print(s.upper() if upCnt > len(s) - upCnt else s.lower())