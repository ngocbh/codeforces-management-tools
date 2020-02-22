<<<<<<< Updated upstream
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Jan 16 13:43:35 2020

@author: mama33
"""

import operator as op
from functools import reduce

def ncr(n, r):
    r = min(r, n-r)
    numer = reduce(op.mul, range(n, n-r, -1), 1)
    denom = reduce(op.mul, range(1, r+1), 1)
    return (numer // denom ) % 1000000007

if __name__ == "__main__":
    n = int(input())
    n_e = 4 + 3*(n-2)
    print(ncr(n_e, n-1) -4*(n-2))
=======
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Jan 16 13:43:35 2020

@author: mama33
"""

import operator as op
from functools import reduce

def ncr(n, r):
    r = min(r, n-r)
    numer = reduce(op.mul, range(n, n-r, -1), 1)
    denom = reduce(op.mul, range(1, r+1), 1)
    return (numer // denom ) % 1000000007

if __name__ == "__main__":
    n = int(input())
    n_e = 4 + 3*(n-2)
    print(ncr(n_e, n-1) -4*(n-2))
>>>>>>> Stashed changes
    #print(ncr(7,2))