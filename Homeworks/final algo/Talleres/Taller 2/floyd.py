# -*- coding: utf-8 -*-
"""
Created on Mon Jun  4 12:18:30 2018

@author: Mahecha
"""
import numpy as np

INF = 1000000000

d = np.array([[INF]*11]*11)

d[1][2] = 40
d[1][3] = 8
d[1][4] = 10
d[2][7] = 10
d[2][5] = 6
d[3][2] = 7
d[3][6] = 2
d[3][4] = 12
d[4][6] = 1
d[5][3] = 2
d[5][6] = 2
d[5][7] = 4
d[6][8] = 4
d[6][9] = 3
d[7][8] = 20
d[7][10] = 1
d[8][5] = 0
d[8][10] = 20
d[9][4] = 6
d[9][8] = 10
d[9][10] = 2

def shows():
    for i in range (1,11):
        for j in range (1,11):
            if(d[i][j]==INF):print("I",end = ", ")
            else:print(d[i][j],end = ", ")
        print()
    print()


for k in range (1,11):
    for i in range (1,11):
        for j in range (1,11):
            d[i][j] = min(d[i][j] , d[i][k]+ d[k][j])
            #shows()
shows()        