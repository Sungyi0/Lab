#is not stable sort
#is in-place sort
#O(n2)

data = [30, 50, 7, 40, 88, 15, 44, 55, 22, 33, 77, 99, 11, 6, 1, 85]

print (data)

for i in range(0, len(data)):
    if not data:
        break

    minD = data[i]
    for n in data[i:len(data)]:
        if n < minD:
            minD = n

    data[data.index(minD)] = data[i]
    data[i] = minD

print data
