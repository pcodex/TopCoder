// srm654.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class SquareScoresDiv2
{
public:
	int getscore(string s);
};

int SquareScoresDiv2::getscore(string s)
{
	size_t scr = 0;

	for (size_t i = 0; i <= s.length(); ++i)
	{
		if (i != 0){
			i -= 1;
		}

		size_t apos = s.find_first_not_of(s[i], i);

		//aaaba
		int maxlen = 0;
		if (apos != std::string::npos)
		{
			maxlen = apos - i;


			string s2 = s.substr(i, maxlen);

			while (maxlen > 0)
			{
				for (int j = 0; j + maxlen <= s2.length(); ++j)
				{
					string tmp = s2.substr(j, maxlen);

					if (tmp.length() == maxlen)
						scr++;
				}

				maxlen--;
			}
			i = apos;
		}
		else if (apos == std::string::npos)
		{
			maxlen = s.length();


			string s2 = s.substr(i, maxlen);

			while (maxlen > 0)
			{
				for (int j = 0; j + maxlen <= s2.length(); ++j)
				{
					string tmp = s2.substr(j, maxlen);

					if (tmp.length() == maxlen)
						scr++;
				}

				maxlen--;
			}
			break;
		}
		
	}

	return scr;
}

int main()
{
	SquareScoresDiv2 sdl;

	string ss = "zzzxxzz";

	int scor = sdl.getscore(ss);
	return 0;
}

