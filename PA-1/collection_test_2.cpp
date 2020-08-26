#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Collection_template_2.h"
//#include "Stress_ball.h"
//#include "Jeans.h"
using namespace std;

using CollectionSB = Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes>;
using CollectionJN = Collection<Jeans, Jeans_colors, Jeans_sizes>;

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
/*
STRESS BALL TESTER SECTION
-
-
-
-
-
*/
void test_stress_balls()
{
    Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes> balls;

    std::cout << "Insert 6 stress balls to balls" << std::endl;
    balls.insert_item(Stress_ball());
    balls.insert_item(Stress_ball());
    balls.insert_item(Stress_ball());
    balls.insert_item(Stress_ball());
    balls.insert_item(Stress_ball());
    balls.insert_item(Stress_ball());

    std::cout << "Insert RED MEDIUM" << std::endl;

    Stress_ball test1 = Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::medium);

    balls.insert_item(test1);

    std::cout << "TEST CONTAINS RED, MEDIUM" << std::endl;
    std::cout << balls.contains(test1) << std::endl;
    std::cout << "Total balls: " << balls.total_items() << std::endl
              << "Total Red: " << balls.total_items(Stress_ball_colors::red) << std::endl
              << "Total Medium" << balls.total_items(Stress_ball_sizes::medium) << std::endl
              << std::endl;
    balls.print_items();
    std::cout << std::endl;
    balls.remove_any_item();
    std::cout << std::endl;
    balls.print_items();
    std::cout << std::endl;
    balls.remove_this_item(test1);

    std::cout << "Print balls:" << std::endl;
    std::cout << balls;

    std::ifstream in;
    in.open("stress_ball1.data");
    if (!in.is_open())
    {
        std::cout << "Could not open file\n\n";
    }

    Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes> balls2;
    in >> balls2;

    in.close();
    std::cout << "Load balls2 from data1" << std::endl;
    CollectionSB balls3(balls2);

    std::cout << "Cpoy assignment balls2 to balls3" << std::endl;
    std::cout << "Print balls2" << balls3 << std::endl;

    sort_by_size(balls3, Sort_choice::bubble_sort);
    std::cout << "Bubble Sort balls 3" << balls3 << std::endl;

    std::cout << "Print balls3" << balls2 << std::endl;

    sort_by_size(balls2, Sort_choice::insertion_sort);
    std::cout << "Insertion Sort balls2" << balls2 << std::endl;

    in.open("stress_ball2.data");

    Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes> balls4;

    in >> balls4;

    in.close();

    std::cout << "Load balls 4 from data2" << std::endl;

    std::cout << balls4 << std::endl;
    sort_by_size(balls4, Sort_choice::selection_sort);
    std::cout << "Selection Sort balls4" << balls4 << std::endl;

    Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes> balls5;

    balls5 = make_union(balls2, balls4);

    std::cout << "Merge balls2 and balls4" << std::endl;

    std::ofstream out;
    out.open("stress_ball3.data");

    std::cout << "Store balls5 to data3" << balls5 << std::endl;

    out << balls5;
    out.close();

    swap(balls5, balls4);

    std::cout << "Swap balls5 and 4, balls 5 should now be shorter" << balls5 << std::endl
              << balls4
              << std::endl;
}
/*
JEANS TESTER SECTION
-
-
-
-
-
-
*/
void test_jeans()
{
    Collection<Jeans, Jeans_colors, Jeans_sizes> jeans1;

    jeans1.insert_item(Jeans());
    jeans1.insert_item(Jeans());
    jeans1.insert_item(Jeans());
    jeans1.insert_item(Jeans());
    jeans1.insert_item(Jeans());
    jeans1.insert_item(Jeans());
    jeans1.insert_item(Jeans());
    jeans1.insert_item(Jeans());
    jeans1.insert_item(Jeans());
    jeans1.insert_item(Jeans());

    Collection<Jeans, Jeans_colors, Jeans_sizes> jeans2;

    jeans2.insert_item(Jeans());
    jeans2.insert_item(Jeans());
    jeans2.insert_item(Jeans());
    jeans2.insert_item(Jeans());
    jeans2.insert_item(Jeans());
    jeans2.insert_item(Jeans());
    jeans2.insert_item(Jeans());
    jeans2.insert_item(Jeans());
    jeans2.insert_item(Jeans());
    jeans2.insert_item(Jeans());

    std::cout << "Print jeans1:\n"
              << jeans1 << std::endl;
    std::cout << "Print jeans2:\n"
              << jeans2 << std::endl;

    swap(jeans1, jeans2);
    std::cout << "Swap Jeans 1 and 2\n"
              << std::endl;

    Collection<Jeans, Jeans_colors, Jeans_sizes> jeans3;
    std::cout << "Merge Jeans 1 and 2 into 3" << std::endl;

    jeans3 = make_union(jeans1, jeans2);
    std::cout << '1' << std::endl;
    std::cout << "Print jeans3:\n"
              << jeans3 << std::endl;

    std::cout << "Sort all the Jeans:\n\n";
    sort_by_size(jeans1, Sort_choice::bubble_sort);
    sort_by_size(jeans2, Sort_choice::insertion_sort);
    sort_by_size(jeans3, Sort_choice::selection_sort);

    std::cout << "Print All jeans:\n"
              << "Jeans1:\n\n"
              << jeans1
              << "\n\nJeans2:\n\n"
              << jeans2
              << "\n\nJeans3:\n\n"
              << jeans3;
}
int main()
{
    int answer;
    cout << "What version to test: stress_ball (=0) or jeans (=1): ";
    cin >> answer;
    if (answer == 0)
        test_stress_balls();
    else if (answer == 1)
        test_jeans();
    else
        cout << "Wrong value: " << answer << endl;
    return 0;
}