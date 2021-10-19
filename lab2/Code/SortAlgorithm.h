#ifndef SORTALGORITHM_H
#define SORTALGORITHM_H

#include <vector>
#include <numeric>
#include <iostream>

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
};

EMSCRIPTEN_BINDINGS(sort_algorithms) {
    emscripten::class_<SortAlgorithm>("SortAlgorithm")
    .constructor<>()
    .function("bubble_sort", &SortAlgorithm::bubble_sort)
    .function("merge_sort1", &SortAlgorithm::merge_sort1)
    .function("insertion_sort", &SortAlgorithm::insertion_sort)
    .function("assignAsVector", &SortAlgorithm::assignAsVector);
}

EMSCRIPTEN_BINDINGS(stl_wrappers) {
    register_vector<int>("vector<int>");
}

#endif