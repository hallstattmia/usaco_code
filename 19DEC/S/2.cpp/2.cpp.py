

if __name__ == '__main__':
    n  = int(input())
    l = []
    x = n

    while (x > 0):
        l.append(x % 10)
        x = x // 10
    s = 0
    print(l)
    for num in l:
       if (num == 1):
           s = s * 10 + 1
       elif (num == 0):
           s = s * 10 + 0
       elif (num == 8):
           s = s * 10 + 8
       elif (num == 6):
           s = s * 10 + 9
       elif (num == 9):
           s = s * 10 + 6
       else:
           print(0)
           exit(0)
    if (s != n):
        print(1)
    else:
        print(0)





