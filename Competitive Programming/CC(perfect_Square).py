import math
t = int(input())
def square(n):
    sqr=math.sqrt(n)
    return (sqr-math.floor(sqr)==0)
        
while(t!=0):
    n=int(input())
    print(square(n))
    t = t-1
