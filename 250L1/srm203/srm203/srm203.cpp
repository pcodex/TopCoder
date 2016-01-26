// srm203.cpp : Defines the entry point for the console application.
//

#include <string>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class UserName
{
public:
	string newMember(vector <string> existingNames, string newName);
};


string UserName::newMember(vector <string> existingNames, string newName)
{
	string nos = "123456789";


	string finalNewName = newName;

	//get base name without trailing numbers
	int pos = finalNewName.find_first_of(nos);
	string baseNm = string(finalNewName, 0, pos);

	int cnt = 0;
	while (find(existingNames.begin(), existingNames.end(), finalNewName) != existingNames.end())
	{
		finalNewName = baseNm;
		stringstream snm;
		snm << finalNewName << ++cnt;
		finalNewName = snm.str();
	}

	return finalNewName;
}


int main()
{
	UserName unm;

	vector<string> exsNms = { "MasterOfDisaster", "TygerTyger1", "DingBat", "Orpheus",
		"TygerTyger", "WolfMan", "MrKnowItAll" };

	string inpnm = "TygerTyger";

	string finalName = unm.newMember(exsNms, inpnm);

	return 0;
}

