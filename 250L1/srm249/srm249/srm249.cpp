// srm249.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <numeric>
#include <math.h>
#include <cctype>

using namespace std;

class ChatTranscript
{
public:
	int howMany(vector <string> transcript, string name);
};


int ChatTranscript::howMany(vector <string> transcript, string name)
{
	int spkcnt = 0;
	string tofnd = name + ":";
	for (int i = 0; i < transcript.size(); ++i)
	{
		if (transcript[i].find(tofnd) == 0)
			spkcnt++;		
	}

	return spkcnt;
}


	int main()
{

	ChatTranscript ct;
	vector<string> t = { "A:A:A:A:A:A:A:A:A" };
	string n = "A";
	int cnt = ct.howMany(t, n);
	return 0;
}

