// srm241.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <math.h>

using namespace std;

class BlackjackWinner
{
public:
	int winnings(int bet, int dealer, int dealerBlackjack, int player, int blackjack);
};

int BlackjackWinner::winnings(int bet, int dealer, int dealerBlackjack, int player, int blackjack)
{
	bool pwin = false, dwin = false, push=false;
	bool pbj = false;

	if (player > dealer)
	{
		if (player <= 21)
			pwin = true;
		if (player == 21 && blackjack == true)
			pbj = true;
	}
	else if (player == dealer)
	{
		if (blackjack == true && dealerBlackjack==true)
			push = true;
		else if (blackjack == true)
		{
			pwin = true;
			pbj = true;
		}

		if (blackjack != true && dealerBlackjack == true)
		{
			dwin = true;
		}
		else if (player <= 21)
		{
			push = true;
		}		
	}
	else if (player < dealer)
	{
		if (dealer>21 && player<=21)
		{
			pwin = true;
			{
				if (blackjack)
					pbj = true;
			}
		}


		if (dealer <= 21)
			dwin = true;

		if (player > 21)
			dwin = true;
	}
		
	if (pwin&&pbj)
		return (1.5*bet);
	else if (pwin)
		return bet;
	else if ((dwin || pwin == false) && (push==false))
		return -bet;
	else if (push)
		return 0;	
}


int main()
{
	BlackjackWinner bw;
	int b = 26 , d = 21 , dbj = 1 , p = 21 , pbj = 0;
	int win = bw.winnings(b, d, dbj, p, pbj);
	return 0;
}

