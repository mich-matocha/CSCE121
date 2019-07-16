#include <iostream>
using namespace std;

class Color {
/* Public */
public:
    void cout_rgb (void) { cout << "Color Values: (" << R << ',' << G <<
        ',' << B << ')' << endl;}
    int get_R() 
    {
        return R;
    }
    int get_G() 
    {
        return G;
    }
    int get_B() 
    {
        return B;
    }
    void set_R(int r)
    {
        if (!is_valid_val(r))
            throw runtime_error(" ");
        R = r;
    }   
    void set_G(int g)
    {
        if (!is_valid_val(g))
            throw runtime_error(" ");
        G = g;
    }
    void set_B(int b)
    {
        if (!is_valid_val(b))
            throw runtime_error(" ");
        B = b;
    }  
    bool is_valid_val(int v)
    {  
        if (v < 0 || v > 255)
            return false;
        else
            return true;
    }
    Color()
    {
        R = 255;
        G = 255;
        B = 255;
    }   
/* Private */
private:
    int R;
    int G;
    int B;
};

int main()
{
    Color color;
    color.cout_rgb();
    cout << "color.R = " << color.get_R() << endl;
    cout << "color.G = " << color.get_G() << endl;
    cout << "color.B = " << color.get_B() << endl;

    cout << "Please enter integer values for R, G, and B: ";
    int R, G, B;
    cin >> R >> G >> B;
    try{
    color.set_R(R); color.set_G(G); color.set_B(B); }
    catch (runtime_error &e) {
        	cout << "the value is out of range" << endl;
            return 1;
        }
    color.cout_rgb();
}