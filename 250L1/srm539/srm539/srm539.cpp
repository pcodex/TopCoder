// srm539.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class PlatypusPaternity
{
public:
	int maxFamily(vector <string> femaleCompatibility, vector <string> maleCompatibility, vector <string> siblingGroups);
};

int PlatypusPaternity::maxFamily(vector <string> femaleCompatibility, vector <string> maleCompatibility, vector <string> siblingGroups)
{		
	vector<int> chldcnt;
	
	int fmcnt = 0, mcnt = 0;
	int fmlid = 0, mlid = 0;

	for (int sbgrpid = 0; sbgrpid < siblingGroups.size(); ++sbgrpid)
	{
		int sibcnt = count(siblingGroups[sbgrpid].begin(), siblingGroups[sbgrpid].end(), 'Y');		
		
		for (int sblen = 0; sblen < siblingGroups[0].length(); ++sblen)
		{
			if (siblingGroups[sbgrpid][sblen] == 'Y')
			{			
				bool fmfound = false;
				//check corresp idx in each female
				for (fmlid; fmlid < femaleCompatibility.size(); ++fmlid)
				{					
					if (femaleCompatibility[fmlid][sblen] == 'Y')
					{
						fmfound = true;
						fmcnt++;
						break;
					}
					else
					{						
						fmfound = false;						
						continue;
					}
				}
				if (!fmfound)
					break;

				//male check
				bool mfound = false;
				//check corresp idx in each female
				for (mlid; mlid < maleCompatibility.size(); ++mlid)
				{
					if (maleCompatibility[mlid][sblen] == 'Y')
					{
						mfound = true;
						mcnt++;
						break;
					}
					else
					{						
						mfound = false;
						continue;
					}
				}
				if (!mfound)
					break;
			}
		}

		if (fmcnt == sibcnt && mcnt == sibcnt)
		{
			chldcnt.push_back(sibcnt);
		}		

		fmcnt = 0, mcnt = 0;
		fmlid = 0, mlid = 0;
			
	}
	int famsz = 0;
	if (chldcnt.size() > 0)
		famsz = *(max_element(chldcnt.begin(), chldcnt.end())) + 2;

	return famsz;
}


int main()
{
	PlatypusPaternity pp;


	vector<string> f1 = { "NNN", "YNY", "YYN", "NYY", "NYY", "YYY", "NNN", "YNY", "YYN", 
					     "YYN", "NYN", "YNY", "NNY", "YNY", "YNN", "NYN", "NNY", "YNN", 
						 "YYN", "NYN", "YYN", "YNN", "NYN", "YNN", "YYN", "YNY", "NYN", "YYY", "NNY" };

	vector<string> m1 = { "NNN", "YNN", "YYY", "NNN", "NYN", "YYN", "YYN", 
						 "NYN", "YYN", "YYY", "YNY", "NNY", "YNN", "YYY", 
						 "YNN", "YNN", "YNY", "YNY", "YYY", "NNY", "NNY", 
						 "YYY", "YYY", "YNY", "NYY", "NYY", "YNN", "YNY",
						 "YNN", "NYY", "YNY", "NYN", "NYY", "NNN", "YYY",
						 "YYY", "YYY", "YNN", "NYY", "NYY", "NYY", "YYN", 
						 "NNY", "NYN", "NYN", "NYY", "NNY" };
	
	vector<string> sg1 = { "NYN", "YNY" };

	vector<string> f2 = { "NNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNN", "NNNNNNYNNNYNNNN", "NNNNNNNNNNNYNNN", "NNNNNNNNNYNNNNN",
		"NNNNNNNYNNNNNNN", "NNNYNYNNNNNNNNN", "NNYNNYNNNNNYYNN", "NNNNNNYNNNNNNNY", "NNNNNNNNNNNYYNN",
		"NNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNN", "NNNNNYNNYNNNNYN", "YNNNNNNNNNYYNYN", "NYYNYNNNNNNNNNN",
		"NNNNNNNNNNNNNNN", "NYNNNNNNNNNNNNN", "NNNNNNYNYNNNNNY", "NYYNNNNNYNNNNNN", "NNNNNNNNNNNNNNN",
		"NNNYNYNNNNNYNNN", "NNNNNNYNNNNNNYN", "NYNNNNNNNNNNNNN", "NNYNYNNNNNNNNNN", "NNNNNNNNNNNNNNN",
		"NNNNNNNNNNNNYNN", "NNNNNNNNYNNNNNY", "NNYNNNNNNNNNNNN", "NNYNNNNNNYYNNNN", "NNNNNNNNNNNNNNN",
		"NYNNNNNNNNNNNNN", "NNNNNYNNNNNNNNN", "NNNYYNYNNNNNNNN", "NNNNNNNNNNNNNNN", "NNYNNNNYNYNNNNN",
		"NYNNNNNNNNNNNYN", "NNNNNNNNNNNNNNN", "YNNNNNNNNNNNNNN", "NNNYNNNNNNNNYYN", "NYNNYNNNNNNNNNN",
		"NNNNNNNNNNNNNYN", "NNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNN" };

	vector<string> m2 = { "NNNNNNNYNYNNNNY", "NNNNNNYNNNNNNNN", "NNNNNNNNNNYNNNN", "NNYYNNNNNNNNNNN",
		"NNNNNNNNNYYNNNN", "NNNNNNNYNNNNYNN", "NNNNYNNNNNNNNNN", "NNNNNNNNYNNNNNN",
		"NNNNNNNNNNNNNNN", "NNNNNYNNNNNNNNN", "NNNNNNNNNYNNNYY", "NNYNNNYNNNYNNNN",
		"NNNNNNYYNNNNNNN", "NNNNNNNNNNNNNNN", "NNNNNNNYNNNNNNN", "YNYNNNNNNNNNNNY",
		"NNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNN", "NNNNNNNYNNYNNNN", "NNNNNNNNNNNNNNY",
		"NNNNNNNNNNNYNNN", "NNNNNNNNNNNNNYY", "YNYNNNNNNNNNNNN", "NNYYNNNNNNNNNNN",
		"YNNNNNNNYNNNNNN", "NNNNNNNNNNNNNNN", "NNYNNNNNNNNNNNN", "NYNNNNNNNNNNNNN",
		"NNNNNYNNNNNNNNN", "NNNNNNYNNYYNNNN", "NNNNNNNNNNNNNNN", "NYNYNYNNNNNNNNN",
		"YNNNNNNNNNNNNYN", "NNNNNNNNNNYNNNN", "NNNYYNNNNYNNYNN", "NNNNNYNNNNYNYNN",
		"NNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNN", "NNNNNNNNYNNNNYN", "YNNNNNNNNNNNNNN",
		"NNNNNNNNNNNNNNN", "NNNNNNNNYNNNNNN", "NNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNN" };

	vector<string> sg2 = { "NNNNYYYNNNNNNNN", "NNNYNNNNNYNNNNN", "NNYNNNNNNNNYNNN", "YNNNNNNNNNNNNNN",
		"NYNNNNNNNNNNNNN", "NNNNNNNNYNNNNYN", "NNNNNNNNNNYNNNY", "NNNNNNNNNNNNYNN", "NNNNNNNYNNNNNNN" };


		
	//int maxf1 = pp.maxFamily(f1, m1, sg1);
	int maxf2 = pp.maxFamily(f2, m2, sg2);

	return 0;
}

