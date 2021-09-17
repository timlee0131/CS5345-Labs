#include "tsp_dp.h"

const int DIST_MAX = 9999999;

tsp_dp::tsp_dp(char* input) {
    p = pp_singleton::pp_instance(input);
    tsp_list = p ->return_interface() ->return_it();

    size = tsp_list.size();

    N = size;

    fill_distance();

    //Un-comment this block to print the euclidean weight distribution matrix.

    // for(int i = 0; i < size; i++) {
    //     for(int j = 0; j < size; j++) {
    //         std::cout << distance[i][j] << "\t";
    //     }   std::cout << std::endl;
    // }
}

void tsp_dp::multi_run_engine(int size) {
    auto start_time = std::chrono::high_resolution_clock::now();
    solve_dp(size);
    auto end_time = std::chrono::high_resolution_clock::now();
    std::cout << "Execution time for Held-Karp TSP with size " << size << " : " << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    std::cout  << " microseconds."<< std::endl;

    exe_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

    dp_solution_helper();
}
 
void tsp_dp::run_tsp() {
    auto start_time = std::chrono::high_resolution_clock::now();
    solve_dp(size);
    auto end_time = std::chrono::high_resolution_clock::now();
    std::cout << "Execution time for Held-Karp TSP with size " << size << " : " << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    std::cout  << " microseconds."<< std::endl;

    exe_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

    dp_solution_helper();
    // output();
}

double tsp_dp::euclidian_distance(tsp_node node1, tsp_node node2) {
    return sqrt(pow(node2.get_X() - node1.get_X(), 2)+ pow(node2.get_Y() - node1.get_Y(), 2) + pow(node2.get_Z() - node1.get_Z(), 2));
}   //This euclidian_distance function is used for the DP TSP

void tsp_dp::fill_distance() {
    //This function populates the weight distribution matrix with 3D euclidean coordinates
    distance = new double*[size];
    for(int i = 0; i < size; i++) {
        distance[i] = new double[size];
    }   //Declaring space for distance[][]

    memo = new double*[size];
    for(int i = 0; i < size; i++) {
        memo[i] = new double[1 << N];
    }   //Declaring space for distance[][]

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            distance[i][j] = euclidian_distance(tsp_list[i], tsp_list[j]);  //fill distance matrix with euclidian weights
        }
    }
}

bool tsp_dp::not_in(int elem, int subset) {
    return ((1 << elem) & subset) == 0;
}

std::vector<int> tsp_dp::combinations(int r, int n) {
    std::vector<int> subsets;
    combinations(0,0,r,n,subsets);
    return subsets;
}

void tsp_dp::combinations(int set, int at, int r, int n, std::vector<int> subsets) {
    int elements_left = n - at;
    if(elements_left < r)   return;

    if(r == 0) {
        subsets.push_back(set);
    } else {
        for(int i = at; i < n; i++) {
            set ^= (1 << i);

            combinations(set, i + 1, r - 1, n, subsets);

            //Backtrack
            set ^= (1 << i);
        }
    }
}

void tsp_dp::solve_dp(int variable_size) {
    if(ran_solver)  return;

    int END_STATE = (1 << variable_size) - 1;
    //double memo[N][1 << N];
    for(int end = 0; end < variable_size; end++) {
        if(end == start)    continue;
        memo[end][(1 << start) | (1 << end)] = distance[start][end];
    }   //end for
    for(int r = 3; r <= variable_size; r++) {
        for(int subset : combinations(r, variable_size)) {
            if(not_in(start, subset))   continue;
            for(int next = 0; next < variable_size; next++) {
                if(next == start || not_in(next, subset))   continue;
                int subset_without_next = subset ^ (1 << next);
                double min_dist = 9999999999;
                for(int end = 0; end < variable_size; end++) {
                    if(end == start || end == next || not_in(end, subset))  continue;
                    double new_dist = memo[end][subset_without_next] + distance[end][next];
                }   //end for for end variable
                memo[next][subset] = min_dist;
            }       //end inner for
        }           //end iterator subsets
    }               //end wrapping for

    for(int i = 0; i < variable_size; i++) {
        if(i == start)  continue;
        double tour_cost = memo[i][END_STATE] + distance[i][start];
        if(tour_cost < min_tour_cost)
            min_tour_cost = tour_cost;
    }

    int last_index = start;
    int state = END_STATE;
    tour.push_back(start);
    //Reconstructing path 
    for(int i = 1; i < variable_size; i++) {
        int index = -1;
        for(int j = 0; j < variable_size; j++) {
            if(j == start || not_in(j , state))     continue;
            if(index == -1)                         index = j;
            double prevDist = memo[index][state] + distance[index][last_index];
            double newDist = memo[j][state] + distance[j][last_index];
            if(newDist < prevDist)                  index = j;

        }   //end for
        tour.push_back(index);
        state = state ^ (1 << index);
        last_index = index;
    }   //end wrapping for
    tour.push_back(start);
    ran_solver = true;
}

void tsp_dp::dp_solution_helper() {
    for(int i = 0; i < tour.size(); i++) {
        solution_list_dp.push_back(tsp_list[tour[i]]);
    }
}

void tsp_dp::display() {
    display_dp();
}

void tsp_dp::display_dp() {
    std::cout << "DP:";
    for(int i = 0; i < solution_list_dp.size(); i++) {
        if(i != solution_list_dp.size() - 1)
            std::cout << solution_list_dp[i].get_nodeID() << " -> ";
        else
            std::cout << solution_list_dp[i].get_nodeID() << std::endl;
    }
}

void tsp_dp::output() {
    p -> output_file(solution_list_dp, 0, exe_time);
}

