// srm689.cpp : Defines the entry point for the console application.
//

#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <iostream>
#include <math.h>
#include <cctype>
#include <functional>
#include <vector>
#include <queue>

using namespace std;

class SimilarUserDetection
{
public:
	string haveSimilar(vector <string> handles);
};


string SimilarUserDetection::haveSimilar(vector <string> handles)
{
	string found = "Similar handles found";
	string nfound = "Similar handles not found";
	set<char> set0 = { 'O', '0' };
	set<char> set1 = { '1', 'l', 'I' };

	for (int i = 0; i < handles.size(); ++i)
	{
		for (int j = i + 1; j < handles.size(); ++j)
		{
			int len1 = handles[i].length();
			int len2 = handles[j].length();

			if (len1 == len2)
			{
				string s1 = handles[i];
				string s2 = handles[j];
				bool simi = true;
				for (int k = 0; k < len1; ++k)
				{
					if (s1[k] != s2[k])
					{
						if ((set0.find(s1[k]) != set0.end() && set0.find(s2[k]) != set0.end())
							||
							(set1.find(s1[k]) != set1.end() && set1.find(s2[k]) != set1.end()))
							simi = true;
						else{
							simi = false;
							break;
						}
					}
				}
				if (simi)
					return found;
			}
		}
	}

	return nfound;
}


int main()
{
	SimilarUserDetection sd;
	vector<string> hand = { "i23", "123", "456", "789", "000", "o", "O" };
	string out = sd.haveSimilar(hand);
	return 0;
}

