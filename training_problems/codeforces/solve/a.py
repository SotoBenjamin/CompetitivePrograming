for i in range(1,16):
    if(i % 3 == 0): 
        continue
    for j in range (3,18,3):
        print(i ^ j, end= " ")
    print()

