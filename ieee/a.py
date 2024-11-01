import math as m
def fastpow(a,n):
    ans = 1
    while( n > 0):
        if n%2:
            ans*=a
        a *= a
        n = n//2
    return ans            
    

n = int(input())

# if n == 0 :
#     print(-1)

# else:
#     x = m.log10(n)/m.log10(3)
#     if x.is_integer():
#         print(int(x))
#     else:
#         print(-1)


# l = 0 ; r = 1e6
# ans = -1
# while l <= r:
#     mid = (l+r)//2
#     x = fastpow(3,mid)
#     if x == n:
#         ans = int(mid)
#         break
#     elif x < n:
#         l = mid +1
#     else:
#         r = mid - 1

# print(ans)
a = fastpow(3,5)
print(a)