#pragma once

#include "figure.h"

class Triangle: public Figure{
public:
    Triangle();
    Triangle(int count, std::vector<double> xCoord, std::vector<double> yCoord);
    Triangle(const std::initializer_list<std::pair<double, double>>& initialValues);
    Triangle(const Triangle& other);
    Triangle(Triangle&& other) noexcept;

    void geometric_centre_calc();
    
    operator double() const;
    
    bool operator==(const Triangle& other) const;
    Triangle& operator=(const Triangle& other); //copy
    Triangle& operator=(Triangle&& other) noexcept; //replace
};