#Silver 1 Solutions - Jan 2021
#Link to Problem - http://www.usaco.org/index.php?page=viewproblem2&cpid=1086

from sys import stdin, stdout
z = 5
arr = []
N, K = stdin.readline().split()
N = int(N)
K = int(K)
for i in range(0, K):
    A, B = stdin.readline().split()
    A = int(A)
    B = int(B)
    arr.append([A - 1, B - 1])

p = []
permutations = []

for i in range(0, N):
    p.append([i])
    permutations.append(i)

for i in range(0, len(arr)):
    lp = arr[i][0]
    rp = arr[i][1]
    lv = permutations[lp]
    rv = permutations[rp]
    p[lv].append(rp)
    p[rv].append(lp)
    temp = permutations[lp]
    permutations[lp] = permutations[rp]
    permutations[rp] = temp

rev = []
accessed = [0] * N

for i in range(0, N):
    if accessed[i] == 0:
        accessed[i] = 1
        rev.append([])
        rev[len(rev) - 1].append(i)
        t = p[i][len(p[i]) - 1]
        while (accessed[t] == 0):
            rev[len(rev) - 1].append(t)
            accessed[t] = 1
            t = p[t][len(p[t]) - 1]

answer_array = [0] * N

for i in range(0, len(rev)):
    z += 1
    count = 0
    for j in range(0, len(rev[i])):
        for k in range(0, len(p[rev[i][j]])):
            q = p[rev[i][j]][k]
            if (accessed[q] != z):
                count += 1
            accessed[q] = z
    for l in range(0, len(rev[i])):
        answer_array[rev[i][l]] = count

for i in answer_array:
    stdout.write(str(i) + '\n')
