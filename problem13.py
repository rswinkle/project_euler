

def main():
	numbers = [];
	for line in open("problem13_input", "r").readlines():
		numbers += [int(line)];

	mysum = sum(numbers);
	print(mysum);

	print(len(str(mysum)));




if __name__ == "__main__":
	main()
