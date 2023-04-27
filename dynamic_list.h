//
// Created by Doctor on 4/25/2023.
//

#ifndef DYNAMICARRAYS_DYNAMIC_LIST_H
#define DYNAMICARRAYS_DYNAMIC_LIST_H

#include "dynamic.h"

template<typename T> class dynamic_list : public dynamic<T>{
    //    void readFromStream(std::ifstream &file_stream);
    private:
        linked_list<T> *start_list_pointer;
    public:
        dynamic_list<T>() : dynamic<T>(){
            this->start_list_pointer = nullptr;
        };
        T push(T value);
        T pop();
        linked_list<T>* getLast();
        linked_list<T>* getNodeAtIndex(int index);
    //    void getUserInput();
    //    void getInputFromFile(std::string filename,int mode);
    //    void outputArrayToFile(std::string filename);
//        void print();

        T& operator[](int index);
        ~dynamic_list(); // Destructor
};


#endif //DYNAMICARRAYS_DYNAMIC_LIST_H
