// 526.cpp : Defines the entry point for the console application.
//
/*

Problem Statement
    
	Mr. Dengklek is taking part in an online quiz. The quiz consists of N multiple-choice questions, conveniently numbered 0 through N-1. For each question there are three possible answers labeled A, B, and C. For each question, exactly one of the three possible answers is correct. You are given the information on correct answers as a string answers. More precisely, answers[i] is the correct answer to the i-th question. This is of course unknown to Mr. Dengklek.  Mr. Dengklek did not know the answer to any of the quiz questions. Being desperate, he hacked the website of the quiz. However, the only thing he could obtain was aggregate information on the answers that will be used. More precisely, thanks to the hack Mr. Dengklek now knows how many questions have the answer A, how many have the answer B, and how many have the answer C.  When taking the quiz, Mr. Dengklek will be given the questions one at a time, in the same order that is used in answers. For each of the questions, he will use his intuition to pick one of the answers that are still possible. After he picks the answer for a question, the quiz will always show him the correct answer for that question.  Mr. Dengklek has noticed that sometimes he can rule out some of the answers when answering a question. Your method must return a vector <int> containing N elements. The i-th element in this vector <int> must be the number of options Mr. Dengklek will choose from when answering the i-th question.
	Definition
	    
		Class:
		CheatingQuiz
		Method:
		howMany
		Parameters:
		string
		Returns:
		vector <int>
		Method signature:
		vector <int> howMany(string answers)
		(be sure your method is public)
		Limits
		    
			Time limit (s):
			2.000
			Memory limit (MB):
			64
			Constraints
			-
			answers will contain between 1 and 50 characters, inclusive.
			-
			Each character of answers will be 'A', 'B', or 'C'.
			Examples
			0)

			    
				"AAAAA"
				Returns: {1, 1, 1, 1, 1 }
				Mr. Dengklek knows that A is the correct answer to all questions. Therefore, for each question, he only has one choice: answering A.
				1)

				    
					"AAABBB"
					Returns: {2, 2, 2, 1, 1, 1 }
					Mr. Dengklek knows that there will be three As and three Bs. For each of the first three questions he has two choices: answering A or B. After answering the third question, he will discover that all As have been used, so for each of the remaining questions he only has one choice: answering B.
					2)

					    
						"CAAAAAC"
						Returns: {2, 2, 2, 2, 2, 2, 1 }

						3)

						    
							"BBCA"
							Returns: {3, 3, 2, 1 }

							4)

							    
								"BACACABCBBBBCAAAAACCCABBCAA"
								Returns:
								{3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
								3, 2, 1, 1 }

								This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <vector>
#include <string>
#include <sstream>
#include <math.h>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

class CheatingQuiz
{
public:
	vector <int> howMany(string answers);
};

vector <int> CheatingQuiz::howMany(string answers)
{
	vector<int> ch;

	int a = count(answers.begin(), answers.end(), 'A');
	int b = count(answers.begin(), answers.end(), 'B');
	int c = count(answers.begin(), answers.end(), 'C');

	for (int i = 0; i < answers.size(); ++i)
	{
		int choicecnt = 0;
		if (a > 0)
			choicecnt++;
		if (b > 0)
			choicecnt++;
		if (c > 0)
			choicecnt++;
		ch.push_back(choicecnt);

		switch (answers[i])
		{
		case 'A':			
			a -= 1;			
			break;
		case 'B':			
			b -= 1;			
			break;
		case 'C':
			c -= 1;
			break;
		default:
			break;
		}
	}

	return ch;

}


int main()
{

	CheatingQuiz cqz;
	vector<int> chs = cqz.howMany("CAAAAAC");
    return 0;
}

