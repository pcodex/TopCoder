// srm221.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class EqualSubstrings
{
public:
	vector <string> getSubstrings(string str);
};

vector <string> EqualSubstrings::getSubstrings(string str)
{

	int ca = count(str.begin(), str.end(), 'a');
	int cb = count(str.begin(), str.end(), 'b');

	if (ca == 0 || cb == 0)
	{
		size_t pos = 0;
		vector<string> vout;

		string p1 = string(str, 0, pos);
		string p2 = string(str, pos);

		ca = count(p1.begin(), p1.end(), 'a');
		cb = count(p2.begin(), p2.end(), 'b');		

		string olp1 = p1;
		string olp2 = p2;
		
		while ((ca <= cb) && (pos<=str.length()))
		{
			pos += 1;			
			
			olp1 = p1;
			olp2 = p2;

			if (pos <= str.length())
			{
				p1 = string(str, 0, pos);
				p2 = string(str, pos);
			}

			ca = count(p1.begin(), p1.end(), 'a');
			cb = count(p2.begin(), p2.end(), 'b');
		}

		vout = { olp1, olp2 };

		return vout;

	}

	size_t pos = 0;
	vector<string> vout;
			
	string p1 = string(str, 0, pos);
	string p2 = string(str, pos);

	ca = count(p1.begin(), p1.end(), 'a');
	cb = count(p2.begin(), p2.end(), 'b');

	string olp1 = p1;
	string olp2 = p2;

	while (ca<=cb)
	{
		pos += 1;
		olp1 = p1;
		olp2 = p2;
		p1 = string(str, 0, pos);
		p2 = string(str, pos);

		ca = count(p1.begin(), p1.end(), 'a');
		cb = count(p2.begin(), p2.end(), 'b');		
	}

	vout = { olp1, olp2 };

	return vout;
}


int main()
{
	EqualSubstrings eg;

	string st = "aaabbb";
	vector<string> vs = eg.getSubstrings(st);

	return 0;
}

