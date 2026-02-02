from copy import deepcopy

class BigNum:
    def __init__(self, n: int = 32, _m: str = '', e: int = 31) -> None:
        self.n = n
        self.m = [0] * (n)
        self.e = e
        if _m:
            lm = len(_m)
            if lm >= n:
                self.m = list(map(int, list(_m)))[:n]
            else:
                for i in range(- 1, -lm - 1, - 1):
                    self.m[i] = int(_m[i])
            # print(self.m)
        pass
    
    def rshift(self, n: int):
        # back = self.m[-1:-n - 1:-1][::-1]
        self.m = [0] * n + self.m
        self.n += n
        self.e += n
        # return back
    
    def cut(self, x: int) -> list[int]:
        back = self.m[-1:-x - 1: -1][::-1]
        self.n = self.n - x
        self.m = self.m[:self.n]
        return back
    def reserve(self, x: int):
        if self.n > x:
            self.cut(self.n - x)
        else:
            self.extend(x - self.n)
    
    def extend(self, x: int):
        if x > 0:
            self.n += x
            self.m += [0] * x

    def exp(self, x: int) -> 'BigNum':
        res = BigNum(self.n, self.m, self.e + x)
        res.extend(x)
        return res
    
    def sqrt(self, b: int) -> 'BigNum':
        left = BigNum(1, '0', 0)
        right = deepcopy(self)
        while left < right:
            mid = (left + right) * BigNum(2, '05', 0)
            mid.reserve(b)
            # print(mid * mid)
            if mid * mid < self:
                left = mid + BigNum(b, '0' * (b - 1) + '1', 0)
            else:
                right = deepcopy(mid)
            # print(right)
            # print(left)
            # print()
        return right
    
    def inv(self, b: int) -> 'BigNum':
        left = BigNum(1, '0', 0)
        right = deepcopy(self)
        while left < right:
            # print('?')
            mid = (left + right) * BigNum(2, '05', 0)
            mid.reserve(b)
            # print(mid * self)
            if mid * self < BigNum(1, '1', 0):
                left = mid + BigNum(b, '0' * (b - 1) + '1', 0)
            else:
                right = deepcopy(mid)
            # print(right)
        return right

    def normalize(self):
        i = 0
        if self.e < 0:
            self.rshift(-self.e)
            return
        if self.m[i] != 0:
            return
        while i < self.n and self.m[i] == 0 and i < self.e:
            i += 1
        # print(i)
        self.m = self.m[i:]
        self.n -= i
        self.e -= i

    def __add__(self, other: 'BigNum') -> 'BigNum':
        e1, e2 = self.e, other.e
        e = max(e1, e2)
        if e1 < e2:
            self.rshift(e2 - e1)
        elif e1 > e2:
            other.rshift(e1 - e2)
        self.extend(other.n - self.n)
        other.extend(self.n - other.n)
        
        res = [0] * (self.n)
        c = 0
        for i in range(self.n - 1, -1, -1):
            a, b = self.m[i], other.m[i]
            s = (c + a + b) % 10
            c = (c + a + b) // 10
            res[i] = s
        if c == 1:
            res = [c] + res
            e += 1
        ans = BigNum(len(res), tuple(res), e)
        ans.normalize()
        return ans

    def mul_low(self, mul: int) -> 'BigNum':
        res = []
        c = 0
        for i in range(self.n - 1, -1, -1):
            s = (self.m[i] * mul + c) % 10
            c = (self.m[i] * mul + c) // 10
            res.append(s)

        if c > 0:
            res.append(c)
        res = res[::-1]
        # print((res))
        return BigNum(len(res), res, self.e + (c > 0))

    def __mul__(self, other: 'BigNum') -> 'BigNum':
        # self.extend(other.n - self.n)
        # other.extend(self.n - other.n)
        res = BigNum(1, '0', 1 )
        for i in range(self.n - 1, -1, -1):
            mult = other.mul_low(self.m[i]).exp(self.n - 1 - i)
            # print('mul:', mult, mult.e)
            res += mult
            # print('res:', res, res.e)
        res.e = res.n - 1 - ((self.n - 1 - self.e) + (other.n - 1 - other.e))
        res.normalize()
        return res

    def __str__(self) -> str:
        return ''.join(map(str, self.m)) + f' {self.e:02d}'
    
    def __lt__(self, other: 'BigNum') -> bool:
        self.normalize()
        other.normalize()
        if self.e != other.e:
            return self.e < other.e
        else:
            self.reserve(max(self.n, other.n))
            other.reserve(max(self.n, other.n))
            return self.m < other.m
    
    def pow(self, x: int, b: int = 32) -> 'BigNum':
        res = BigNum(1, '1', 0)
        for _ in range(x):
            res *= self
            # print(res)
        res.reserve(b)
        return res
            