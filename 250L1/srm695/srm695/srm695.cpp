// srm695.cpp : Defines the entry point for the console application.
//

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <functional>
#include <numeric>
#include <math.h>
#include <ctime>
#include <Windows.h>


using namespace std;

typedef long long int64; typedef unsigned long long uint64;

uint64 GetTimeMs64()
{
	/* Windows */
	FILETIME ft;
	LARGE_INTEGER li;

	/* Get the amount of 100 nano seconds intervals elapsed since January 1, 1601 (UTC) and copy it
	* to a LARGE_INTEGER structure. */
	GetSystemTimeAsFileTime(&ft);
	li.LowPart = ft.dwLowDateTime;
	li.HighPart = ft.dwHighDateTime;

	uint64 ret = li.QuadPart;
	ret -= 116444736000000000LL; /* Convert from file time to UNIX epoch time. */
	ret /= 10000; /* From 100 nano seconds (10^-7) to 1 millisecond (10^-3) intervals */

	return ret;
}


class BearNSWE
{

public:
	double totalDistance(vector <int> a, string dir);
};

double BearNSWE::totalDistance(vector <int> a, string dir)
{
	
	uint64 start = GetTimeMs64();

	int hor = 0;
	int vert = 0;

	for (size_t i = 0; i < dir.length(); ++i)
	{
		switch (dir[i])
		{
		case 'E':
			hor += a[i];
			break;
		case 'W':
			hor -= a[i];
			break;
		case 'N':
			vert += a[i];
			break;
		case 'S':
			vert -= a[i];
			break;
		default :
			break;
		}
	}

	double totroute = sqrt(hor*hor + vert*vert) + accumulate(a.begin(), a.end(), 0);

	Sleep(300);
	uint64 end = GetTimeMs64();
	
	cout << "time: " << (end - start)<< endl;

	return totroute;

}


int main()
{
	BearNSWE bsw;
	vector<int> vec = { 10, 10, 10, 15, 8, 20, 5 };
	string d = "NEWEWWE";	 
	double finaldist = bsw.totalDistance(vec, d);
	return 0;
}

