#Bronze 1 Solution - December 2020
#Link to Contest - http://www.usaco.org/index.php?page=viewproblem2&cpid=1059
from itertools import permutations
x = list(map(int, input().split()))
for i in permutations(x):
    if (i[0] + i[1] == i[3] and i[0] + i[2] == i[4] and i[1] + i[2] == i[5] and i[0] + i[1] + i[2] == i[6]):
        if (i[0] <= i[1] and i[1] <= i[2]):
            print(str(i[0]) + ' ' + str(i[1]) + ' ' + str(i[2]))
            break
