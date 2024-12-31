[n,c1,c2] = input().split()
s = list(input())
n = int(n)
for i in range(n):
    if s[i] != c1 :
        s[i] = c2

for i in range(n):
    print(s[i], end="")

print()