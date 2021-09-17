#include "tsp_n.h"
#include "tsp_dp.h"
#include "tsp_interface.h"
#include "tsp_node.h"
#include <vector>
#include <iostream>
//#include "tsp.h"

int main () {
    char* input = const_cast<char*>("datafiles/largePositions.txt");    //When testing against private list of nodes, change this value.
    tsp_interface* k = new tsp_dp(input);
    k -> run_tsp();
    // k -> display();

    // k = new tsp_n(input);
    // k -> run_tsp();
    // k -> display();

    return 0;
}