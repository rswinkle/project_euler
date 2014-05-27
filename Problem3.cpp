/*
import sys
import codecs


x = 600851475143

factors = new list
powers = new list

pointer = 0


for i in range(100000000):
	while x % i == 0:
		if powers[pointer]==0:
			factors.append(i)
		
		powers[pointer]+=1
		x /= i
		
		
for i in range(len(factors))
	print(factors[i] + " " + powers[i] +"\n")
*/

#include <iostream>

using namespace std;

int main()
{
	unsigned long long x = 600851475143;

	int factors[100] = {0};
	int powers[100] = {0};
	int pointer = 0;

	for(int i=0;i<100000000;i++)
	{
		while(x%i == 0)
		{
			if(powers[pointer]==0)
				factors[pointer] = i;
			
			++powers[pointer];
			x /= i;
		}
		if(x==1) break;
	}

	for(int i=0;;i++)
	{
		if(factors[i]==0)break;

		cout<<factors[i]<<" "<<powers[i]<<endl;
	}





	return 0;
}




	
