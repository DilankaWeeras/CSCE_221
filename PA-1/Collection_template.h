#ifndef COLLECTION_TEMPLATE_H
#define COLLECTION_TEMPLATE_H
#include <string>
#include <iostream>
#include <fstream>
#include "Jeans.h"
#include "Stress_ball.h"

//using CollectionJN = Collection<Jeans, Jeans_colors, Jeans_sizes>;
//using CollectionSB = Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes>;

enum class Sort_choice
{
    bubble_sort,
    insertion_sort,
    selection_sort
};

template <typename Obj, typename F1, typename F2>
class Collection
{

private:
    Obj *array;
    int size;     // logical size of the array
    int capacity; // physical size of the array, must be greater than size

    void resize_array() // Resize array capacity * 2
    {
        std::cout << "resize" << std::endl;
        /*
        if (capacity == 0)
        {
            array = new Obj[5];
            capacity = 5;
            return;
        }
        Obj *new_array = new Obj[capacity * 2];
        for (int i = 0; i < capacity; i++)
        {
            new_array[i] = array[i];
        }
        delete array;
        array = new_array;
        capacity = capacity * 2;
        */
        if(capacity == 0) this->capacity = 1;
		else capacity *= 2;
		Obj* new_array = new Obj[capacity];
		for(int i = 0; i < size; ++i)
		{
			new_array[i] = array[i];
		}
		delete []array;
		array = new_array;
    }

protected:
public:
    //Constructors

    Collection() // default constructor
    {
        array = nullptr; // ask TA
        size = 0;
        capacity = 0;
    }
    Collection(int s) // size constructor
    {
        array = new Obj[s];
        size = 0;
        capacity = s;
    }
    Collection(const Collection &other) // copy constructor
    {
        array = new Obj[capacity];
        size = other.size;
		capacity = other.capacity;
		for(int i = 0; i < size; ++i)
		{
			array[i] = other.array[i];
		}
    }
    Collection &operator=(const Collection &other) // copy assignment
    {
        if(this == &other)
		{
			// Save Mem
		}
		else
		{
			if(array != nullptr) {delete []array;}
			size = other.size;
			capacity = other.capacity;
			array = new Obj[capacity];
			for(int i = 0; i < size; ++i)
			{
				array[i] = other.array[i];
			}
		}
        return *this;
    }

    ~Collection() // destructor
    {
        //if array is a nullptr you cannot call delete on it
        if (array != nullptr)
        {
            delete[] array;
            size = 0;
            capacity = 0;
        }
    }

    Collection(Collection &&other) // move constructor
    {
        array = other.array;
        size = other.size;
        capacity = other.capacity;
        other.array = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    Collection &operator=(Collection &&other) // move assignment
    {
        if(this == &other)
		{
			// Save Mem
		}
		else
		{
			if(array != nullptr)
				delete []array;
			array = other.array;
			size = other.size;
			capacity = other.capacity;
			other.array = nullptr;
			other.size = 0;
			other.capacity = 0;
		}
		return *this;
    }

    //mutators and accessors
    void insert_item(const Obj &sb) // inserts a stress ball
    {
        
        if (capacity == size)
        {
            //std::cout << "HI" << std::endl;
            this->resize_array();
        }
        //std::cout << capacity << std::endl;
        array[size] = sb;
        //std::cout << "and" << std::endl;
        size++;
    }
    bool contains(const Obj &sb) const // checks if a stress ball exist in the colleciton
    {
        for (int i = 0; i < size; i++)
        {
            if (array[i] == sb)
            {
                return true;
            }
        }
        return false;
    }
    Obj remove_any_item() // removes and return a random stress ball or Jean
    {
        Obj tempObject;
        if (size == 0)
        {
            throw "Collection is empty \n";
        }
        int temp = rand() % size;
        Obj *new_array = new Obj[capacity];
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (i != temp)
            {
                new_array[count] = array[i];
                count++;
            }
            else
            {
                tempObject = Obj(array[i].get_color(), array[i].get_size());
            }
        }
        delete array;
        array = new_array;
        size--;
        return tempObject;
    }
    void remove_this_item(const Obj &sb) // removes a specific stress ball
    {
        if (size == 0 || !contains(sb))
        {
            std::cerr << "Collection is empty or does not contain this Stress Ball" << '\n';
            return;
        }
        Obj *new_array = new Obj[capacity];
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (!(array[i] == sb))
            {
                new_array[count] = array[i];
                count++;
            }
        }
        delete array;
        array = new_array;
        size--;
    }
    void make_empty()
    {
        Obj *new_array = nullptr;
        delete array;
        array = new_array;
        size = 0;
        capacity = 0;
    }
    bool is_empty()
    {
        return size == 0;
    }
    int total_items() const
    {
        return size;
    }
    int total_items(F1 c) const
    {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (array[i].get_color() == c) // error here
            {
                count++;
            }
        }
        return count;
    }
    int total_items(F2 s) const
    {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (array[i].get_size() == s) // error here
            {
                count++;
            }
        }
        return count;
    }
    void print_items() const
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << array[i] << std::endl;
        }
        std::cout << std::endl;
    }
    Obj &operator[](int i)
    {
        return array[i];
    }
    const Obj &operator[](int i) const
    {
        return array[i];
    }
};
/*
END OF CLASS
BEGIN ADDTIONAL FUNCTIONS OUTSIDE OF CLASS
*/
template <typename Obj, typename F1, typename F2>
std::ostream &operator<<(std::ostream &os, const Collection<Obj, F1, F2> &c)
{
    for (int i = 0; i < c.total_items(); i++)
    {
        os << c[i] << std::endl;
    }
    return os;
}
template <typename Obj, typename F1, typename F2>
Collection<Obj, F1, F2> make_union(const Collection<Obj, F1, F2> &c1, const Collection<Obj, F1, F2> &c2)
{
    std::cout << "2" << std::endl;

    Collection<Obj, F1, F2> c3(c1);
    std::cout << c3.total_items() << std::endl;
    for (int i = 0; i < c2.total_items(); i++)
    {
        std::cout << i << std::endl;
        c3.insert_item(c2[i]);
    }
    return c3;
}
template <typename Obj, typename F1, typename F2>
void swap(Collection<Obj, F1, F2> &c1, Collection<Obj, F1, F2> &c2)
{
    Collection<Obj, F1, F2> temp = std::move(c1);
    c1 = std::move(c2);
    c2 = std::move(temp);
}
template <typename Obj, typename F1, typename F2>
void sort_by_size(Collection<Obj, F1, F2> &c, Sort_choice sort)
{
    switch (sort)
    {
    case Sort_choice::bubble_sort:
    {
        bool sorted = false;
        while (!sorted)
        {
            sorted = true;
            for (int i = 0; i < c.total_items() - 1; i++)
            {
                if (c[i + 1] < c[i])
                {
                    Obj temp = c[i];
                    c[i] = c[i + 1];
                    c[i + 1] = temp;
                    sorted = false;
                }
            }
        }
        break;
    }

    case Sort_choice::insertion_sort:
    {
        for (int i = 1; i < c.total_items(); i++)
        {
            Obj markS = c[i];
            int j = i;
            while (j > 0 && markS < c[j - 1])
            {
                c[j] = c[j - 1];
                j = j - 1;
            }
            c[j] = markS;
        }
        break;
    }

    case Sort_choice::selection_sort:
    {
        Collection<Obj, F1, F2> temp;
        while (c.total_items() != 0)
        {
            Obj smallest = c[0];
            int indexS = 0;

            for (int i = 1; i < c.total_items(); i++)
            {
                if (c[i] < smallest)
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

#endif
