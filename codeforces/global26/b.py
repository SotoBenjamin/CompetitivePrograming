t = int(input())
for i in range(t):
    x = list(input())
    if x[0] == '1' and x[len(x) - 1] != '9':
        flag = False
        for i in range(1,len(x) - 1):
            if x[i] == '0':
                print("NO")
                flag = True
                break
        if not flag:
            print("YES")        
    else :
        print("NO")
    