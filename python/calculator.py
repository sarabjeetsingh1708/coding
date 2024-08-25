op=input("")
N_in=int(input(''))
l=[]
if 1<=N_in<=5:
    for i in range(N_in):
        no=int(input(""))
        l.append(no)
else:
    print("-1")
def add(l):
    sum=0
    if len(l) >1:
        for j in l:
            sum+=j
        print(sum)
    else:
        print("-1")
def subt(l):
    r_t=l[0]
    if len(l) >1:
        for k in l[1:]:
            r_t-=k
        print(r_t)
    else:
        print("-1")
def multi(l):
    r_t=1
    if len(l) >1:
        for t in l:
            r_t=r_t*t
        print(r_t)
    else:
        print("-1")
def div(l):
    r_t=l[0]
    if len(l) >1:
        for y in l[1:]:
            if y!=0:
                r_t=r_t/y
                   
            else:
                r_t=-1
        return r_t
    else:
        print("-1")
if op =='addition' or op== 'Addition':
    add(l)
elif op =='subtraction' or op== 'Subtraction':
    subt(l)
elif op =='multiplication' or op== 'Multiplication':
    multi(l)
elif op =='division' or op== 'Division':
    a=div(l)
    print(a)
else:
    print("-1")