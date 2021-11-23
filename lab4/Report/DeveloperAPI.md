# Developer API and Documentation #
### Author: Tim Lee ###

## Set Up ##
**Server Side**: navigate to `/Code` and run `node server.js`. This opens a connection on port 8080.

**Client Side**: navigate to `/Code` and run `python3 -m http.server` on a port other than 8080. Then navigate to sort.html. The client should automatically connect to port 8080 with web sockets.

## Apllication Flow ##
On connection to server (server.js), server sends 3 packages each containing an unsorted list to the client (originally written in C++, transpiled using emscripten). The client then learns relevant information regarding the packages using the parameters set in each package and sorts the unsorted lists. Using nlohmann's json API, the javascript list is converted to `std::vector` and sorted using C++ functions that take in `std::vector` as input and return `std::vector`. Once sorted and converted back to a javascript list, the package (now containing sorted list) is sent back to the server with relevant information embedded inside the package object. Once all 3 packages have been handled appropriately and sent back to the server, an iteration of web socket communication is concluded.

Each package contains 5 parameters: `type`, `data`, `method`, `timing`, and `js_timing`.

`type` whose value at this point is `list_unsorted` signifies the type of data that is being handled. When sorting is complete at the client and validation is done to ensure that it is sorted, the `type` parameter is given the value `list_sorted` at which point the package itself is sent back to the server. 

`data` is a list of integers. Originally unsorted and randomized, it is the target variable for the client whose job it is to sort `data` using various sorting algorithms. Once `data` is sorted at client, it is validated to ensure the correctness of the sort and sent back to server with an updated `type` field as mentioned above. 

`method` field is set at server and tells to the client which sorting method to employ for that particular package. The `method` field can take on 3 values: bubble, merge, or insertion. On client-side, the `method` field is used on a series of if-statements to correctly sort the corresponding `data` with the correct sorting method as set by the server. 

`timing` is field created on client-side and records the timing in microseconds of a particular sorting operation done on that package using `std::chrono`. This value is set to `timing` and sent back to the server where it is displayed. 

`js_timing` represents the timing performance of the entire web socket operation for a given package. It records time elapsed between sending a package with unsorted list from server to receiving the sorted list from client, again at the server. This operation uses javascript's `performance.now` API and is originally calculated in milliseconds.

## High Level Architecture ##
![image info](../data/uml.png)