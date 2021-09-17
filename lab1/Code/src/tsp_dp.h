#ifndef TSP_DP_H
#define TSP_DP_H

/*
    Citation in the dynamic programming approach to TSP
    https://github.com/williamfiset/Algorithms
*/

#include "tsp_interface.h"
// #include "file_io.h"
#include "pp_singleton.h"
#include "tsp_node.h"

#include <vector>
#include <map>
#include <iostream>
#include <cmath>

class tsp_dp: public tsp_interface {
private:
    std::vector<tsp_node> tsp_list;
    std::vector<tsp_node> solution_list_dp;

    int size;   //number of elements in 
    int N, start;
    double** distance;
    double** memo;
    std::vector<int> tour;

    double min_tour_cost = 9999999;
    bool ran_solver = false;
    pp_singleton* p;
    double exe_time;
public:
    //Constructor
    tsp_dp(char*);
    
    //Pure virtual implementations
    virtual void run_tsp();
    virtual void display();

    //DP functions
    void fill_distance();
    static bool not_in(int, int);

    std::vector<int> combinations(int, int);
    void combinations(int, int, int, int, std::vector<int>);

    void solve_dp(int);
    void multi_run_engine(int);
    void dp_solution_helper();

    //Utility functions
    double euclidian_distance();
    double euclidian_distance(tsp_node, tsp_node);
    void display_dp();
    void output();
};

#endif