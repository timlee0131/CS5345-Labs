#ifndef FILE_IO_H
#define FILE_IO_H

#include <vector>
#include <fstream>
#include "tsp_node.h"

class file_io {
public:
    virtual void load(char*) = 0;
    virtual void output(std::ofstream&, std::vector<tsp_node>, int, double) = 0;
    virtual std::vector<tsp_node> return_it() = 0;
};

#endif