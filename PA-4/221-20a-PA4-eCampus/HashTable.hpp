#pragma once

#include <string>
#include <vector> // vector makes up the first stage of the hash table
#include <list>	  // standard linked list class
#include <iostream>
#include <utility>


template <typename T>
class Node
{
private:
	int key;
	T val;
	friend class Hashtable;

public:
	Node(int k = 0, T v = T()) : key(k), val(v) {}
	int getKey() { return key; }
	T* getVal() { return &val; }
};



template <typename T>
class HashTable
{
private:
	int size;
	//IMPLEMENT
	std::vector<Node<T>> *table;

	int hash(const int _key)
	{
		return _key % size;
	}

public:
	HashTable(const int _size)
	{
		//IMPLEMENT
		size = _size;
		table = new std::vector<Node<T>>[size];
	}

	~HashTable()
	{
		//IMPLEMENT
		delete[] table;
	}

	void insert(const int _key, T _value)
	{
		//IMPLEMENT
		Node<T> newNode(_key, _value);
		table[hash(_key)].push_back(newNode);
	}

	int minChainLen()
	{
		//IMPLEMENT
		//return 0;
		int min = table[0].size();
		
		for (int i = 0; i < size; i++)
		{
			if ((table[i].size() < min))
			{
				min = table[i].size();
			}
		}
		return min;
	}

	int maxChainLen()
	{
		//IMPLEMENT
		//return 0;
		int max = table[0].size();
		
		for (int i = 0; i < size; i++)
		{
			if (!table[i].empty() && (table[i].size() > max))
			{
				max = table[i].size();
			}
		}
		return max;
	}

	double averageChainLen()
	{
		//IMPLEMENT
		//return 0.0;
		double sum = 0;
		for (int i = 0; i < size; i++)
		{
			if (!table[i].empty())
			{
				sum += table[i].size();
			}
		}
		return sum/size;
	}

	T *search(int _key)
	{
		int hashlocation = hash(_key);
		for (int i = 0; i < table[hashlocation].size(); i++)
		{
			if(table[hashlocation].at(i).getKey() == _key)
			{
				return table[hashlocation].at(i).getVal();
			}
		}
		return nullptr;
	}
	void printTable()
	{
		std::cout << "\n\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << i << ")\t";
			for (int j = 0; j < table[i].size(); j++)
			{
				std::cout << " --> " << *table[i].at(j).getVal();
			}
			std::cout << "\n";
		}
	}
};