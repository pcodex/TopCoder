// srm668.cpp : Defines the entry point for the console application.
//


#include <vector>
#include <string>

using namespace std;

class VerySecureEncryption
{
public:
	string encrypt(string message, vector <int> key, int K);
};

string VerySecureEncryption::encrypt(string message, vector <int> key, int K)
{
	string wrkcpy = message;
	string finalstr = string(wrkcpy.length(), ' ');

	for (int cnt = 0; cnt < K; ++cnt)
	{
		for (int i = 0; i < key.size(); ++i)
		{
			finalstr[key[i]] = wrkcpy[i];
		}
		wrkcpy = finalstr;
	}

	return finalstr;
}

int main()
{
	VerySecureEncryption vse;
	/*
	"abcde"
	{4, 3, 2, 1, 0}
	2
	*/
	/*
	"uogcodlk"
{4, 3, 6, 2, 5, 1, 0, 7}
44*/
	string ss = "uogcodlk";
	vector<int> vs = { 4, 3, 6, 2, 5, 1, 0, 7 };
	int k = 44;

	string finalop = vse.encrypt(ss,vs,k);

	return 0;
}

