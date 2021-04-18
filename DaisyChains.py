#Bronze 2 Solution - December 2020
#Link to Problem - http://www.usaco.org/index.php?page=viewproblem2&cpid=1060
n = int(input())
x = list(map(int, input().split()))
ans = 0
for i in range(0, len(x)):
    for j in range(i + 1, len(x) + 1):
        if(sum(x[i : j]) % len(x[i : j]) == 0):
            if (sum(x[i : j]) / len(x[i : j])) in x[i : j]:
                ans += 1
print(ans)
