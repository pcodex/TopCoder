// srm233.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class JustifyText
{
public:
	vector <string> format(vector <string> text);
};


vector <string> JustifyText::format(vector <string> text)
{
	int maxlen = 0;
	vector<string> out;

	for (int i = 0; i < text.size(); ++i)
	{
		if (text[i].length()>maxlen)
			maxlen = text[i].length();
	}

	for (int i = 0; i < text.size(); ++i)
	{
		size_t len = text[i].length();
		int noSpaces = maxlen - len;

		string tmp = string(noSpaces, ' ') + text[i];		
		
		out.push_back(tmp);
	}

	return out;
}


int main()
{

	JustifyText jt;
	vector<string> vo;
	vector<string> tv = { "BOB", "TOMMY", "JIM" };

	vo = jt.format(tv);
	return 0;
}

