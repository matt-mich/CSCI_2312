//
// Created by Doctor on 4/24/2023.
//

#ifndef DYNAMICARRAYS_DYNAMIC_H
#define DYNAMICARRAYS_DYNAMIC_H

#include <iostream>

template<typename T>
struct linked_list{
    T value;
    linked_list<T>* ptr;
};

template<typename T> class dynamic {
    protected:
        T *start_pointer;
        int arr_size;
    //    virtual void readFromStream(std::ifstream &file_stream);
    public:
        dynamic();    // Constructor
        // dynamic_array(dynamic_array const &old_arr);    // Constructor
        virtual T push(T value) = 0;
//        virtual T pop() = 0;
    //    void getUserInput();
    //    void getInputFromFile(std::string filename,int mode);
    //    void outputArrayToFile(std::string filename);
        void print();
        virtual T& operator[](int index) = 0;
};




#endif //DYNAMICARRAYS_DYNAMIC_H
