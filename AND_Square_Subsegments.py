#pow(2, 30) = 1073741824
pre = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
pre_and = []
for i in range(0, 10000):
	pre_and.insert(i, 0)
pre_and.insert(0, pre[0])
for i in range(1, len(pre)):
	pre_and.insert(i, pre_and[i - 1] & pre[i])
	print(pre_and[i], pre[i])
print()