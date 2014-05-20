import time

def main():
	start = time.time()
	a = list(str(2**1000))
	s = sum([int(i) for i in a])
	elapsed = time.time() - start
	print(s, "found in", elapsed, "seconds")




if __name__ == "__main__":
	main();
