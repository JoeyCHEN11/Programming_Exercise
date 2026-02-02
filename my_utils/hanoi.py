class Tower:
    def __init__(self, name: str, plates: list[int] = []) -> None:
        self.name = name
        self.plates = plates.copy()
        pass
    
    def move_to(self, target: 'Tower') -> None:
        target.plates.append(self.plates.pop())
        print(f'{self.name} -> {target.name}')
    def print_info(self):
        print(f'{self.name}:', self.plates)


# move plates of tower with h height in A to C, with the help of B
def solve(A: Tower, B: Tower, C: Tower, h: int) -> None:
    if h == 1:
        A.move_to(C)
        # return
    else:
        solve(A, C, B, h - 1)
        A.move_to(C)
        solve(B, A, C, h - 1)
    # for t in sorted([A, B, C], key= lambda x: x.name):
    #     t.print_info()
    

if __name__ == '__main__':
    n = int(input())
    A = Tower('A', list(map(int, input().split())))
    B, C = Tower('B'), Tower('C')
    solve(A, B, C, n)
    A.print_info()
    B.print_info()
    C.print_info()
    