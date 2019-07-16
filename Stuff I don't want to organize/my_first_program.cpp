#include <iostream>
#include <string>

int main()
{
	std::string fname = "";
    std::string lname = "";
    std::cout << "Please enter your first name [space] last name: " << std::endl;
    std::cin >> fname >> lname;
    std::cout << "Hello, " << fname << " " << lname << "!" << std::endl;
    return 0;
}