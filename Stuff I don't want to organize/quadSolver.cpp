#include <iostream>
#include <cmath>
using namespace std;

int
main ()
{
  double sol1;			//first solution
  double sol2;			//second solution (not always used)
  double a, b, c;		//input values
  cin >> a >> b >> c;
  cout << a << "x^2 ";
  if (b < 0)			//ensures no double signs in the equation, i.e. 1x^2 + 3x + -5
    {
      cout << "- " << fabs (b);
    }
  else
    {
      cout << "+ " << b;
    }
  cout << "x ";
  if (c < 0)			//corrects double signs
    {
      cout << "- " << fabs (c);
    }
  else
    {
      cout << "+ " << c;
    }
  cout << " = 0" << endl;
  double discrim = pow (b, 2) - 4 * a * c;	//finding the discriminant to see if there are imaginary roots
  if (discrim > 0 && a != 0)	//two real roots
    {
      sol1 = (-b + sqrt (discrim)) / (2 * a);
      sol2 = (-b - sqrt (discrim)) / (2 * a);
      cout << "x = " << sol2 << endl;
      cout << "x = " << sol1 << endl;
      return 0;
    }
  else if (a == 0 || discrim == 0)	//one root
    {
      if (a != 0)		//nonlinear
	{
	  sol1 = -b / (2 * a);
	  if (!(isfinite (sol1)))	//checks if roots even exist or not
	    {
	      cout << "Unable to determine root(s)." << endl;
	    }
	}
      else			//linear
	{
	  sol1 = -c / b;
	}
      if (!(isfinite (sol1)))	//checks if roots even exist or not
	{
	  cout << "Unable to determine root(s)." << endl;
	}
      else
	{
	  cout << "x = " << sol1 << endl;
	}
      return 0;
    }
  else				//imaginary roots!
    {
      double x1 = sqrt (fabs (discrim)) / (2 * a);	//first part of solution (the imagninary part)
      double x2 = -b / (2 * a);	//second part of solution
      if (x1 < 0)
      {
        cout << "x = " << x2 << " + " << fabs(x1) << "i" << endl;
        cout << "x = " << x2 << " - " << fabs(x1) << "i" << endl;
      }
      else
      {
        cout << "x = " << x2 << " - " << x1 << "i" << endl;
        cout << "x = " << x2 << " + " << x1 << "i" << endl;
      }
      return 0;
    }
}