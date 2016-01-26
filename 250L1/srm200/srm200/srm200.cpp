// srm200.cpp : Defines the entry point for the console application.
//

#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <sstream>

using namespace std;

class NoOrderOfOperations
{
public:
	int evaluate(string expr);
};

int NoOrderOfOperations::evaluate(string expr)
{
	
	char oprtr;
	int num1,num2;
	int res=0;

	stringstream ssnum1;

	ssnum1 << expr[0];
	ssnum1 >> res;

	for (int i = 1; i < expr.length(); i+=2)
	{
		stringstream opr, ssnum2;
		opr << expr[i];
		opr >> oprtr;

		ssnum2 << expr[i+1];
		ssnum2 >> num2;
				
		switch (oprtr)
		{
		case '+':
			res += num2;
			break;
		case '-':
			res -= num2;
			break;
		case '*':
			res *= num2;
			break;
		}
		
	}

	return res;
}

int main()
{
	NoOrderOfOperations nop;
	string ssinp = "1*2*3*4*5*6*7*8*9";
	int res = nop.evaluate(ssinp);
	return 0;
}

