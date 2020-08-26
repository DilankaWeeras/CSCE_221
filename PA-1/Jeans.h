#ifndef JEANS_H
#define JEANS_H
#include <string>
#include <iostream>

/*
Jeans class has has private datatypes Jeans_colors and Jeans_sizes
Create a Jean with these datatypes, functions to access the stress ball and 
Overloaded operators for == and <<
*/

enum class Jeans_colors { red, blue, yellow, green};
enum class Jeans_sizes  { small, medium, large};

class Jeans
{

    private:

    Jeans_colors color;
    Jeans_sizes size;

    protected:

    public:
    
    //constructor
    Jeans();
    Jeans(Jeans_colors c, Jeans_sizes s);

    //accessors and mutators
    Jeans_colors get_color() const; 
    Jeans_sizes get_size() const;

    // overloaded outputs
    bool operator==(const Jeans& sb);
    bool operator<(const Jeans& sb);

};
std::ostream& operator<<(std::ostream& o, const Jeans& sb);

    

#endif


    



