// srm662.cpp : Defines the entry point for the console application.
//

#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <sstream>

using namespace std;


class Hexspeak
{
public:
	string decode(long long ciphertext);
};

string Hexspeak::decode(long long ciphertext)
{
	vector<long> vin;
	while (ciphertext != 0)
	{
		long long rem = ciphertext % 16;
		vin.push_back(rem);
		ciphertext /= 16;
	}

	string hexcode = "";
	size_t sz = vin.size();
	for (int i = sz-1; i >= 0; --i)
	{
		switch (vin[i])
		{
		case 1:
			hexcode += "I";
				break;
		case 0:
			hexcode += "O";
			break;
		case 10:
			hexcode += "A";
			break;
		case 11:
			hexcode += "B";
			break;
		case 12:
			hexcode += "C";
			break;
		case 13:
			hexcode += "D";
			break;
		case 14:
			hexcode += "E";
			break;
		case 15:
			hexcode += "F";
			break;
		default:
			hexcode = "Error!";
				break;
		}
		if (hexcode == "Error!")
			break;
	}

	return hexcode;
}

int main()
{
	Hexspeak hsx;

	string op = hsx.decode(1000000000000000000);

	return 0;
}

