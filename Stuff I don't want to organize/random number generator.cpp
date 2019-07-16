#include <iostream>
#include <random>
#include <string>
#include <vector>
using namespace std;

int
main ()
{
  int x = 0;
  random_device r_dev{};
  default_random_engine d_engine{r_dev ()};

  uniform_int_distribution <> my_uni_dist{0, 5};
  int val = my_uni_dist (d_engine);
  vector < int >v (6);

  for (int i = 0; i < 10001; ++i)
    {
      x = my_uni_dist (d_engine);
      ++v[x];
    }
  for (int j = 0; j < 6; ++j)
    {
      cout << j << ": " << v[j] << endl;
    }

  return 0;
}
