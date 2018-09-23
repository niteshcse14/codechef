def extedgcd(a, b):
	if (a == 0):
		return b
	return extedgcd(b % a, a)
t = input('')
MOD = (int)(1e9 + 7)
while(t):
	a, b, n = [int(x) for x in raw_input().split()]
	d = a - b
	ans = 0
	if (d == 0) :
		ans = (pow(a, n, MOD) + pow(b, n, MOD)) % MOD;
	else :
		ans = extedgcd(d, (pow(a, n, d) + pow(b, n, d))) % MOD;
	print ans
	t = t - 1