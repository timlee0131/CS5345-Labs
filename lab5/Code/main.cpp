// #include <iostream>
// #include <vector>
// #include <stdlib.h>
// #include <chrono>
// #include <time.h>
// #include <stdio.h>
// #include "SortAlgorithm.h"

// int main(int argc, char **argv) {
//     srand(time(NULL));

//     std::vector<int> vec;
//     for(int i = 0; i < 1000; i++) {
//         vec.push_back(rand() % 2000);
//     }

//     SortAlgorithm sort;
    
//     auto start_time = std::chrono::high_resolution_clock::now();
//     sort.mthread_merge_sort(vec);
//     auto end_time = std::chrono::high_resolution_clock::now();
//     std::cout << "merge: " << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " microseconds."<< std::endl;

//     std::random_shuffle(vec.begin(), vec.end());

//     start_time = std::chrono::high_resolution_clock::now();
//     sort.mthread_insertion_sort(vec);
//     end_time = std::chrono::high_resolution_clock::now();
//     std::cout << "insertion: " << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " microseconds."<< std::endl;

//     std::random_shuffle(vec.begin(), vec.end());

//     start_time = std::chrono::high_resolution_clock::now();
//     sort.mthread_bubble_sort(vec);
//     end_time = std::chrono::high_resolution_clock::now();
//     std::cout << "bubble: " << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " microseconds."<< std::endl;

//     return 0;
// } 