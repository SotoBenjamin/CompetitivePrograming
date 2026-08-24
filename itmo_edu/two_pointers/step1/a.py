def f(n):
    ac = 1
    for i in range(n+1):
        ac *= (365 - i +1)/(365)
    return 1 - ac

print(f(60))
