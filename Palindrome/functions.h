#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>

using namespace std;

bool isValidFlag(string flag);
void printUsageInfo(string exe);
string toLower(string word);
bool isPalindrome(string word, bool caseFlag, bool spaceFlag);
bool isPalindromeR(string word); //recursive function, case sensitive and include spaces as characters
string preprocessString(string word, bool caseFlag, bool spaceFlag);
string removePunctuation(string word);


#endif