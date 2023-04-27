
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "dynamic_array.h"
#include "dynamic.cpp"


template<typename T>
T dynamic_array<T>::pop() {
    if(this->start_pointer == nullptr){
        std::cout << "Popped from empty array" << std::endl;
        exit(-5);
    }
    T temp = this->start_pointer[this->arr_size-1];
    T* temp_ptr = &this->start_pointer[this->arr_size-1];
    this->arr_size--;
    T* temp_arr = new T[this->arr_size];
    for(int i = 0; i < this->arr_size; i++){
        temp_arr[i] = this->start_pointer[i];
    }
    delete [] this->start_pointer;
    this->start_pointer = temp_arr;
    return temp;
}

template<typename T>
T dynamic_array<T>::push(T value) {
    this->arr_size++;
    T* temp_arr = new T[this->arr_size];
    for(int i = 0; i < this->arr_size - 1; i++){
        temp_arr[i] = this->start_pointer[i];
    }
    temp_arr[this->arr_size-1] = value;
    this->start_pointer = temp_arr;
    return value;
}
//
//template<typename T>
//void dynamic_array<T>::print() {
//
//    for(int i = 0; i < this->arr_size; i++){
//        std::cout << this->start_pointer[i] << ", ";
//    }
//    std::cout << std::endl;
//}


template<typename T>
T& dynamic_array<T>::operator[](int index){
    if(index >= this->arr_size){
        std::string temp_str = "Array index too high: "
                + std::to_string(index)
                + " >= "
                + std::to_string(this->arr_size);
        throw std::out_of_range(temp_str);
    }
    return this->start_pointer[index];
}
template<typename T>
dynamic_array<T>::~dynamic_array() {
    for(int i = this->arr_size; i < 1; i--){
        delete (this->start_pointer+i);
    }
    delete [] this->start_pointer;
}
//template<typename T>
//dynamic_array<T>::dynamic_array(const dynamic_int_array &old_arr) {
//    arr_size = 0;
//    start_pointer = nullptr;
//    for(int i = 0; i < old_arr.arr_size;i++){
//        this->push(*(old_arr.start_pointer+i));
//    }
//}
template<typename T>
void dynamic_array<T>::getUserInput() {
    using namespace std;
    std::cout << "enter new array values separated by commas" << std::endl;
    std::string temp_string;
    std::getline(std::cin,temp_string);
    std::string temp_value;
//  cout << temp_string.at(temp_string.find(',')) << endl;
    while(temp_string.find(',') != -1){
//      int temp_int = stoi(temp_string.substr(0,temp_string.find(',')));
        temp_value = temp_string.substr(0,temp_string.find(','));
        double temp_double = stod(temp_value);
        temp_string.erase(0,temp_string.find(',')+1);
        this->push((T)temp_double);
    }
    int temp_int = stoi(temp_string);
    this->push(temp_int);
}
template<typename T>
void dynamic_array<T>::getInputFromFile(std::string filename,int mode) {
    // Mode 0 -> Read a single line file that is comma delimited.
    // Mode 1 -> Read a file where each value is on its own line.

    std::ifstream file_stream(filename);
    if(file_stream.fail()){
        std::cout <<"File access failed." << std::endl;
        exit(1);
    }
    switch(mode){
        case 0:
            this->readFromStream(file_stream);
            break;
        case 1:
            int temp_int;
            while(!file_stream.eof()){
                file_stream >> temp_int;
                this->push(temp_int);
            }
            break;
        default:
            exit(2);
    }
    file_stream.close();
}
template<typename T>
void dynamic_array<T>::readFromStream(std::ifstream &file_stream) {
    std::string temp_string;
    std::getline(file_stream,temp_string);
//  cout << temp_string.at(temp_string.find(',')) << endl;
    while(temp_string.find(',') != -1){
        double temp_d = stod(temp_string.substr(0,temp_string.find(',')));
        temp_string.erase(0,temp_string.find(',')+1);
        this->push((T)temp_d);
    }
    double temp_d = stod(temp_string);
    this->push((T)temp_d);
}

template<typename T>
void dynamic_array<T>::outputArrayToFile(std::string filename) {
    std::ofstream file_stream(filename);
    if(file_stream.fail()){
        std::cout << "File access failed." << std::endl;
        exit(1);
    }
    for(int i = 0; i<this->arr_size;i++){
        file_stream << this->start_pointer[i];
        if (i != this->arr_size - 1){
            file_stream << std::endl;
        }
    }
    file_stream.close();
}
