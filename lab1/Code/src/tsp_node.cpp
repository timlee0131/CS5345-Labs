#include "tsp_node.h"
#include <cmath>

void tsp_node::set_nodeID(int n_id) {
    nodeID = n_id;
} 

void tsp_node::set_X(double x_val) {
    x = x_val;
}

void tsp_node::set_Y(double y_val) {
    y = y_val;
}

void tsp_node::set_Z(double z_val) {
    z = z_val;
}

int tsp_node::get_nodeID() {
    return nodeID;
}

double tsp_node::get_X() {
    return x;
}

double tsp_node::get_Y() {
    return y;
}

double tsp_node::get_Z() {
    return z;
}

double tsp_node::dist(tsp_node& node) {
    //distance = sqrt(pow((x - x2), 2) + pow((y - y2), 2) + pow((z - z2), 2));
    double dist = sqrt(pow((node.x - this -> x), 2) + pow((node.y - this -> y), 2) + pow((node.z - this -> z), 2));

    return dist;
} 