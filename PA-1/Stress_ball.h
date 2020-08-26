#ifndef STRESS_BALL_H
#define STRESS_BALL_H
#include <string>
#include <iostream>

/*
Stress ball class has has private datatypes Stress_ball_colors and Stress_ball_size
Create a stress ball with these datatypes, functions to access the stress ball and 
Overloaded operators for == and <<
*/

enum class Stress_ball_colors { red, blue, yellow, green};
enum class Stress_ball_sizes  { small, medium, large};

class Stress_ball 
{

    private:

    Stress_ball_colors color;
    Stress_ball_sizes size;

    protected:

    public:
    
    //constructor
    Stress_ball();
    Stress_ball(Stress_ball_colors c, Stress_ball_sizes s);

    //accessors and mutators
    Stress_ball_colors get_color() const; 
    Stress_ball_sizes get_size() const;

    // overloaded outputs
    bool operator==(const Stress_ball& sb);
    bool operator<(const Stress_ball& sb);

};

std::ostream& operator<<(std::ostream& o, const Stress_ball& sb);

    

#endif


    



