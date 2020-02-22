#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Jan 16 12:41:28 2020

@author: mama33
"""

         
def check(a,b):
    sum_mouse = 0
    for i in range(0, len(x)):
        if (abs(x[i] -a ) <= d) and (abs(y[i] - b) <= d):
            sum_mouse = sum_mouse + s[i]
        else:
            pass
    return sum_mouse
        

def ca():
    d = {}
    for i in range(min(x),max(x)):
        for j in range(min(y),max(y)):
            _sum = check(i,j)
            d[_sum] = (i,j)
    kq = max(d.keys())
    td = d[kq]
    x0 = td[0]
    y0 = td[0]
    return [x0,y0,kq]

if __name__ == "__main__":
    d = int(input())
    n = int(input())
    d = 1
# =============================================================================
#     x = [4,6]
#     y = [4,6]
#     s = [10,20]
# =============================================================================
    x = []
    y = []
    s= []
    for i in range(0,n):
        data = input().split()
        x.append(int(data[0]))
        y.append(int(data[1]))
        s.append(int(data[2]))
    kq = ca()
    print(kq[0]," ", kq[1], "", kq[2])
    
        
    
    