<<<<<<< Updated upstream
import operator as op
from functools import reduce
 
def ncr(n, r):
    r = min(r, n-r)
    numer = reduce(op.mul, range(n, n-r, -1), 1)
    denom = reduce(op.mul, range(1, r+1), 1)
    return (numer // denom -n) % 1000000007
 
if __name__ == "__main__":
    n = int(input())
=======
import operator as op
from functools import reduce
 
def ncr(n, r):
    r = min(r, n-r)
    numer = reduce(op.mul, range(n, n-r, -1), 1)
    denom = reduce(op.mul, range(1, r+1), 1)
    return (numer // denom -n) % 1000000007
 
if __name__ == "__main__":
    n = int(input())
>>>>>>> Stashed changes
    print(ncr(2*n,2))