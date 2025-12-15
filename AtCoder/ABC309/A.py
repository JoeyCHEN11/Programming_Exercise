a, b = map(int, input().split())
ai, aj = (a - 1) // 3, (a - 1) % 3
bi, bj = (b - 1) // 3, (b - 1) % 3
print('Yes' if abs(ai - bi) == 0 and abs(aj - bj) == 1 else 'No')