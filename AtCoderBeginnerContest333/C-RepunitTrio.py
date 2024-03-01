N = int(input())
L = 12
r = [int("1" * (i+1)) for i in range(L)]
for i in range(L):
    for j in range(i+1):
        for k in range(j+1):
            N -= 1
            if N == 0:
                print(r[i] + r[j] + r[k])