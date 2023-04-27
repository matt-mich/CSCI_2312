//
// Created by Doctor on 4/25/2023.
//

#include "dynamic_list.h"

template<typename T>
dynamic_list<T>::~dynamic_list() {
    while(this->arr_size > 0){
        this->pop();
    }
}

template<typename T>
T &dynamic_list<T>::operator[](int index) {
    linked_list<T>* curr_ptr = getNodeAtIndex(index);
    return curr_ptr->value;
}

template<typename T>
linked_list<T> *dynamic_list<T>::getNodeAtIndex(int index) {
    if(index > this->arr_size - 1){
        std::cout << "Out of range" << std::endl;
        exit(-6);
    }
    if(index == 0){
        return start_list_pointer;
    }

    linked_list<T>* curr_ptr = this->start_list_pointer;
    for(int i = 0; i < index; i++){
        curr_ptr = curr_ptr->ptr;
    }
    return curr_ptr;
}

template<typename T>
T dynamic_list<T>::pop() {
    if(this->start_list_pointer == nullptr){
        std::cout << "Popped from empty" << std::endl;
        exit(-5);
    }
    linked_list<T>* curr_second_last;
    T popped_value;

    if(this->arr_size == 1){
        curr_second_last = start_list_pointer;
        popped_value = curr_second_last->value;
    }else if(this->arr_size >= 2){
        curr_second_last = this->getNodeAtIndex(this->arr_size-2);
        popped_value = curr_second_last->ptr->value;
    }
    linked_list<T>* curr_last = curr_second_last->ptr;
    delete curr_last;
    this->arr_size--;
    curr_second_last->ptr = nullptr;
    return popped_value;
}

//template<typename T>
//void dynamic_list<T>::print() {
////    linked_list<T>* curr_ptr = this->start_list_pointer;
////    if(this->start_list_pointer == nullptr){
////        std::cout << "No values" << std::endl;
////    }
////    do{
////        std::cout << curr_ptr->value << ", ";
////        curr_ptr = curr_ptr->ptr;
////    }while(curr_ptr != nullptr);
////    std::cout << std::endl;
//    for(int i = 0; i < this->arr_size; i++){
//        std::cout << (*this)[i] << ", ";
//    }
//    std::cout << std::endl;
//
//}

template<typename T>
linked_list<T> *dynamic_list<T>::getLast() {
    linked_list<T>* curr_ptr = this->start_list_pointer;
    if(this->start_list_pointer == nullptr){
        return this->start_list_pointer;
    }
    while(curr_ptr->ptr != nullptr){
        curr_ptr = curr_ptr->ptr;
    }
    return curr_ptr;
}

template<typename T>
T dynamic_list<T>::push(T value) {
    auto* temp_node = new linked_list<T>;
    temp_node->value = value;
    temp_node->ptr = nullptr;
    this->arr_size++;
    if(this->start_list_pointer == nullptr){
        this->start_list_pointer = temp_node;
        return temp_node->value;
    }
    linked_list<T>* curr_last = this->getLast();
    curr_last->ptr = temp_node;
    return temp_node->value;
}
