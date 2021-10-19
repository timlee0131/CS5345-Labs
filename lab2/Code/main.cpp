#include <iostream>
#include <vector>
#include <stdlib.h>
#include <chrono>
#include <time.h>
#include <stdio.h>
#include "SortAlgorithm.h"

// enum algorithm_type {BUBBLE, MERGE, LAST};

int main(int argc, char **argv) {
    srand(time(NULL));

    std::vector<int> vec;
    for(int i = 0; i < 1000; i++) {
        vec.push_back(rand() % 2000);
    }

    SortAlgorithm sort;
    
    auto start_time = std::chrono::high_resolution_clock::now();
    sort.merge_sort1(vec);
    auto end_time = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " microseconds."<< std::endl;

    std::random_shuffle(vec.begin(), vec.end());

    start_time = std::chrono::high_resolution_clock::now();
    sort.insertion_sort(vec);
    end_time = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " microseconds."<< std::endl;

    std::random_shuffle(vec.begin(), vec.end());

    start_time = std::chrono::high_resolution_clock::now();
    sort.bubble_sort(vec);
    end_time = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " microseconds."<< std::endl;

    return 0;
}