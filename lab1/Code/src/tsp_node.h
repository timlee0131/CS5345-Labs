#ifndef TSP_NODE_H
#define TSP_NODE_H

class tsp_node {
private:
    int nodeID;
    double x;
    double y;
    double z;
public:
    void set_nodeID(int);
    void set_X(double);
    void set_Y(double);
    void set_Z(double);

    int get_nodeID();
    double get_X();
    double get_Y();
    double get_Z();

    double dist(tsp_node&);
};

#endif