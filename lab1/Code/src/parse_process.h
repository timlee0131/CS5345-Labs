#ifndef PARSE_PROCESS_H
#define PARSE_PROCESS_H

#include "tsp_node.h"
#include "file_io.h"
#include <vector>

class parse_process: public file_io {
private:
    std::vector<tsp_node> process_list;
public:
    //Pure virtual implementations
    virtual void load(char*);
    virtual void output(std::ofstream&, std::vector<tsp_node>, int, double);

    //Class utility functions
    std::vector<tsp_node> return_it();
};

#endif