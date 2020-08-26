//Collection test

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Collection.h"
//#include "time.h"


main()
{
    Collection balls;

    std::cout << "Insert 6 stress balls to balls" << std::endl;
    balls.insert_item(Stress_ball());
    balls.insert_item(Stress_ball());
    balls.insert_item(Stress_ball());
    balls.insert_item(Stress_ball());
    balls.insert_item(Stress_ball());
    balls.insert_item(Stress_ball());
    
    std::cout << "Insert RED MEDIUM" << std::endl;

    Stress_ball test1 = Stress_ball( Stress_ball_colors::red, Stress_ball_sizes::medium);
    
    balls.insert_item(test1);
    
    std::cout << "TEST CONTAINS RED, MEDIUM" << std::endl;
    std::cout << balls.contains(test1) << std::endl;
    std::cout << "Total balls: " << balls.total_items() << std::endl << "Total Red: " <<  balls.total_items(Stress_ball_colors::red) << std::endl << "Total Medium" << balls.total_items(Stress_ball_sizes::medium) << std::endl << std::endl;
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
    if(!in.is_open()) {std::cout << "Could not open file\n\n";}

    Collection balls2;
    in >> balls2;

    in.close();
    std::cout << "Load balls2 from data1" << std::endl;
    Collection balls3 = balls2;

    std::cout << "Cpoy assignment balls2 to balls3" << std::endl;
    std::cout << "Print balls2" << balls3 << std::endl;

    sort_by_size(balls3, Sort_choice::bubble_sort);
    std::cout << "Bubble Sort balls 3" << balls3 << std::endl;

    std::cout << "Print balls3" << balls2 << std::endl;

    sort_by_size(balls2, Sort_choice::insertion_sort);
    std::cout << "Insertion Sort balls2" <<  balls2 << std::endl;

    in.open("stress_ball2.data");

    Collection balls4;

    in >> balls4;

    in.close();

    std::cout << "Load balls 4 from data2" << std::endl;

    std::cout << balls4 << std::endl;
    sort_by_size(balls4, Sort_choice::selection_sort);
    std::cout << "Selection Sort balls4" << balls4 << std::endl;

    Collection balls5;
    
    balls5 = make_union(balls2, balls4);

    std::cout << "Merge balls2 and balls4" << std::endl;
    
    std::ofstream out;
    out.open("stress_ball3.data");
    
    std::cout << "Store balls5 to data3" << balls5 << std::endl;

    out << balls5;
    out.close();

    swap(balls5, balls4);

    std::cout << "Swap balls5 and 4, balls 5 should now be shorter" << balls5 << std::endl << balls4;


}