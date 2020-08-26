#include <iostream>
#include <cstdlib>
#include <string>
#include "Jeans.h"

/*  Jeans default constructer that randomizes the jean with rand and uses a switch
	case to assign the random enum data to the color and to the size
*/
Jeans::Jeans()
{
    int c = rand() % 4;
    int s = rand() % 3;

    switch (c)
    {
    case 0:
        color = Jeans_colors::red;
        break;
    case 1:
        color = Jeans_colors::blue;
        break;
    case 2:
        color = Jeans_colors::yellow;
        break;
    case 3:
        color = Jeans_colors::green;
        break;
    }
    switch (s)
    {
    case 0:
        size = Jeans_sizes::small;
        break;
    case 1:
        size = Jeans_sizes::medium;
        break;
    case 2:
        size = Jeans_sizes::large;
        break;
    }
}
/* Second constructer for assigning a specific color and size

*/
Jeans::Jeans(Jeans_colors c, Jeans_sizes s)
{
    color = c;
    size = s;
}
/* returns the color

*/
Jeans_colors Jeans::get_color() const
{
    return color;
}
/*returns the size

*/
Jeans_sizes Jeans::get_size() const
{
    return size;
}
/* compares this current jean with the jean right of the == operator

*/
bool Jeans::operator==(const Jeans &sb) // this operator is only compared with another jean
{
    return this->get_color() == sb.get_color() && this->get_size() == sb.get_size();
}
bool Jeans::operator<(const Jeans &sb)
{
    return this->get_size() < sb.get_size();
}
/*  reassigns the shift of the color and size
	without this the code would display 0 and 1
*/
std::ostream &operator<<(std::ostream &o, const Jeans &sb)
{
    std::string ocolor = "";
    std::string osize = "";

    if (sb.get_color() == Jeans_colors::red)
    {
        ocolor = "red";
    }
    if (sb.get_color() == Jeans_colors::blue)
    {
        ocolor = "blue";
    }
    if (sb.get_color() == Jeans_colors::yellow)
    {
        ocolor = "yellow";
    }
    if (sb.get_color() == Jeans_colors::green)
    {
        ocolor = "green";
    }
    if (sb.get_size() == Jeans_sizes::small)
    {
        osize = "small";
    }
    if (sb.get_size() == Jeans_sizes::medium)
    {
        osize = "medium";
    }
    if (sb.get_size() == Jeans_sizes::large)
    {
        osize = "large";
    }

    o << ocolor << " " << osize << std::endl;
    return o;
}