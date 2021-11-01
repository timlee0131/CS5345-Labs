#include "SortAlgorithm.h"

std::vector<int>& SortAlgorithm::mthread_insertion_sort(std::vector<int>& vec) {
    std::size_t const middleSize = vec.size() / 2;

    std::vector<int> vecLow(vec.begin(), vec.begin() + middleSize);

    // std::cout << "low vec" << std::endl;
    // for(int i = 0; i < vecLow.size(); i++) {
    //     std::cout << vecLow[i] << ", ";
    // }   std::cout << std::endl;

    std::vector<int> vecHigh(vec.begin() + middleSize, vec.end());

    // std::cout << "high vec" << std::endl;
    // for(int i = 0; i < vecHigh.size(); i++) {
    //     std::cout << vecHigh[i] << ", ";
    // }   std::cout << std::endl;

    // std::cout << std::endl;

    std::thread t1([this, &vecLow]() {this -> insertion_sort(vecLow);});
    std::thread t2([this, &vecHigh]() {this ->insertion_sort(vecHigh);});
    
    t1.join();
    t2.join();

    vec.clear();

    std::merge(vecLow.begin(), vecLow.end(), vecHigh.begin(), vecHigh.end(), std::back_inserter(vec));

    return vec;
}

std::vector<int>& SortAlgorithm::mthread_bubble_sort(std::vector<int>& vec) {
    std::size_t const middleSize = vec.size() / 2;

    std::vector<int> vecLow(vec.begin(), vec.begin() + middleSize);

    // std::cout << "low vec" << std::endl;
    // for(int i = 0; i < vecLow.size(); i++) {
    //     std::cout << vecLow[i] << ", ";
    // }   std::cout << std::endl;

    std::vector<int> vecHigh(vec.begin() + middleSize, vec.end());

    // std::cout << "high vec" << std::endl;
    // for(int i = 0; i < vecHigh.size(); i++) {
    //     std::cout << vecHigh[i] << ", ";
    // }   std::cout << std::endl;

    // std::cout << std::endl;

    std::thread t1([this, &vecLow]() {this -> bubble_sort(vecLow);});
    std::thread t2([this, &vecHigh]() {this ->bubble_sort(vecHigh);});
    
    t1.join();
    t2.join();

    vec.clear();

    std::merge(vecLow.begin(), vecLow.end(), vecHigh.begin(), vecHigh.end(), std::back_inserter(vec));

    return vec;
}

std::vector<int>& SortAlgorithm::mthread_merge_sort(std::vector<int>& vec) {
    std::size_t const middleSize = vec.size() / 2;

    std::vector<int> vecLow(vec.begin(), vec.begin() + middleSize);

    // std::cout << "low vec" << std::endl;
    // for(int i = 0; i < vecLow.size(); i++) {
    //     std::cout << vecLow[i] << ", ";
    // }   std::cout << std::endl;

    std::vector<int> vecHigh(vec.begin() + middleSize, vec.end());

    // std::cout << "high vec" << std::endl;
    // for(int i = 0; i < vecHigh.size(); i++) {
    //     std::cout << vecHigh[i] << ", ";
    // }   std::cout << std::endl;

    // std::cout << std::endl;

    std::thread t1([this, &vecLow]() {this -> merge_sort1(vecLow);});
    std::thread t2([this, &vecHigh]() {this ->merge_sort1(vecHigh);});
    
    t1.join();
    t2.join();

    vec.clear();

    std::merge(vecLow.begin(), vecLow.end(), vecHigh.begin(), vecHigh.end(), std::back_inserter(vec));

    return vec;
}

std::vector<int>& SortAlgorithm::bubble_sort(std::vector<int>& vec) {
    for(int i = 0; i < vec.size(); i++) {
        bool swap = false;
        for(int j = 0; j < vec.size() - i - 1; j++) {
            if(vec[j] > vec[j + 1]) {
                //Swap
                int temp;
                temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;

                //set swap flag
                swap = true;
            }//end if
        }//end for
        if(swap == false)   break;//end bubblesort if everything is sorted
    }

    return vec;
}

std::vector<int>& SortAlgorithm::merge_sort1(std::vector<int>& vec) {
    merge_sort(vec, 0, vec.size() - 1);
    return vec;
}

void SortAlgorithm::merge_sort(std::vector<int>& vec, int left, int right) {
    int middle;
    if(left < right) {
        middle = (left + right) / 2;
        merge_sort(vec, left, middle);
        merge_sort(vec, middle + 1, right);
        merge(vec, left, middle, right);
    }
}

void SortAlgorithm::merge(std::vector<int>& vec, int left, int middle, int right) {
    int size_left, size_right;

    size_left = middle - left + 1;
    size_right = right - middle;

    //declare two arrays of size left and right
    int array_left[size_left];
    int array_right[size_right];

    //initializing the separate arrays
    for(int i = 0; i < size_left; i++) {
        array_left[i] = vec[left + i];
    }
    for(int i = 0; i < size_right; i++) {
        array_right[i] = vec[middle + i + 1];
    }

    //Compare, Sort, Merge
    int i = 0;
    int j = 0;
    int k = 0;

    for(k = left; i < size_left && j < size_right; k++) {
        if(array_left[i] < array_right[j])
            vec[k] = array_left[i++];
        else 
            vec[k] = array_right[j++];
    }

    while(i < size_left) {
        vec[k++] = array_left[i++];
    }
    while(j < size_right) {
        vec[k++] = array_right[j++];
    }
}

std::vector<int>& SortAlgorithm::insertion_sort(std::vector<int>& vec) {
    //Insertion sort algorithm returns a vector reference
    for(int i = 1; i <= vec.size() - 1; i++) {
        int temp = vec[i];
        int j = i - 1;
        while(temp < vec[j] && j >= 0) {
            vec[j + 1] = vec[j];
            j--;
        }//nested while loop
        vec[j + 1] = temp;
    }
    return vec;
}