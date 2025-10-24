#include "../include/triangle.h"

Triangle::Triangle(): Figure(){
    geometric_centre_calc();
}

Triangle::Triangle(int count, std::vector<double> xCoord, std::vector<double> yCoord): Figure(count, xCoord, yCoord){
    if(count != 3){
        throw std::logic_error("Triangle have 3 sides");
    }
    geometric_centre_calc();
}

Triangle::Triangle(const std::initializer_list<std::pair<double, double>>& initialValues): Figure(initialValues){
    if(initialValues.size() != 3){
        throw std::logic_error("Triangle have 3 sides");
    }
    geometric_centre_calc();
}

Triangle::Triangle(const Triangle& other): Figure(other){}

Triangle::Triangle(Triangle&& other) noexcept : Figure(std::move(other)){} 

void Triangle::geometric_centre_calc(){
    double x1, x2, x3, y1, y2, y3;
    x1 = peaks_coord[0].first; x2 = peaks_coord[1].first; x3 = peaks_coord[2].first;
    y1 = peaks_coord[0].second; y2 = peaks_coord[1].second; y3 = peaks_coord[2].second; 
    geometric_centre.first = (x1 + x2 + x3) / 3.0;
    geometric_centre.second = (y1 + y2 + y3) / 3.0;
}

Triangle::operator double() const{
    double x1, x2, x3, y1, y2, y3;
    x1 = peaks_coord[0].first; x2 = peaks_coord[1].first; x3 = peaks_coord[2].first;
    y1 = peaks_coord[0].second; y2 = peaks_coord[1].second; y3 = peaks_coord[2].second; 
    double area = 0.5*fabs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2));
    return area;
}

bool Triangle::operator==(const Triangle& other) const{
    std::vector<double> cpyThis = this->sidesLen;
    std::vector<double> cpyOther = other.sidesLen;

    std::sort(cpyThis.begin(), cpyThis.end());
    std::sort(cpyOther.begin(), cpyOther.end());

    for(int i = 0; i < 4; ++i){
        if(fabs(cpyThis[i] - cpyOther[i]) > 1e-12){
            return false;
        }
    }
    return true;
}

Triangle& Triangle::operator=(const Triangle& other){
    if(this != &other){
        this->numberOfPeaks = other.numberOfPeaks;
        this->peaks_coord = other.peaks_coord;
        this->geometric_centre = other.geometric_centre;
        this->sidesLen = other.sidesLen;
    }
    return *this;
}

Triangle& Triangle::operator=(Triangle&& other) noexcept{
    if(this != &other){
        this->numberOfPeaks = other.numberOfPeaks;
        this->peaks_coord = other.peaks_coord;
        this->geometric_centre = other.geometric_centre;
        this->sidesLen = other.sidesLen;

        other.numberOfPeaks = 0;
        other.peaks_coord.clear();
        other.geometric_centre = {0, 0};
        other.sidesLen.clear();
    }
    return *this;
}
