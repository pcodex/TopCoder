// srm665.cpp : Defines the entry point for the console application.
//

//#include <vector>

//using namespace std;

class LuckyXor
{
public:
	int construct(int a);
};

int LuckyXor::construct(int a)
{
	int res = -1;
	int b = a + 1;

	for (b; b <= 100; ++b)
	{
		int z = a^b;
		if ((z == 4) ||
			(z == 44) ||
			(z == 47) ||
			(z == 7) ||
			(z == 74) ||
			(z == 77))
		{
			res = b;
			break;
		}
	}

	return res;
}


int main()
{
	LuckyXor lkx;

	int res = lkx.construct(4);
	
	return 0;
}

