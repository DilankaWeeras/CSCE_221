#include "graph.h"

// to be implemented

/*
Helper function to sort by the top_num then print
Because vector is pass by value the actual node_list will not be changed

Takes input node_list and outputs to terminal the top_sorted list
*/
void topSort_helper(vector<Vertex> a)
{
    bool sorted = false;
    while (!sorted)
    {
        sorted = true;
        for (int i = 0; i < a.size() - 1; i++)
        {
            if (a[i].top_num > a[i + 1].top_num)
            {
                Vertex temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = a[i];
                sorted = false;
            }
        }
    }

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i].label << " ";
    }
    cout << "\n";
}

void Graph::buildGraph(ifstream &input)
{
    while (!input.eof())
    {
        string str;
        getline(input, str);
        stringstream ss(str);

        bool assignV = true;
        list<int> *_edge = nullptr;

        do
        {
            int num;
            ss >> num;

            if (assignV)
            {
                Vertex v(num);
                node_list.push_back(v);
                _edge = new list<int>();
                assignV = false;
            }
            else if (num != -1)
            {
                _edge->push_back(num);
            }
        } while (ss);
        adj_list.push_back(_edge);
    }
    node_list.pop_back();
}

void Graph::displayGraph()
{
    cout << "Display Graph\n";
    ofstream output("output.data");

    for (int i = 0; i < node_list.size(); i++)
    {
        std::cout << node_list[i].label << ": ";
        for (auto it = adj_list[i]->begin(); it != adj_list[i]->end(); it++)
        {
            cout << *it << " ";
        }

        output << node_list[i].label << ": ";
        for (auto it = adj_list[i]->begin(); it != adj_list[i]->end(); it++)
        {
            output << *it << " ";
        }
        cout << "\n";
        output << "\n";
    }
}

void Graph::topological_sort()
{
    queue<Vertex> q;
    int counter = 0;

    //q.empty();
    for (int i = 0; i < node_list.size(); i++)
    {
        if (node_list[i].indegree == 0)
        {
            q.push(node_list[i]);
        }
    }

    while (!q.empty())
    {
        Vertex v = q.front();
        q.pop();
        //cout << v.label;
        node_list[v.label - 1].top_num = ++counter; // Assign next number

        for (auto it = adj_list[v.label -1 ]->begin(); it != adj_list[v.label - 1]->end(); it++)
        {
            if (--node_list[*it - 1].indegree == 0)
            {
                q.push(node_list[*it - 1]);
            }
        }
    }

    //cout << counter;
    if (counter != node_list.size())
    {
        throw "Cycle found exception";
    }
}

void Graph::compute_indegree()
{
    int ind;
    for (int i = 0; i < node_list.size(); i++)
    {
        ind = 0;
        for (int j = 0; j < adj_list.size(); j++)
        {
            for (auto it = adj_list[j]->begin(); it != adj_list[j]->end(); it++)
            {
                if (node_list[i].label == *it)
                {
                    ind++;
                    //cout << "test\t";
                }
            }
        }
        Vertex v(node_list[i].label, ind);
        node_list[i] = v;
    }
    //cout << "\n";
    /*for(int i = 0; i < node_list.size(); i++)
    {
        cout << node_list[i].indegree << "\n";
    }
    */
}

/*
get topological sort position.
output vector ar
*/
void Graph::print_top_sort()
{
    //topSort_helper(node_list);
    vector <int> output(node_list.size());
    for(int i = 0; i < node_list.size(); i++)
    {
        //cout << node_list[i].top_num << endl;
        output[node_list[i].top_num - 1] = node_list[i].label;
    }
    for(int i : output)
    {
        cout << i << " ";
    }
    cout << "\n";
}
