#include "include.h"
CPPVector1 CPPVector1::operator+(const CVector1& other)
{
    if (size != other.size) {
        std::cerr << "Cannot add vectors of different sizes!" << std::endl;
        exit(1); // Программа завершает работу из-за ошибки
    }

    CPPVector1 result(size);
    for (int i = 0; i < size; ++i) {
        //std::cout<<"(+)"<<data[i]<<"+"<<other.data[i];
        result.data[i] = data[i] + other.data[i];
    }
    return *this;
}
CPPVector1 CPPVector1::operator-(const CVector1& other)
{
    if (size != other.size) {
        std::cerr << "Cannot add vectors of different sizes!" << std::endl;
        exit(1); // Программа завершает работу из-за ошибки
    }

    CPPVector1 result(size);
    for (int i = 0; i < size; ++i) {
        //std::cout<<"(+)"<<data[i]<<"+"<<other.data[i];
        result.data[i] = data[i] - other.data[i];
    }
    return *this;
}