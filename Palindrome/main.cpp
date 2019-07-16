#include "functions.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	string flag = "";
	int startPoint = 0;
	vector <char> flagElements {}; 
	bool caseFlag = false;
	bool spaceFlag = false;
	bool firstFlagValid = false;

	//if there is only one argument (aside from the exe)
	//if the first arg is a flag and not a valid flag
	//if there are only 2 args and both are flags
	if(argc <= 2 || argv[1][0] == '-' && !isValidFlag(argv[1]) || (argc == 3 && argv[1][0] == '-' && argv[2][0] == '-'))
	{
		printUsageInfo(argv[0]);
		return 0;
	}

	//if the first arg is a flag
	if(argv[1][0] == '-')
	{
		firstFlagValid = true;
		startPoint = 1;
		flag = argv[1];
		for(int i = 0; i < flag.size(); ++i)
		{
			if(tolower(flag[i]) == 'c')
			{
				caseFlag = true;
			}

			if(tolower(flag[i]) == 's')
			{
				spaceFlag = true;
			}
		}
	}

	if(argc >= 3 && argv[2][0] == '-' && firstFlagValid) // FIXME check that first flag is also valid
	{
		startPoint = 2;
		flag = argv[2];
		for(int i = 0; i < flag.size(); ++i)
		{
			if(tolower(flag[i]) == 'c')
			{
				caseFlag = true;
			}

			if(tolower(flag[i]) == 's')
			{
				spaceFlag = true;
			}
		}
	}

	bool palindrome = false;
	string word = "";
	string wordProcessed = "";

	for(int i = startPoint + 1; i < argc; ++i) //starting after the executable and looping through the argument list
	{
		word = argv[i];
		wordProcessed = word;
		wordProcessed = removePunctuation(wordProcessed);
		palindrome = isPalindrome(wordProcessed, caseFlag, spaceFlag);
		cout << "\"" << word << "\" is ";

		if(!palindrome)
		{
			cout << "not ";
		}

		cout << "a palindrome." << endl;
		palindrome = false;
	}
	return 0;
}