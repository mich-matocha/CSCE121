#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>

using namespace std;

int main() {
    srand(std::chrono::duration_cast<std::chrono::milliseconds>
     (std::chrono::system_clock::now().time_since_epoch()).count()%2000000000); 
    // needed to autograde some test cases in Mimir

    int numDigits = 0;
    int code = 0;
    vector<int> d;
    vector<int> possibleDigits {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    do
    {
        cout << "Enter number of digits in code (3, 4 or 5): ";
        cin >> numDigits;
    }while(numDigits != 3 && numDigits != 4 && numDigits != 5 && numDigits != 0);

    if(numDigits == 0) //cheat code!!
    {
        cout << "Enter code: ";
        cin >> code;
        cout << "Enter number of digits in code: ";
        cin >> numDigits;
        vector<int> digits(numDigits);
        int hold = code;
        int count = 0;
        vector<int> backwards(numDigits);

        while(hold > 0)
        {
            int dig = hold % 10;
            backwards.at(count) = dig;
            hold /= 10;
            count++;
        }

        int diff = count - numDigits;

        if(diff != 0)
        {
            for(int i = 0; i < diff + 1; i++)
                backwards.push_back(0);
        }

        for(int i = 0; i < digits.size(); i++) //adding elements of backwards to digits in the correct order
        {
            digits.at(i) = backwards.back(); //assigning to digits
            backwards.pop_back(); //deleting so loop works (lol)
        }
        d = digits;

        for(int i = 0; i < numDigits; i++) //THIS IS THE CODE YOU WANT!! THIS IS HOW YOU COMPARE TWO VECTORS!!!
        {
            for(int j = 0; j < d.size(); j++)
            {
                if(j != i)
                {
                    while(d.at(i) == d.at(j))
                    {
                        cout << "Each number must be different." << endl;
                    }
                }
            }
        }

    }

    else //fill code with random digits, generating double digits somehow?? something is getting missed.
    {
        for(int i = 0; i < numDigits; i++) //i is the "current" digit
        {
            int index = rand() % (possibleDigits.size() - 1);
            d.push_back(possibleDigits.at(index));
            possibleDigits.erase(possibleDigits.begin() + index);
        }
    }

    cout << "Number to guess: ";

    for(int i = 0; i < d.size() - 1; i++) //print out code to guess
        {
            cout << d.at(i) << "-";
        }

    cout << d.at(d.size() - 1) << endl;

//NOW HERE IS WHERE THE USER WILL GUESS
    int guess = 0;
    bool guessCorrect = false;
    vector<int> guessDigits(numDigits);
    bool duplicate = false;
    int bulls = 0;
    int cows = 0;

    while(!guessCorrect)
    {
        cout << "Enter Guess: "; //CAPITAL G HAHA
        cin >> guess;
        int hold = guess;
        duplicate = false;
        bulls = 0;
        cows = 0;
        int count = 0;
        
        while(hold > 0) // checking if user input too many digits
        {
            hold /= 10;
            count++;
        }
        
        if(count > numDigits)
        {
            cout << "You can only enter " << numDigits << " digits." << endl;
        }
        
        else
        {
            hold = guess;
            for(int i = numDigits - 1; i >= 0; --i)
        {
            int dig = hold % 10;
            guessDigits.at(i) = dig;
            hold /= 10;
        }
        
        for(int i = 0; i < numDigits; i++) //making sure that the guess is a valid guess
        {
            for(int j = 0; j < guessDigits.size(); j++)
            {
                if(j != i && guessDigits.at(i) == guessDigits.at(j))
                {
                    while(!duplicate)
                    {
                        cout << "Each number must be different." << endl;
                        duplicate = true;
                    }
                }
            }
        }
        
        if(!duplicate)
        {
            for(int i = 0; i < numDigits; i++) //checking for cows and bulls
            {
                if(guessDigits.at(i) == d.at(i))
                {
                    ++bulls;
                }
                else
                {
                    for(int j = 0; j < numDigits; j++)
                    {
                        if(d.at(i) == guessDigits.at(j))
                        {
                            ++cows;
                        }
                    }
                }
            }
            
            if (bulls == numDigits)
            {
                guessCorrect = true;
            }
   
            if(cows > 0 || bulls < numDigits)
            {
                cout << bulls << " bulls" << endl;
                cout << cows << " cows" << endl;
            }
            else
            {
              cout << bulls << " bulls... ";
            
                for(int i = 0; i < d.size() - 1; i++) //print out code to guess
                {
                    cout << d.at(i) << "-";
                }

                cout << d.at(d.size() - 1) << " is correct!" << endl;
            }
        }
        }
        
    }
}
