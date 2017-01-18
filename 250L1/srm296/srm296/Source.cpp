#include <string>
#include <sstream>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cctype>
#include <math.h>
#include <set>
#include <functional>

using namespace std;

class EratosthenSieve2
{
public:
	int nthElement(int n);
};

int EratosthenSieve2::nthElement(int n)
{
	vector<int> seq;
	int cnt = 0;
	for (int i = 1; i <= 1000; ++i)
	{		
		seq.push_back(i);
	}

	for (int i = 2; i < 11; ++i)
	{
		for (int j = i-1; j < seq.size(); j+=i)
		{			
			seq[j]=0;
		}

		vector<int> cpy;
		for (int i = 0; i < seq.size(); ++i)
		{
			if (seq[i] != 0)
				cpy.push_back(seq[i]);
		}
		seq = cpy;
	}

	
	int nthelem = seq[n - 1];
	return nthelem;

}

int main()
{
	EratosthenSieve2 e;

	int elem = e.nthElement(25);
	return 0;
}