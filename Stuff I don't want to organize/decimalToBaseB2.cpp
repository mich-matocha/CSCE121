#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    int decimal;
    int base;
    cout << "Enter a decimal value : ";
    cin >> decimal;
    do
    {
        cout << "Enter a base (2-16) : ";
        cin >> base;
    } while(base > 16 || base < 2);
    cout << endl;
    int number = decimal;
    int numDigits = 0;
    while(number > 0)
    {
        number/= base; //calculating the number of digits (how many times you can divide by the base)
        numDigits++; 
    }
    char currDigit;
    
    vector<char> finalAns(numDigits); //creating a vector to store digits
    
    
    int placeVal;
    number = decimal;
    int intCurrDigit;
    
    if(numDigits == 0)
    {
        finalAns.push_back('0');
    }
    
    for(int i = numDigits - 1; i >= 0; i--)
    {
        placeVal = pow(base, i); //calculating the number to divide by
        intCurrDigit = number / placeVal; //makes it such that when subtracting from 'number' it doesn't yield the wrong result
        currDigit = number / placeVal + 48; //+ 48 makes the int to char conversion valid & yields the correct result
        if(currDigit > '9')
        {
            currDigit += 7; //jumps to A-F when necessary
        }
        finalAns.at(i) = currDigit; //adding the current digit to the vector
        number -= (placeVal * intCurrDigit); //amount remaining
    }

    cout << "Base-10 value : " << decimal << endl;
    cout << "Base-" << base << " value : ";
        for(int i = finalAns.size() - 1; i >= 0; i--) //looping backwards because digits were inserted in the vector backwards
    {
        cout << finalAns.at(i);
    }
    cout << endl << "Digits required : " << numDigits << endl;
}