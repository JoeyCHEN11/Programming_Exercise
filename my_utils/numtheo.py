
def sieve_eratos(n) -> list[bool]:
    n = int(n)
    isPrime = [True] * (n + 1)
    isPrime[0] = isPrime[1] = False
    for f in range(2, int(n**0.5) + 1):
        if isPrime[f]:
            for j in range(f + f, n + 1, f):
                isPrime[j] = False
    return isPrime

if __name__ == '__main__':
    P = sieve_eratos(1e5)
    # print(list(enumerate(P)))