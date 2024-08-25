'''output =False
a=int(input())
if a<=1:
    exit()

b=int(input())
if 1 >= b and b>a:
    exit()
for i in range(0,a):
    if a==b**i:
        output=True
        break
    else:
        output=False
print (output)'''
'''output=True
k=int(input())
a=str(input())
b=""
if 0>k and 26<k:
    print("Invalid Input")
if str.isupper(a) :
    output=True
else:
    print("Invalid Input")
for i in a:
    z=int(ascii(a[i]))
    a=z+k
    b=b+chr(a)
print(b)'''

r,c=map(int,input().split(" "))
for i in range(1,r-1,2):
    print((".|."*i).center(c,'-'))
print("WELCOME".center(c,"-"))
for i in range(r-2,0,-2 ):
    print((".|."*i).center(c,"-"))
    
    

    
    
    

        
    
