import math
t = int(input(""))


 
def square(n):
    c,m=0,0
    for i in n:
        if i<0:
            c+=1
        else:
            
            if int(i*0.5) * 2 == i:
                m+=1
                continue
            else:
                c+=1
    if c>0:
        print("No")
    elif m>0:
        print("Yes")
        
while(t!=0):
    m=int(input())
    n = score=list(map(int,input("").split()))
    
    square(n)
    
    t = t-1