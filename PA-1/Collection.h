#ifndef COLLECTION_H
#define COLLECTION_H
#include <string>
#include <iostream>
#include <fstream>
#include "Stress_ball.h"

enum class Sort_choice{ bubble_sort, insertion_sort, selection_sort};


class Collection
{

    private:

    Stress_ball *array;
    int size; // logical size of the array
    int capacity; // physical size of the array, must be greater than size
    void resize_array();

    protected:

    public:

    //Constructors

    Collection(); // default constructor
    Collection(int s); // size constructor
    Collection(const Collection &other); // copy constructor
    Collection& operator=(const Collection& sBA); // copy assignment

    ~Collection(); // destructor

    Collection(Collection &&other); // move constructor
    Collection& operator=(Collection &&other); // move assignment

    //mutators and accessors
    void insert_item(const Stress_ball& sb); // inserts a stress ball
    bool contains(const Stress_ball& sb) const; // checks if a stress ball exist in the colleciton
    Stress_ball remove_any_item(); // removes and return a random stress ball
    void remove_this_item(const Stress_ball& sb); // removes a specific stress ball
    void make_empty();
    bool is_empty();
    int total_items() const;
    int total_items(Stress_ball_sizes s) const;
    int total_items(Stress_ball_colors c) const;
    void print_items() const;
    
    Stress_ball& operator[](int i);
    const Stress_ball& operator[](int i) const;

};

std::istream& operator>>(std::istream& is, Collection& c);
std::ostream& operator<<(std::ostream& os, const Collection& c);
Collection make_union(const Collection& c1, const Collection& c2);
void swap(Collection& c1, Collection& c2);
void sort_by_size(Collection& c, Sort_choice sort);




#endif
