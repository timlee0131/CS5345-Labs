#ifndef TSP_N_H
#define TSP_N_H

/*
    Citation in the naive approach to TSP
    https://github.com/samlbest/traveling-salesman
*/

#include "tsp_interface.h"
// #include "file_io.h"
#include "pp_singleton.h"
#include "tsp_node.h"

#include <vector>
#include <map>
#include <iostream>
#include <cmath>

class tsp_n: public tsp_interface {
private:
    //Original list for the naive solution
    std::vector<tsp_node> tsp_list;
    std::vector<tsp_node> solution_list;
    int size;   //number of elements in 
    pp_singleton* p;
    double exe_time;
public:
    //Constructor
    tsp_n(char*);
    
    //Pure virtual implementations
    virtual void run_tsp();
    virtual void display();

    //Naive Brute Force functions
    void brute_force_wrap();
    void brute_force(std::vector<tsp_node>& best_path, int min_dist, int nodes_left);
    void rotate(int);
    void setup();
    void copy_list(std::vector<tsp_node>& src_list, std::vector<tsp_node>& dest_list);

    //Utility functions
    double euclidian_distance();
    double euclidian_distance(tsp_node, tsp_node);
    void output();
};

#endif