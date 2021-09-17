#include "tsp_n.h"
#include <chrono>

const int DIST_MAX = 9999999;

tsp_n::tsp_n(char* input) {
    p = pp_singleton::pp_instance(input);
    tsp_list = p -> return_interface() -> return_it();

    size = tsp_list.size();
}

void tsp_n::run_tsp() {
    auto start_time = std::chrono::high_resolution_clock::now();
    brute_force_wrap();
    auto end_time = std::chrono::high_resolution_clock::now();
    std::cout << "Execution time for Naive TSP with size " << size << " : " << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    std::cout  << " microseconds."<< std::endl;
    exe_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    output();
}

void tsp_n::setup() {
    int start_index = 0;
    int cities_added = 0;
    int closest = 9999999;
    double total_dist = 0;
    double current_dist = 0.0;
    int closest_index = 0;
    int current_num = size;
    std::vector<tsp_node> temp;

    copy_list(tsp_list, temp);

    solution_list.push_back(tsp_list[start_index]);
    tsp_list.erase(tsp_list.begin() + start_index);
    --current_num;
    ++cities_added;

    while(current_num != 0) {
        closest = 9999999;
        for(int i = 0; i < current_num; i++) {
            current_dist = tsp_list[i].dist(solution_list[cities_added - 1]);
            if(current_dist < closest) {
                closest_index = i;
                closest = current_dist;
            }
        }

        total_dist += closest;
        solution_list.push_back(tsp_list[closest_index]);
        tsp_list.erase(tsp_list.begin() + closest_index);

        --current_num;
        ++cities_added;
    }

    copy_list(temp, tsp_list);
}

//Naive implementation

void tsp_n::brute_force_wrap() {
    int distance = 0;
    int min_dist = DIST_MAX;
    std::vector<tsp_node> best_path;

    setup();

    brute_force(best_path, min_dist, size);
    copy_list(best_path, solution_list);
    solution_list.push_back(best_path[0]);

    return;
}

void tsp_n::brute_force(std::vector<tsp_node>& best_path, int min_dist, int nodes_left) {
    double current_dist = 0;
    for(int i = 0; i < nodes_left; i++) {
        rotate(nodes_left - 1);
        current_dist = euclidian_distance();
        if(current_dist < min_dist) {
            min_dist = current_dist;
            copy_list(solution_list, best_path);
        }
        
        brute_force(best_path, min_dist, nodes_left - 1);
    }

    return;
}  

void tsp_n::rotate(int position) {
    std::rotate(solution_list.begin(), solution_list.begin() + position + 1, solution_list.end());
}

double tsp_n::euclidian_distance() {
    double total_distance = 0.0;
    for(int i = 0; i < size - 1; i++) {
        total_distance += solution_list[i].dist(solution_list[i + 1]);
    }
    total_distance += solution_list[0].dist(solution_list[size - 1]);
    return total_distance;
}   //This euclidian_distance function is used for the naive TSP 

double tsp_n::euclidian_distance(tsp_node node1, tsp_node node2) {
    return sqrt(pow(node2.get_X() - node1.get_X(), 2)+ pow(node2.get_Y() - node1.get_Y(), 2) + pow(node2.get_Z() - node1.get_Z(), 2));
}   //This euclidian_distance function is used for the DP TSP

void tsp_n::copy_list(std::vector<tsp_node>& src_list, std::vector<tsp_node>& dest_list) {
    dest_list.clear();
    for(int i = 0; i < src_list.size(); i++) {
        dest_list.push_back(src_list[i]);
    }
}

void tsp_n::display() {
    std::cout << "NAIVE:";
    for(int i = 0; i < solution_list.size(); i++) {
        if(i != solution_list.size() - 1)
            std::cout << solution_list[i].get_nodeID() << " -> ";
        else
            std::cout << solution_list[i].get_nodeID() << std::endl;
    }
}

void tsp_n::output() {
    p ->output_file(solution_list, 1, exe_time);
}
