#include <iostream>
#include <cstdlib>
#include <string>
#include "Collection.h"


/*
Defualt constructor
*/
Collection::Collection() //Fin
{
    array = new Stress_ball[1]; // ask TA
    size = 0;
    capacity = 1;
}
/*
Collection constructor with input for size
*/
Collection::Collection(int s) // Fin
{
    array = new Stress_ball[s];
    size = s;
    capacity = s;
}
/*
Collection Assignment Constructor
*/
Collection::Collection(const Collection &other) // needs revision // clear the array then use insert // Deep copy
{
    for(int i = 0; i < other.total_items(); i++)
    {
        Stress_ball sb = Stress_ball(other[i].get_color(),other[i].get_size());
        insert_item(sb);
    }
}
/*
Collection Assignment operator
*/
Collection& Collection::operator=(const Collection& other) // needs revision // clear the array then use insert // Deep copy
{
    for(int i = 0; i < other.total_items(); i++)
    {
        Stress_ball sb = Stress_ball(other[i].get_color(),other[i].get_size());
        insert_item(sb);
    }
    return *this;
}
/*
Collection Destructor
*/
Collection::~Collection()
{
    //if array is a nullptr you cannot call delete on it
    if(array != nullptr)
    {
        delete[] array;
        size = 0;
        capacity = 0;
    }
}
/*
Collection move Constructor
*/
Collection::Collection(Collection &&other)
{
    array = other.array;
    size = other.size;
    capacity = other.capacity;
    other.array = nullptr;
    other.size = 0;
    other.capacity = 0;
}
/*
Collection move operator
*/
Collection& Collection::operator=(Collection &&other)
{
    array = other.array;
    size = other.size;
    capacity = other.capacity;
    other.array = nullptr;
    other.size = 0;
    other.capacity = 0;
    return *this;
}
/*
Insert item adds an additional item to the collection
*/
void Collection::insert_item(const Stress_ball& sb) //Fin
{
    if(capacity == size)
    {
        resize_array();
    }
    array[size] = sb;
    size++;    
}
/*
Contains searches for the item and returns whether or not it is in the collection
*/
bool Collection::contains(const Stress_ball& sb) const //Fin
{
    for(int i = 0; i < size; i++)
    {
        if(array[i] == sb)
        {
            return true;
        }
    }
    return false;
}
/*
Remove item removes a random item
*/
Stress_ball Collection::remove_any_item() // Fin
{
    Stress_ball tempStressBall;
    if(size == 0)
    {
        throw "Collection is empty \n";
    }
    int temp = rand() % size;
    Stress_ball* new_array = new Stress_ball[capacity];
    int count = 0;
    for(int i = 0; i < size; i++)
    {
        if(i != temp)
        {
            new_array[count] = array[i];
            count++;
        }
        else
        {
            tempStressBall = Stress_ball(array[i].get_color(), array[i].get_size());
        }
    }
    delete array;
    array = new_array;
    size--;
    return tempStressBall;
}
/*
Remove this item will remove a specific item if it exists in the collection
*/
void Collection::remove_this_item(const Stress_ball& sb) //Fin
{
    if(size == 0 || !contains(sb))
    {
         std::cerr << "Collection is empty or does not contain this Stress Ball" << '\n';
        return;
    }
    Stress_ball* new_array = new Stress_ball[capacity];
    int count = 0;
    for(int i = 0; i < size; i++)
    {
        if(!(array[i] == sb))
        {
            new_array[count] = array[i];
            count++;
        }
    }
    delete array;
    array = new_array;
    size = count;
}
/*
Empties the collection
*/
void Collection::make_empty() //Fin
{
    Stress_ball* new_array = new Stress_ball[1];
    delete array;
    array = new_array;
    size = 0;
    capacity = 0;
}
/*
Checks if collection is empty
*/
bool Collection::is_empty() //Fin
{
    return size == 0;
}
/*
Returns the size of the collection but not the capacity
*/
int Collection::total_items() const // Fin
{
    return size;
}
/*
Returns the number of a specific stress ball size
*/
int Collection::total_items(Stress_ball_sizes s) const // Fin
{
    int count = 0;
    for(int i = 0; i < size; i++)
    {
        if(array[i].get_size() == s)
        {
            count++;
        }
    }
    return count;
}
/*
Returns the number of a specific stress ball color
*/
int Collection::total_items(Stress_ball_colors c) const // Fin
{
    int count= 0;
    for(int i = 0; i < size; i++)
    {
        if(array[i].get_color() == c)
        {
            count++;
        }
    }
    return count;
}
/*
Prints all the Stress balls in the collection
*/
void Collection::print_items() const // Fin
{
    for(int i = 0; i < size; i++)
    {
        std::cout << array[i] << std::endl; 
    }
    std::cout << std::endl;
}
/*
array accessor of []
*/
Stress_ball& Collection::operator[](int i) // Fin
{
    return array[i];
}
/*
const array accessor of []
*/
const Stress_ball& Collection::operator[](int i) const // Fin
{
    return array[i];
}
// helping functions
void Collection::resize_array() // Fin
{
    if(capacity == 0)
    {
        array = new Stress_ball[5];
        capacity = 5;
        return;
    }
    Stress_ball* new_array = new Stress_ball[capacity*2];
    for(int i = 0; i < capacity; i++)
    {
        new_array[i] = array[i];
    }
    delete array;
    array = new_array;
    capacity = capacity*2;
}


