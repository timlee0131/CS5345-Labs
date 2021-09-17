#ifndef PP_SINGLETON_H
#define PP_SINGLETON_H

#include "file_io.h"
#include "parse_process.h"

class pp_singleton: public parse_process {
private:
    static pp_singleton* pp;
    file_io* interface;
    pp_singleton(char*);
    std::ofstream output;
public:
    static pp_singleton* pp_instance(char*);
    file_io* return_interface();

    void set_object(char*);
    void output_file(std::vector<tsp_node>, int, double);
};

#endif