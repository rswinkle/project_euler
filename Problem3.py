import sys
import codecs


x = 600851475143

factors = []
powers = [0, 0]
#first I tried "factors = new list (and list())

pointer = 1


for i in range(2,100000000):
	powers.append(0)
	pointer += 1
	while x % i == 0:
		if powers[pointer]==0:
			factors.append(i)
	
		powers[pointer]+=1
		x /= i
		
		
for i in range(len(factors)):
	print(factors[i], " ", powers[factors[i]], "\n")
