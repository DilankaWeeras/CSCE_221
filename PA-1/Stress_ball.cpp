#include <iostream>
#include <cstdlib>
#include <string>
#include "Stress_ball.h"

/*  Stress_ball default constructer that randomizes the stress ball with rand and uses a switch
	case to assign the random enum data to the color and to the size
*/
Stress_ball::Stress_ball()
{
    int c = rand() % 4;
    int s = rand() % 3;

    switch(c)
    {
        case 0:
            color = Stress_ball_colors::red;
            break;
        case 1:
            color = Stress_ball_colors::blue;
            break;
        case 2:
            color = Stress_ball_colors::yellow;
            break;
        case 3:
            color = Stress_ball_colors::green;
            break;
    }
    switch(s)
    {
        case 0:
            size = Stress_ball_sizes::small;
            break;
        case 1:
            size = Stress_ball_sizes::medium;
            break;
        case 2:
            size = Stress_ball_sizes::large;
            break;
    }
}
/* Second constructer for assigning a specific color and size

*/
Stress_ball::Stress_ball(Stress_ball_colors c, Stress_ball_sizes s)
{
    color = c;
    size = s;
}
/* returns the color

*/
Stress_ball_colors Stress_ball::get_color() const
{
    return color;
}
/*returns the size

*/
Stress_ball_sizes Stress_ball::get_size() const
{
    return size;
}
/* compares this current stress ball with the stress ball right of the == operator

*/
bool Stress_ball::operator==(const Stress_ball& sb) // this operator is only compared with another stress ball
{
    return this->get_color() == sb.get_color() && this->get_size() == sb.get_size();
}
bool Stress_ball::operator<(const Stress_ball& sb)
{
    return this->get_size() < sb.get_size();
}
/*  reassigns the shift of the color and size
	without this the code would display 0 and 1
*/
std::ostream& operator<<(std::ostream& o, const Stress_ball& sb)
{
    std::string ocolor = "";
    std::string osize = "";

    if(sb.get_color() == Stress_ball_colors::red)
    {
        ocolor = "red";
    }
    if(sb.get_color() == Stress_ball_colors::blue)
    {
        ocolor = "blue";
    }
    if(sb.get_color() == Stress_ball_colors::yellow)
    {
        ocolor = "yellow";
    }
    if(sb.get_color() == Stress_ball_colors::green)
    {
        ocolor = "green";
    }
    if(sb.get_size() == Stress_ball_sizes::small)
    {
        osize = "small";
    }
    if(sb.get_size() == Stress_ball_sizes::medium)
    {
        osize = "medium";
    }
    if(sb.get_size() == Stress_ball_sizes::large)
    {
        osize = "large";
    }


    
    
    o << ocolor << " " << osize << std::endl;
    return o;
}