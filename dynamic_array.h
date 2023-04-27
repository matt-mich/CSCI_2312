
#ifndef DYNAMICARRAYS_DYNAMIC_ARRAY_H
#define DYNAMICARRAYS_DYNAMIC_ARRAY_H
#include "dynamic.h"
#include <stdexcept>
template<typename T> class dynamic_array : public dynamic<T>{
    protected:

        void readFromStream(std::ifstream &file_stream);
    public:
        dynamic_array<T>() : dynamic<T>(){};
        // dynamic_array(dynamic_array const &old_arr);    // Constructor
        T push(T value);
        T pop();
        void getUserInput();
        void getInputFromFile(std::string filename,int mode);
        void outputArrayToFile(std::string filename);
//        void print();
        T& operator[](int index);
        ~dynamic_array(); // Destructor
};



#endif //DYNAMICARRAYS_DYNAMIC_ARRAY_H
