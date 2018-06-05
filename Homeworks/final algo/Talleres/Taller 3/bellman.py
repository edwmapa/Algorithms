# -*- coding: utf-8 -*-
"""
Created on Mon Jun  4 12:18:30 2018

@author: Mahecha
"""

class edge: #edge creation between nodes a,b with weight w
    def __init__(self, a,b,w):
        self.a = a
        self.b = b
        self.w = w
    
    def getVals(self):
        return self.a,self.b,self.w
        
def bellman(n_vertex,edges,s):#s is the source
    d = [10000000]*n_vertex
    parent = [-1]*n_vertex
    
    d[s] = 0 #source distance
    
    for i in range(n_vertex-1):
        for e in edges:
            a,b,w = e.getVals()
            if(d[a] + w < d[b]):
                d[b] = d[a]+w
                parent[b] = a
        print(d)
    
    for e in edges:
        a,b,w = e.getVals()
        if(d[a]+w<d[b]):
            print("[Graph with negative cycle, dist > ",d,parent,"]")
    
    print ("[",d,parent,"]")


graph = [edge(0,2,3),
          edge(0,1,9),
          edge(1,3,1),
          edge(2,1,2),
          edge(2,3,6),
          edge(2,4,6),
          edge(3,2,4),
          edge(3,4,2)]

print("Graph A")
bellman(5,graph,0)

graph = [edge(0,2,3),
          edge(0,1,9),
          edge(1,3,1),
          edge(2,1,2),
          edge(2,3,6),
          edge(2,4,6),
          edge(3,2,-4),
          edge(3,4,2)]

print("Graph B")
bellman(5,graph,0)

graph = [edge(0,2,8),
          edge(0,1,2),
          edge(1,3,3),
          edge(2,1,2),
          edge(2,3,6),
          edge(2,4,6),
          edge(3,2,-4),
          edge(3,4,2)]

print("Graph C")
bellman(5,graph,0)
