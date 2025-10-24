#include "../include/square.h"

Square::Square(){
    numberOfPeaks = 4;
    peaks_coord = {{0, 0}, {0, 1}, {1, 1}, {1, 0}};
    lenOfSidesCalc(peaks_coord);
    geometric_centre_calc();
}

Square::Square(int count, std::vector<double> xCoord, std::vector<double> yCoord): Figure(count, xCoord, yCoord){
    if(count != 4){
        throw std::logic_error("Square 4 sides");
    }
    geometric_centre_calc();
}

Square::Square(const std::initializer_list<std::pair<double, double>>& initialValues): Figure(initialValues){
    if(initialValues.size() != 4){
        throw std::logic_error("Square have 4 sides");
    }
    geometric_centre_calc();
}

Square::Square(const Square& other): Figure(other){}

Square::Square(Square&& other) noexcept : Figure(std::move(other)){}

void Square::geometric_centre_calc(){
    double xSum = 0.0;
    double ySum = 0.0;
    for(const auto& peak: peaks_coord){
        xSum += peak.first;
        ySum += peak.second;
    }
    geometric_centre.first = xSum / 4.0;
    geometric_centre.second = ySum / 4.0;
} 

Square::operator double() const{
    return sidesLen[0] * sidesLen[0];
}

bool Square::operator==(const Square& other) const{
    return this->sidesLen == other.sidesLen;
}

Square& Square::operator=(const Square& other){
    if(this != &other){
        this->numberOfPeaks = other.numberOfPeaks;
        this->peaks_coord = other.peaks_coord;
        this->geometric_centre = other.geometric_centre;
        this->sidesLen = other.sidesLen;
    }
    return *this;
}

Square& Square::operator=(Square&& other) noexcept {
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