# # l=[1,2,1,1,2,4,6,4,1,7]
# # dict={}
# # for i in (l):
# #     if i in dict:
# #         dict[i] +=1
# #     else:
# #         dict[i]=1
# # print(dict)
# l=[1,2,1,1,2,4,6,4,1,7]
# # s=set(l)
# # d={}
# # for i in s:
# #     d[i]=l.count(i)
# # print(d)
# d=dict.fromkeys(l,0)
# for i in l:
#     d[i]+=1
# print(d)
for i in range(10):
    print("hello")
    for j in range(i):
        print("world")