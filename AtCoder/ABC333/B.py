e1, e2 = [input() for _ in range(2)]

NEIGHBOUR = 0
OPPOSITE = 1
def getType(edge: str) -> int:
    p1, p2 = ord(edge[0]), ord(edge[1])
    return NEIGHBOUR if abs(p1 - p2) % 3 == 1 else OPPOSITE

print('Yes' if getType(e1) == getType(e2) else 'No')