'''arr = ['sunday', 'monday', 'tuesday', 'wednesday']

# without using asterisk
print(' '.join(map(str,arr)))

# using asterisk
print (arr)'''
'''def even_odd_patterns(n):
    alt_even = +1
    for i in range(0,n+1):
        if i%2==0:
            i = i + alt_even
            alt_even = alt_even * -1
        print("*"*i)
        
even_odd_patterns(7)
print()
even_odd_patterns(4)'''
