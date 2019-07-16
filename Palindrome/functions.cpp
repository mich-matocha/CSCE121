#include "functions.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValidFlag(string flag)
{
	if(flag.size() <= 3 && flag[0] == '-' && (tolower(flag[1]) == 'c' || tolower(flag[1]) == 's'))
	{
		if(flag.size() == 3 && (tolower(flag[2]) == 'c' || tolower(flag[2]) == 's'))
		{
			return true;
		}
		else if(flag.size() != 3)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if(flag.size() > 3 && flag[0] == '-')
	{
		flag = toLower(flag);
		int notC = flag.find_first_not_of('c');
		int notS = flag.find_first_not_of('s');
		if(notC == -1 || notS == -1)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

void printUsageInfo(string exe)
{
	cout << "Usage: " << exe << " [-c] [-s] string ..." << endl;
	cout << "  -c: turn on case sensitivity" << endl << "  -s: turn off ignoring spaces" << endl;
}

bool isPalindrome(string word, bool caseFlag, bool spaceFlag)
{	
	bool ret = false;
	word = preprocessString(word, caseFlag, spaceFlag);
	ret = isPalindromeR(word);
	return ret;
}

bool isPalindromeR(string word) //recursive helper function, case sensitive and include spaces as characters 
{
	if(word.size() == 0 || word.size() == 1) //if the word is only one or none letters long it's obviously a palindrome
	{
		return true;
	}
	else if(word[0] == word[word.size() - 1]) // if the first and last letter are equal
	{
		return isPalindromeR(word.substr(1, word.size() - 2)); //call the function again without the first and last letters
	}
	else
	{
		return false; // this is where I'm having the issues! Not returning correctly
	}
}

string toLower(string word) //lowers entire string
{
	string ret = "";
	for(int i = 0; i < word.size(); ++i)
	{
		ret += tolower(word[i]);
	}
	return ret;
}

string preprocessString(string word, bool caseFlag, bool spaceFlag) //removes spaces or case sensitivity if necessary
{
	string ret = word;
	if(caseFlag == 0) //if the case of the letters doesn't matter
	{
		ret = toLower(ret);
	}
	if(spaceFlag == 1) //if spaces don't matter
	{
		for(int i = ret.size() - 1; i >= 0; --i)
		{
			if(ret[i] == ' ')
			{
				ret.erase(i, 1);
			}
		}
	}
	return ret;
}

string removePunctuation(string word)
{

	for(int i = 0; i < word.size(); ++i) //replacing punctuation with x'es such that all punctuation is seen as the same
	{
		if(!isalpha(word[i]) && word[i] != ' ')
		{
			word.erase(i, 1);
		}
	}
	return word;
}
