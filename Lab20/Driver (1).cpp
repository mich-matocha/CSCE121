#include <iostream>
#include <stdexcept>
#include "BasicTree.h"
#include "Node.h"
using namespace std;

int main()
try
{
    BasicTree bt;
    cout << bt << endl;
    bt.insert(10);
    bt.insert(5);
    cout << bt << endl; 
    //cout << bt.find(10) << endl;
    //cout << bt.find(7) << endl; 

    bt.insert(25);
    bt.insert(3);
    bt.insert(500);
    bt.insert(34);
    bt.insert(2);
    bt.insert(7);
    bt.insert(400);
    cout << bt << endl;
    bt.in_order();
    bt.post_order();
    bt.pre_order();
    
    return 0;
} catch (runtime_error& e)
{
    cerr << e.what() << '\n';
    return 1;
} catch (...)
{
    cerr << "exception\n";
    return 2;
}