#include <iostream>
#include <limits>
#include <string>
#include "/home/faculty/e/elba/teach/shared/BinaryRepresentation.h"
#include "/home/faculty/e/elba/teach/shared/FullPrecisionWithBoost.h"

int main ()
{
    auto val = -1;
    std::cout << "   stored value : " << full_precision(val) << std::endl;
    std::cout << "     binary rep : " << bit_string(val) << std::endl;
    std::cout << "binary rep size : " << sizeof(val) * 8 << " bits" << std::endl;
    return 0;
}
