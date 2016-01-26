// srm226.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>

using namespace std;

class VLNString
{
public:
	string makeAcronym(string longName);
};


string VLNString::makeAcronym(string longName)
{
	size_t pos1 = 0;
	string thewd = "";
	string theac = "";

	while (pos1 < longName.length() && pos1!=std::string::npos)
	{
		pos1 = longName.find_first_not_of(" ",pos1);

		size_t pos2 = pos1;
		pos2 = longName.find(" ", pos2);


		if (pos2 == std::string::npos)
			pos2 = longName.length();			
		

		if (pos1 != std::string::npos && pos2 != std::string::npos)
		{
			thewd = string(longName, pos1, pos2 - pos1);
			pos1 = pos2;

			if (thewd == "and" || thewd == "of" || thewd == "the")
				continue;
			else
			{
				theac += toupper(thewd[0]);
			}
		}		
	}

	return theac;
}


int main()
{
	VLNString vl;

	string l = "dance dance revolution";
	string ac = vl.makeAcronym(l);
	return 0;
}

