// srm692.cpp : Defines the entry point for the console application.
//

#include <string>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

class PriorityQueue
{
public:
	int findAnnoyance(string S, vector<int> a);
};


int PriorityQueue::findAnnoyance(string S, vector<int> a)
{
	int dsum = 0;

	for (int i = 0; i < S.length(); ++i)
	{
		if (S[i] == 'b')
		{
			for (int j = 0; j < i; ++j)
				dsum += a[j];
		}
	}

	return dsum;
}


int main()
{
	PriorityQueue pq;
	string rst = "bbeebeebeeeebbb";
	vector<int> a = { 58, 517, 301, 524, 79, 375, 641, 152, 810, 778, 222, 342, 911, 313, 336 };

	int sum = pq.findAnnoyance(rst, a);

	return 0;
}

