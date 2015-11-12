// srm658.cpp : Defines the entry point for the console application.
//

#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <sstream>
#include <fstream>

using namespace std;

const string NEQ = "Not equal";
const string EQ = "Equal";

class InfiniteString
{
public:
	string equal(string s, string t);
};

string InfiniteString::equal(string s, string t)
{
	bool iseq = false;

	if (s == t)
		iseq = true;

	if (s.length() != t.length())
	{
		size_t slen = s.length();
		size_t tlen = t.length();

		if (slen < tlen)
		{
			while (s.length() < t.length())
				s += s;
		}

		if (tlen < slen)
		{
			while (t.length() < s.length())
				t += t;
		}

		s += s;
		t += t;

		size_t pos = std::string::npos;

		if (s.length() < t.length())
			pos = t.find(s);
		else
			pos = s.find(t);

		if (pos == 0)
			iseq = true;
	}

	if (iseq)
		return EQ;
	else
		return NEQ;
	
}

int main()
{
	ofstream of("results.txt", ios::ate);	
	vector<string> s1 = { "ab", "abc", "abab", "aaaaa", "ababab", "a", "ababa" , "ababba"};
	vector<string> s2 = { "abab", "bca", "aba", "aaaaaa", "abab", "z", "ababaa", "abab" };
	
	InfiniteString is;
	for (int i = 0; i < s1.size(); ++i)
	{
		string op = is.equal(s1[i], s2[i]);
		of << "\"" << s1[i]<<"\"" << endl;
		of << "\"" << s2[i]<<"\""<< endl;
		of << op << endl<<endl;
	}

	return 0;
}

