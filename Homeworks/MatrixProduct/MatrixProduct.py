import numpy as np
import time

#Product Function
def matrixProduct(A,B,n,m,k):
    C = np.zeros((n,k),dtype=int)
    for i in range(0,n):
        for j in range(0,k):
            for l in range(0,m):
                C[i][j] = C[i][j]+(A[i][l]*B[l][j])
    return C

#This is the same function but with some changes to measure time taken by operations(+,*).
def matrixProductTimes(A,B,n,m,k):
    C = np.zeros((n,k),dtype=int)
    add,multi = 0,0
    for i in range(0,n):
        for j in range(0,k):
            for l in range(0,m):
                to = time.clock()
                pr = A[i][l]*B[l][j]
                tf = time.clock()
                multi = multi + (tf-to)
                to = time.clock()
                C[i][j] = C[i][j]+pr
                tf = time.clock()
                add = add + (tf-to)
    return C,add,multi


print("Testing function - insert a value n: ")
hmm = (int)(input("> "))
# we define the matrix dimesion nxm for two matrix
n,m,k = hmm,hmm,hmm
#Matrix A,B
A = np.ones((n,m), dtype=np.int) #n*m
B = np.full((m,k), 2) #n*k
to= time.clock()
C = matrixProduct(A,B,n,m,k)
tf= time.clock()

print("A = \n",A)
print("B = \n",B)
print("AB = \n",C)
print ("time elapsed > ",tf-to," seconds.")

print ("---- PYTHON_3 time performance analysis - each 10 steps----")
print("n \t avg(10) \t add_avg(10) \t prod_avg(10)")
for i in range(0,200,10):
    avg,timeAdd,timeProd=0.0,0.0,0.0
    n=m=k=i
    A = np.ones((n,m), dtype=np.int) #n*m
    B = np.full((m,k), 2) #n*k
    for j in range(10):
        t0=time.clock()
        C,ad,pr = matrixProductTimes(A,B,n,m,k)
        tf=time.clock()
        avg += tf-t0
        timeAdd += ad
        timeProd += pr
    avg/=10.0
    timeAdd/=10.0
    timeProd/=10.0
    print(i,'\t',avg,'\t',timeAdd,'\t',timeProd)
