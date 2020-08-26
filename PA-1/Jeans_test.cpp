#include <iostream>
#include <cstdlib>
#include "Jeans.h"
#include "Collection_template_2.h"
#include "time.h"

using namespace std;
using CollectionJN = Collection<Jeans, Jeans_colors, Jeans_sizes>;

std::istream &operator>>(std::istream &is, CollectionJN &c)
{
  if (is.good())
  {
    std::string line = "";
    int space = 0;

    std::string cc = "";
    std::string ss = "";

    Jeans_colors color;
    Jeans_sizes size;

    while (!is.eof() || is.bad())
    {
      is >> cc;
      is >> ss;

      if (cc.compare("red") == 0)
      {
        color = Jeans_colors::red;
      }
      else if (cc.compare("blue") == 0)
      {
        color = Jeans_colors::blue;
      }
      else if (cc.compare("yellow") == 0)
      {
        color = Jeans_colors::yellow;
      }
      else if (cc.compare("green") == 0)
      {
        color = Jeans_colors::green;
      }
      else
      {
        break;
      }

      if (ss.compare("small"))
      {
        size = Jeans_sizes::small;
      }
      else if (ss.compare("medium"))
      {
        size = Jeans_sizes::medium;
      }
      else if (ss.compare("large"))
      {
        size = Jeans_sizes::large;
      }
      else
      {
        break;
      }

      Jeans sb = Jeans(color, size);
      c.insert_item(sb);
    }
  }
  return is;
}

int main()
{
  srand(time(NULL));

  cout << "Default constructor test:\n";
  Jeans arr_test[5];
  for (int i = 0; i < 5; i++)
  {
    arr_test[i] = Jeans();
    cout << i << ": " << arr_test[i] << endl;
  }

  cout << "\nTwo arg constructor test:\n";
  Jeans test2(Jeans_colors::red, Jeans_sizes::small);
  cout << test2 << endl;

  Jeans test3(Jeans_colors::green, Jeans_sizes::large);
  cout << test3 << endl;

  cout << "\nCompare stress balls:\n";
  for (int i = 0; i < 5; i++)
  {
    if (arr_test[i] == test2)
    {
      cout << "arr_test[" << i << "] equal test2\n";
    }
    else if (arr_test[i] == test3)
    {
      cout << "arr_test[" << i << "] equal test3\n";
    }
    else
    {
      cout << "arr_test[" << i << "] not equal test2 nor test3\n";
    }
  }
}