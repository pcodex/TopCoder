// srm400.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>

using namespace std;

class GrabbingTaxi
{
public:
	int minTime(vector <int> tXs, vector <int> tYs, int gX, int gY, int walkTime, int taxiTime);
};

int GrabbingTaxi::minTime(vector <int> tXs, vector <int> tYs, int gX, int gY, int walkTime, int taxiTime)
{
	int ifYouWalk2OffT = abs(gX)*walkTime + abs(gY)*walkTime;

	vector<int> tx2OffTimes;

	for (int i = 0; i < tXs.size(); ++i)
	{
		int x1 = tXs[i];
		int x2 = gX;
		int diffx = abs(x1 - x2);

		int y1 = tYs[i];
		int y2 = gY;
		int diffy = abs(y1 - y2);

		tx2OffTimes.push_back( (diffx*taxiTime) + (diffy * taxiTime) );
	}
	

	vector<int> txWalkTimes;
	for (int i = 0; i < tXs.size(); ++i)
	{
		int x1 = tXs[i];
		
		int diffx = abs(x1 - 0);

		int y1 = tYs[i];
		
		int diffy = abs(y1 - 0);

		txWalkTimes.push_back((diffx*walkTime) + (diffy * walkTime));
	}
	
	int timeusingTaxi = txWalkTimes[0] + tx2OffTimes[0];
	//-------------
	if (tXs.size() > 0)
	{		
		for (int i = 0; i < txWalkTimes.size(); ++i)
		{
			int tmp = txWalkTimes[i] + tx2OffTimes[i];
			if (timeusingTaxi > tmp)
				timeusingTaxi = tmp;
		}		
	}

	int themin = ifYouWalk2OffT;

	if (tXs.size() > 0)
	{

		if (timeusingTaxi < themin)
			themin = timeusingTaxi;		
	}

	return themin;
}

int main()
{
	GrabbingTaxi gtx;

	//2476
	//{{34, -12, 1, 0, 21, -43, -98, 11, 86, -31}, {11, 5, -68, 69, -78, -49, -36, -2, 1, 70}, -97, -39, 47, 13}


	vector<int> txs = { 34, -12, 1, 0, 21, -43, -98, 11, 86, -31 };
	vector<int> tys = { 11, 5, -68, 69, -78, -49, -36, -2, 1, 70 };
	int gx = -97;
	int gy = -39;
	int wkTime = 47;
	int txTime = 13;

	int tottme = gtx.minTime(txs,tys,gx,gy,wkTime,txTime);

	return 0;
}