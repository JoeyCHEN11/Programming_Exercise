n, m = map(int, input().split())
candies = list(map(int, input().split()))
persons = list(map(int, input().split()))


def buyCandy() -> int:
    stCandies, stPersons = sorted(candies), sorted(persons) 
    ans, i, j = 0, 0, 0
    
    while i < n and j < m:
        if stCandies[i] >= stPersons[j]:
            ans += stCandies[i]
            j += 1
        i += 1
        
    return ans if j == m else -1

print(buyCandy())
    
    
        
    