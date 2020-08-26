#include <iostream>
#include <cstdlib>
#include "Stress_ball.h"
#include "time.h"
#include "Collection_template_2.h"

using namespace std;
using CollectionSB = Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes>;

std::istream &operator>>(std::istream &is, CollectionSB &c)
{
    if(is.good())
    {
        std::string line = "";
        int space = 0;

        std::string cc = "";
        std::string ss = "";

        Stress_ball_colors color;
        Stress_ball_sizes size;

        while(!is.eof() || is.bad())
        {
            is >> cc;
            is >> ss;
            
            if(cc.compare("red") == 0) {color = Stress_ball_colors::red;}
            else if(cc.compare("blue") == 0) {color = Stress_ball_colors::blue;}
            else if(cc.compare("yellow") == 0) {color = Stress_ball_colors::yellow;}
            else if(cc.compare("green") == 0) {color = Stress_ball_colors::green;}
            else {break;}

            if(ss.compare("small")) {size = Stress_ball_sizes::small;}
            else if(ss.compare("medium")) {size = Stress_ball_sizes::medium;}
            else if(ss.compare("large")) {size = Stress_ball_sizes::large;}
            else {break;}

            Stress_ball sb = Stress_ball(color, size);
            c.insert_item(sb);
        }
    }
    return is;
}
int main(){
  srand(time(NULL));
  
  cout << "Default constructor test:\n";
  Stress_ball arr_test[5];
  for(int i = 0; i < 5; i++){
    arr_test[i] = Stress_ball();
    cout << i << ": " << arr_test[i] << endl;
  }

  cout << "\nTwo arg constructor test:\n";
  Stress_ball test2(Stress_ball_colors::red, Stress_ball_sizes::small);
  cout << test2 << endl;

  Stress_ball test3(Stress_ball_colors::green, Stress_ball_sizes::large);
  cout << test3 << endl;

  cout << "\nCompare stress balls:\n";
  for (int i = 0; i < 5; i++) {
    if (arr_test[i] == test2) {
      cout << "arr_test[" << i << "] equal test2\n";
    } else if (arr_test[i] == test3) {
      cout << "arr_test[" << i << "] equal test3\n";
    } else {
      cout << "arr_test[" << i << "] not equal test2 nor test3\n";
    }
  }
  
}