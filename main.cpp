#include <iostream>
#include "dynamic_array.h"
#include "dynamic_array.cpp"

#include "dynamic_list.h"
#include "dynamic_list.cpp"

// Goal: Make a dynamically resizable array.

int main() {
/*
//    dynamic_int_array::num_arrays = 0;
    dynamic_int_array darr = dynamic_int_array();
//    std::cout << dynamic_int_array::num_arrays << std::endl;
    //    darr.print();
    for(int i = 0; i < 10; i++) {
        darr.push(i);
//        darr.print();
    }
    darr[5] = 42;
//    darr.print();
    //    std::cout << darr[2] << std::endl;
    for(int i = 0; i < 3; i++) {
        std::cout << darr.pop()<< std::endl;
//        darr.print();
    }
    dynamic_int_array new_darr = dynamic_int_array(darr);
//    std::cout << dynamic_int_array::num_arrays << std::endl;
    new_darr.print();
    new_darr.getUserInput();
    new_darr.print();

    dynamic_int_array darr = dynamic_int_array();
    std::string filename = "array_commas.txt";
    std::string filename_lines = "out_array_lines.txt";
    std::string out_filename_lines = "out_array_lines.txt";

//    darr.getInputFromFile(filename,0);
    darr.getInputFromFile(filename_lines,1);

    darr.print();
    darr.outputArrayToFile(out_filename_lines);
    darr.getInputFromFile(out_filename_lines,1);
    darr.print();
    darr.outputArrayToFile(out_filename_lines);
*/
//    dynamic_list<double> darr_int = dynamic_list<double>();
    dynamic_array<double> darr_int = dynamic_array<double>();

    darr_int.push(10.1);
    for(int i = 0; i < 5; i++){
        darr_int.push((double)i+((double)i/10));
    }
    darr_int.print();

    try{
        std::cout << darr_int[10] << std::endl;
    }catch (std::out_of_range& e){
        std::cout << "Array isn't ten values long :(" << std::endl;
    }

    std::cout << darr_int[7] << std::endl;
    std::cout << darr_int[2] << std::endl;

    std::cout << darr_int.pop() << std::endl;

    darr_int.print();
//    std::string filename = "array_commas.txt";
    return 0;
}
