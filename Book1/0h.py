"""  0h 
길이가 n인 정수 배열 a[]와 위치 p가 주어진다. 
이때 0<=i<=p<=j<n 
이면서 a[i] + a[i+1] + ... + a[j]를 최대로 하는 i, j를 구하는 프로그램을 작성하라. 
즉, 어떤 위치를 포함하는 배열의 부분 중에서 합이 가장 큰 것을 고르는 프로그램이다.
"""

import time

a = [-131312331, 1313, 2, 3, 4]
print (a)
p = 1
n = len(a)

startTime = time.time()

biggist = 0
bigI = 0
bigJ = 0
for i in range(0, p+1):
	for j in range(p, n):
		total = sum(a[i:j +1])
		if biggist < total:
			bigI = i
			bigJ = j
			biggist = total
			
print('i(%d), p(%d), j(%d), total.. %d' % (bigI, p, bigJ, biggist))

print((time.time() - startTime) * 1000, 'ms')
