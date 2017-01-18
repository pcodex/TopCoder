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

class PackingParts
{
public:
	int pack(vector <int> partSizes, vector <int> boxSizes);
};

int PackingParts::pack(vector <int> partSizes, vector <int> boxSizes)
{
	int cnt = 0;
	for (int i = 0; i < partSizes.size(); ++i)
	{
		for (int j = 0; j < boxSizes.size(); ++j)
		{
			if (partSizes[i] <= boxSizes[j])
			{
				cnt++;
				boxSizes[j] = 0;
				break;
			}
		}
	}
	return cnt;
}

/*
old submission
#include <vector>
#include <iostream>

using namespace std;

class PackingParts
{
public:
int pack(vector<int> partSizes, vector<int> boxSizes);
};

int PackingParts::pack(vector<int> ptSzes, vector<int> bxSzes)
{
int totalnoOfParts = ptSzes.size();
int totalnoOfBoxes = bxSzes.size();
int noOfPartsPacked = 0;

vector<int>::iterator partsIter = ptSzes.begin();
vector<int>::iterator BoxesIter;

cout<<"\nNo of parts is " << totalnoOfParts;
cout<<"\nNo of boxes is " << totalnoOfBoxes;

while(partsIter != ptSzes.end())
{
int startAtBox = 0;
int stopAtBox = totalnoOfBoxes;
bool boxAvailable = false;
if((BoxesIter =  bxSzes.begin()) == bxSzes.end())
break;

cout<<"\nSize of the first element in the parts array "<<ptSzes[0];
cout<<"\nSize of the middle element in the box array "<<bxSzes[totalnoOfBoxes/2];

if(*partsIter <= bxSzes[totalnoOfBoxes/2])
{
stopAtBox = (totalnoOfBoxes/2);
cout<<"\nStop at box no "<<stopAtBox+1<<" with size "<<bxSzes[stopAtBox];
boxAvailable =  true;
}
else if(*partsIter <= bxSzes[totalnoOfBoxes-1])
{
startAtBox = totalnoOfBoxes/2 + 1;
cout<<"\nStart at box no "<<startAtBox+1<<" with size "<<bxSzes[startAtBox];
boxAvailable =  true;

}

if(boxAvailable)
{
for(int i = startAtBox; i <= stopAtBox; i++)
{
cout<<"\nChecking box "<<i<<" with size "<<bxSzes[i]<<" for part size "<<*partsIter;
if(*partsIter <= bxSzes[i])
{
cout<<"\nUsing box "<<i<<" with size "<<bxSzes[i];
bxSzes.erase(BoxesIter+i);
partsIter = ptSzes.erase(partsIter);
noOfPartsPacked += 1;
totalnoOfBoxes -= 1;
break;
}

}
}
else
break;
}

return noOfPartsPacked;
}
*/

int main()
{
	PackingParts o;
	vector<int> p = { 2, 2, 2 };
	vector<int> b = { 1, 2, 2, 3 };

	int cn = o.pack(p, b);
	return 0;
}