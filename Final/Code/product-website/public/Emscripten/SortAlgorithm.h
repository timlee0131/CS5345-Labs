#ifndef SORTALGORITHM_H
#define SORTALGORITHM_H

#include <vector>
#include <numeric>
#include <iostream>
#include <thread>
#include <iterator>

#include <emscripten/bind.h>
using namespace emscripten;

class SortAlgorithm {
public:
    std::vector<int>& bubble_sort(std::vector<int>& vec);
    std::vector<int>& merge_sort1(std::vector<int>& vec);
    void merge_sort(std::vector<int>& vec, int left, int right);
    void merge(std::vector<int>& vec, int left, int middle, int right);
    std::vector<int>& insertion_sort(std::vector<int>& vec);

    std::vector<int> assignAsVector() {
        std::vector<int> initVector;
        return initVector;
    }

    // NEW INTERFACE FOR MULTITHREADING
    std::vector<int>& mthread_bubble_sort(std::vector<int>& vec);
    std::vector<int>& mthread_merge_sort(std::vector<int>& vec);
    std::vector<int>& mthread_insertion_sort(std::vector<int>& vec);
};

EMSCRIPTEN_BINDINGS(sort_algorithms) {
    emscripten::class_<SortAlgorithm>("SortAlgorithm")
    .constructor<>()
    .function("mthread_bubble_sort", &SortAlgorithm::mthread_bubble_sort)
    .function("mthread_merge_sort", &SortAlgorithm::mthread_merge_sort)
    .function("mthread_insertion_sort", &SortAlgorithm::mthread_insertion_sort)
    .function("assignAsVector", &SortAlgorithm::assignAsVector);
}

EMSCRIPTEN_BINDINGS(stl_wrappers) {
    register_vector<int>("vector<int>");
}

#endif