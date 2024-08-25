for i in range(7):
    for j in range(7):
        if i+j==3 or j-i==3 or i-j==3 or i+j==9:
            print("*",end=" ")
        else:
            print(end=" ")
    print()
            