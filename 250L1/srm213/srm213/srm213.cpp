// srm213.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>

using namespace std;


class Chivalry
{
public:
	string getOrder(string first, string second);
};

string Chivalry::getOrder(string first, string second)
{
	string outln = "";

	while (first.length() > 0 && second.length() > 0)
	{
		if (first[0] == 'M' && second[0] == 'W')
		{
			outln += 'W';
			second.erase(0, 1);
		}
		else 
		{
			outln += first[0];
			first.erase(0, 1);
		}
				
	}

	if (first.length() > 0)
		outln += first;
	else
		outln += second;

	return outln;
}
	


int main()
{
	Chivalry chv;

	string f = "M";
	string s = "WWW";

	string out = chv.getOrder(f, s);

	return 0;
}

