#ifndef TSP_INTERFACE_H
#define TSP_INTERFACE_H

class tsp_interface {
public:
    virtual void run_tsp() = 0;
    virtual void display() = 0;     //Delete later. Replace with output
};

#endif