/*
ADDTIONAL FUNCTIONS
*/
/*
in stream takes all stress balls in a file and places into collection
*/
std::istream& operator>>(std::istream& is, Collection& c)
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
/*
prints all the stress balls in a collection to a file
*/
std::ostream& operator<<(std::ostream& os, const Collection& c)
{
    Stress_ball_colors color;
    Stress_ball_sizes size;
    
    for(int i = 0; i < c.total_items(); i++)
    {
        std::string line = "";
        
        color = c[i].get_color();
        size = c[i].get_size();

        switch(color)
        {
            case Stress_ball_colors::red: line = "red "; break;
            case Stress_ball_colors::blue: line = "blue "; break;
            case Stress_ball_colors::yellow: line = "yellow "; break;
            case Stress_ball_colors::green: line = "green "; break;
        }
        switch(size)
        {
            case Stress_ball_sizes::small: line += "small"; break;
            case Stress_ball_sizes::medium: line += "medium"; break;
            case Stress_ball_sizes::large: line += "large"; break;
        }

        os << line << std::endl;
    }
    return os;
}
Collection make_union(const Collection& c1, const Collection& c2)
{
    Collection c3 = c1;
    for(int i = 0; i < c2.total_items(); i++)
    {
        c3.insert_item(c2[i]);
    }
    return c3;
}
void swap(Collection& c1, Collection& c2)
{
    Collection temp = std::move(c1);
    c1 = std::move(c2);
    c2 = std::move(temp);
}
void sort_by_size(Collection& c, Sort_choice sort)
{
    switch(sort)
    {
        case Sort_choice::bubble_sort :
        {
            bool sorted = false;
            while(!sorted)
            {
                sorted = true;
                for(int i = 0; i < c.total_items()-1; i++)
                {
                    if(c[i+1] < c[i])
                    {
                        Stress_ball temp = c[i];
                        c[i] = c[i+1];
                        c[i+1] = temp;
                        sorted = false;
                    }
                }
            }           
            break;
        }

        case Sort_choice::insertion_sort :
        {
            for(int i = 1; i < c.total_items(); i++)
            {
                Stress_ball markS = c[i];
                int j = i;
                while( j > 0 && markS < c[j-1])
                {
                    c[j] = c[j-1];
                    j = j - 1;
                }
                c[j] = markS;
            }
            break;
        }

        case Sort_choice::selection_sort :
        {
            Collection temp;
            while(c.total_items() != 0 )
            {
                Stress_ball smallest = c[0];
                int indexS = 0;
                
                for(int i = 1; i < c.total_items(); i++)
                {
                    if(c[i] < smallest)
                    {
                        smallest = c[i];
                    }
                }
                c.remove_this_item(smallest);
                temp.insert_item(smallest);
            }
            c = std::move(temp); //mov operator
            break;
        }
    }
}
/*
NOTES
-------------

You can swap a removed element until it gets to the end to the point that it is not accessible to the user

*/