# API Documentation for the Multithreaded Library #
### Author: Tim Lee ###

---
### How to get Demo Application Started ###
To start a local server with the right headers to allow for `SharedArrayBuffer`, run `server.py` (a python script that spins up a localhost at port 8000) inside `../Code` using the command ***python server.py*** or ***python3 server.py***. Navigate to `../Code/frontend/` and click on `sort.html`. 

### How to Compile ###
To compile using emscripten, `make emcc`

To compile using g++, `make compile`

## API Documentation ##

`Module.SortAlgorithm().mthread_bubble_sort(vector<int>)`<br />
This function from the mthreadSort.js library performs bubble sort on vector of ints. The original native C++ version of the code header is as follows: `std::vector<int>& mthread_bubble_sort(std::vector<int>& vec)`. It takes in a standard vector of ints by reference, performs a bubble sort on that given vector of integers with multithreading on two threads using `std::thread` under the hood, and returns a standard vector of ints.
<br />
<br />

`Module.SortAlgorithm().mthread_insertion_sort(vector<int>` <br />
This function performs an insertion sort on a vector of ints. The original native C++ version of the code header is as follows: `std::vector<int>& mthread_insertion_sort(std::vector<int>& vec)`. It takes a standard vector of ints by reference, performs insertion sort on that given vector of integers with multithreading on two threads using `std::thread` under the hood, and returns a standard vector of ints.
<br />
<br />

`Module.SortAlgorithm().mthread_merge_sort(vector<int>)`<br />
This function performs a merge sort on a vector of ints. The original native C++ version of the code header is as follows: `std::vector<int>& mthread_merge_sort(std::vector<int>& vec)`. It takes a standard vector of ints by reference, performs merge sort on that given vector of integers with multithreading on two threads using `std::thread`, and returns a standard vector of ints. This function in C++ takes in two helper functions `void merge_sort(std::vector<int>& vec, int left, int right)` and `void merge(std::vector<int>& vec, int left, int middle, int right)` in order to perform the said task of performing merge sort. However, since these two helper functions are encapsulated within `merge_sort1()`, they were not exposed as part of the emscripten bindings. 
<br />
<br />

`Module.SortAlgorithm().assignAsVector()` <br />
Since the rest of the exposed functions need std::vector<int> both as parameters and as return calls, it was crucial to allow the library implementation on the javascript side to use std::vector<int>. However, the built-in type conversion offered by embind does not include standard c++ vectors. So in order to be able to use the standard vector, it was necessary to use factory function provided by embind to manually register the standard vector as a valid type (source: https://emscripten.org/docs/porting/connecting_cpp_and_javascript/embind.html). The code below shows the process.
```cpp
EMSCRIPTEN_BINDINGS(stl_wrappers) {
    register_vector<int>("vector<int>");
}
```
The function `assignAsVector(int)` is used to assign the type standard vector of integer to a javascript variable. It takes no inputs and returns a vector of type int.  

## Design Concepts ##
This sorting algorithms library was created using the strategy behavioral design pattern. Using this design pattern, the set of sorting algorithms to be exposed and used as a library were neatly grouped to a single class object to be used. Since all sorting functions to be exposed were performing similar operations with the same set of input and outputs with slight differences, it made sense to employ the strategy pattern. Unlike in many use cases of the strategy pattern, this library only required one family of algorithms in one class. An advantage of this design pattern is that it allows for simplicity in that functions that perform very similar operations are able to be tied to one class object that is instantiated. This allows for all three sorting algorithms to be called from one instance of the object.


With regards to the multithreaded functionality added to each sorting algorithm, two threads were introduced via the `std::thread` library in native C++. The two threads performed simultaneous operations on two subvectors that were the result of splicing the input vector of unsorted integers. After the two subvectors were sorted in parallel using multithreading, they were combined together using `std::merge`, a C++ library that is designed to efficiently sort and merge two sorted vectors. The underlying algorithms for each sorting method were unchanged. Adding the multithreaded capabilites to these sorting algorithms introduced benefits such as the ability to sort parts of the input vector simultaneously and in parallel. One notable downside however, is the fact that introducing multithreading and operating `std::merge` introduced new overheads to the algorithms. 

## High Level Design Overview ##
![image info](../data/data.png)
