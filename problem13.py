import sys

def main():
	numbers = [];
	if len(sys.argv) != 2:
		print("usage: python3", sys.argv[0], "[textfile of numbers separated by newlines]")
		sys.exit()
	
	for line in open(sys.argv[1], "r").readlines():
		numbers += [int(line)];

	mysum = sum(numbers);
	print(mysum);

	print(len(str(mysum)));




if __name__ == "__main__":
	main()
