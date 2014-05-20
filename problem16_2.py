import time
 
def pow2sum(exp):
	L = [0] * exp # make a list exp long
	L[0] = 1
	for power in range(exp):
		carry, add = 0, 0
		for index in range(exp):
			prod = L[index] * 2 + carry
			if prod > 9:
				carry = 1
				prod = prod % 10
			else: carry = 0
			L[index] = prod
		for i in range(exp):
			print(L[i])
		print("===\n", power, "\n===");

	return sum(L)
 
start = time.time()
n = pow2sum(20)
elapsed = (time.time() - start)
print(n, "found in", elapsed, "seconds")
