#Bronze 3 Solution - December 2020
#Link to Problem - http://www.usaco.org/index.php?page=viewproblem2&cpid=1061

import math
#variables
data = []
dataE = []
dataN = []
answers = []
highestX = 0
highestY = 0
x = 0
intersections = []

def increment(x):
    for i in range(0, len(x)):
        if x[i][0] == 'E' and x[i][6] == False:
            x[i][3] += 1
        elif x[i][0] == 'N' and x[i][6] == False:
            x[i][4] += 1

def validateE():
    for i in range(0, len(dataE)):
        for j in range(0, len(dataN)):
            if (dataE[i][6] == False): #good
                if (dataE[i][1] <= dataN[j][1] and dataE[i][2] >= dataN[j][2]): #good
                    if (dataE[i][3] == dataN[j][3]):
                        if (dataE[i][4] < dataN[j][4]): #wrong
                            dataE[i][6] = True

def validateN():
    for i in range(0, len(dataN)):
        for j in range(0, len(dataE)):
            if (dataN[i][6] == False): #good
                if (dataN[i][2] <= dataE[j][2] and dataN[i][1] >= dataE[j][1]): #good
                    if (dataN[i][4] == dataE[j][4]):
                        if (dataN[i][3] < dataE[j][3]): #wrong
                            dataN[i][6] = True

#input manipulation
n = int(input())
for i in range(0, n):
    inputString = str(input())
    inputString2 = inputString[2:]
    data.append(list(map(str, inputString.split() + inputString2.split())))
    answers.append(0)
    data[i].append(i)
    data[i].append(False)
    for j in range(1, 5):
        data[i][j] = int(data[i][j])
    if data[i][1] > highestX:
        highestX = data[i][1]
    if data[i][2] > highestY:
        highestY = data[i][2]
for i in data:
    if 'E' in i:
        dataE.append(i)
    elif 'N' in i:
        dataN.append(i)

highest = max(highestX, highestY)

for i in range(0, len(dataE)):
    if dataE[i][6] == True:
        answers[dataE[i][5]] = dataE[i][3] - dataE[i][1]
    else:
        answers[dataE[i][5]] = 'Infinity'

for i in range(0, len(dataN)):
    if dataN[i][6] == True:
        answers[dataN[i][5]] = dataN[i][4] - dataN[i][2]
    else:
        answers[dataN[i][5]] = 'Infinity'

for i in answers:
    print(i)
