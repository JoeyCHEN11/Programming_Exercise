sx, sy = map(int, input().split())
tx, ty = map(int, input().split())
ans = 0

# s -> right, t -> left
if sx < tx:
    if (sx + sy) % 2 == 0:
        sx += 1
    if (tx + ty) % 2 == 1:
        tx -= 1
    hori = tx - sx
else:
    if (sx + sy) % 2 == 1:
        sx -= 1
    if (tx + ty) % 2 == 0:
        tx += 1
    hori = sx - tx
        
vert = abs(sy - ty)
ans += vert + (max(hori - vert, 0) + 1) // 2
print(ans)
        