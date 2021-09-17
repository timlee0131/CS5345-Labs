#include "pp_singleton.h"
pp_singleton* pp_singleton::pp = nullptr;

pp_singleton::pp_singleton(char* filename) {
    set_object(filename);
}

pp_singleton* pp_singleton::pp_instance(char* filename) {
    if(!pp) pp = new pp_singleton(filename);
    return pp;
}

void pp_singleton::set_object(char* filename) {
    interface = new parse_process();
    interface -> load(filename);

    char* fn = "output.txt";
    output.open(fn);
}

file_io* pp_singleton::return_interface() {
    return interface;
}

void pp_singleton::output_file(std::vector<tsp_node> solution_list_dp, int flag, double exe_time) {
    interface -> output(output, solution_list_dp, flag, exe_time);
}