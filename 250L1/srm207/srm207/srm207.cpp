// srm207.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class TransportCounting
{
public:
	int countBuses(int speed, vector <int> positions, vector <int> velocities, int time);
};

int TransportCounting::countBuses(int speed, vector <int> positions, vector <int> velocities, int time)
{
	int mytPosition = 0;
	int metCnt = 0;

	for (int j = 0; j < positions.size(); ++j)
	{
		if (positions[j] <= mytPosition)
		{
			metCnt++;
			positions[j] = -99;
		}
	}
	
		//final position
		mytPosition = time*speed;

		vector<int> bustPositions;

		for (int i = 0; i < positions.size(); ++i)
		{			
			if (positions[i] != -99){

				int bustpos = positions[i] + (velocities[i] * time);
				bustPositions.push_back(bustpos);
			}
		}

		
		for (int z = 0; z < bustPositions.size(); ++z)
		{
			if (bustPositions[z] <= mytPosition)
			{				
				metCnt++;
			}
		}	

	return metCnt;
}

int main()
{
	TransportCounting tcnt;

	int s = 219;
	
	vector<int> pos = {736, 942, 913, 719, 806, 787, 385, 874, 482, 262, 397, 40, 924, 252, 228, 29, 946, 963, 287, 432, 26, 773, 821, 879, 13, 313, 854, 
	345, 980, 714, 442, 966, 986, 376, 232, 644, 80, 990, 144, 0, 133, 414, 10, 544, 266, 287, 359, 276, 929, 776};

	vector<int> vel = {236, 606, 278, 150, 293, 272, 526, 872, 32, 892, 262, 514, 421, 982, 578, 350, 829, 853, 385, 
	963, 112, 869, 356, 617, 373, 963, 812, 606, 707, 495, 606, 377, 965, 3, 968, 891, 809, 819, 661, 923, 193, 814, 38, 140, 736, 599, 117, 456, 746, 845};
	
	int t = 83;		
	

	/*int s = 100;

	vector<int> pos = {0};

	vector<int> vel = {0};

	int t = 0;*/

	int cnt = tcnt.countBuses(s, pos, vel, t);
	return 0;
}

