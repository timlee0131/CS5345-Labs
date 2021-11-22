#include <iostream>
#include <string>
#include <chrono>

#include <emscripten/websocket.h>

#include "SortAlgorithm.h"

#include "json.h"
using namespace nlohmann;

// emcc -lwebsocket.js
// -lwebsocket.js is necessary to use websockets
// should output to HTML since Node (by default) does not support WebSockets

// example run command: emcc -lwebsocket.js -o index.html main.cpp

//this does not create a server, only clients

EM_BOOL WebSocketOpen(int eventType, const EmscriptenWebSocketOpenEvent* e, void* userData) {
    //If we open the socket, this tells us what we got- 
    //equivalent to socket.addEventListener('open)...
    std::cout << "Open(eventType: " << 
        eventType << ", userData: " << int(userData) << std::endl;
    std::cout << "Connected to Server." << std::endl;
    return 0;
}

EM_BOOL WebSocketClose(int eventType, const EmscriptenWebSocketCloseEvent* e, void* userData) {
    //the websocket close event e has wasClean, code, reason, and user data
    std::cout << "Close(eventType: " << eventType << ", wasClean: " <<
        e->wasClean << ", code: " << e->code << ", reason: " << e->reason <<
        ", userData: " << int(userData) << std::endl;
    std::cout << "Connection to Server Closed." << std::endl;
    return 0;
}

EM_BOOL WebSocketError(int eventType, const EmscriptenWebSocketErrorEvent* e, void* userData) {
    std::cout << "Error - eventType: " << 
        eventType << ", userData: " << int(userData) << std::endl;
    return 0;
}

EM_BOOL WebSocketMessage(int eventType, const EmscriptenWebSocketMessageEvent* e, void* userData) {
    std::cout << "Message - eventType: " << eventType <<
        ", Number of Bytes: " << e->numBytes << ", isText: " << e->isText << 
        ", userData: " << int(userData) << std::endl;

        //once we get a message, we need to know what to do with it
    if (e->isText) {
        auto msg = json::parse(e->data);

        //accessing is done like vectors
        //get = return it as the type you want- in this case, we want to get "data"
        //as a string object
        // std::cout << msg["data"].get<std::vector<int> >() << std::endl;
        std::vector<int> incomingVector = msg["data"].get<std::vector<int> >();
        
        SortAlgorithm sa;

        if(msg["method"] == "bubble") {
            auto start_time = std::chrono::high_resolution_clock::now();
            sa.bubble_sort(incomingVector);
            auto end_time = std::chrono::high_resolution_clock::now();

            msg["timing"] = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
        } else if(msg["method"] == "merge") {
            auto start_time = std::chrono::high_resolution_clock::now();
            sa.merge_sort1(incomingVector);
            auto end_time = std::chrono::high_resolution_clock::now();

            msg["timing"] = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
        } else if(msg["method"] == "insertion") {
            auto start_time = std::chrono::high_resolution_clock::now();
            sa.insertion_sort(incomingVector);
            auto end_time = std::chrono::high_resolution_clock::now();

            msg["timing"] = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
        }

        bool flagIsSorted = true;
        for(int i = 0; i < incomingVector.size() - 1; i++) {
            if(incomingVector.at(i) > incomingVector.at(i + 1))
                flagIsSorted = false;
        }
        if(flagIsSorted)
            msg["type"] = "list_sorted";
        else
            msg["type"] = "list_failedsort";

        json j_vec(incomingVector);
        msg["data"] = incomingVector;

        // std::string output = msg.dump();

        // std::cout << "Sending: " << output << std::endl;
        std::cout << "executing sorting method: " << msg["method"] << std::endl;
        std::cout << "sending updated data back to server..." << std::endl;

        //if we get a message, we want to send it right back
        //show the de-serialized portion of it with msg.dump() --> send it as a char array
        //with c_str()
        emscripten_websocket_send_utf8_text(e->socket, msg.dump().c_str()); 
        // emscripten_websocket_send_utf8_text(e->socket, incomingVector);
    }
    return 0;
}

//creating main to use these

int main() {
    srand(time(NULL));
    if(!emscripten_websocket_is_supported()) {
        std::cout << "WebSockets are not Supported, can not continue." << std::endl;
        exit(1);
    }
    
    //initialize attributes for the web socket
    EmscriptenWebSocketCreateAttributes attr;
    emscripten_websocket_init_create_attributes(&attr);


    //creat the web socket's attributes
    const char* url = "ws://localhost:8080/";
    attr.url = url;
    attr.protocols = "client"; //these are user defined protocols
    //this could even be used for room #'s
    attr.createOnMainThread = false;

    //create the web socket itself
    EMSCRIPTEN_WEBSOCKET_T socket = emscripten_websocket_new(&attr);

    //test if it was actually created- it returns negative on failure- so we cast this as
    //a "result" object and check from there
    if (socket < 0) {
        std::cout << "Socket creation failed, ERROR Code: " << 
            (EMSCRIPTEN_RESULT) socket << std::endl;
        exit(1);

    }

    emscripten_websocket_set_onopen_callback(socket, (void*)1, WebSocketOpen);
    emscripten_websocket_set_onclose_callback(socket, (void*)2, WebSocketClose);
    emscripten_websocket_set_onerror_callback(socket, (void*)3, WebSocketError);
    emscripten_websocket_set_onmessage_callback(socket, (void*)4, WebSocketMessage);


}