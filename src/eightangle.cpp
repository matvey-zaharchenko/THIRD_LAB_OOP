#include "../include/eightangle.h"

Eightangle::Eightangle(){
    numberOfPeaks = 8;
    peaks_coord = {{0, 0}, {1, 1}, {2, 1}, {3, 0}, {3, -1}, {2, -2}, {1, -2}, {0, -1}};
    lenOfSidesCalc(peaks_coord);
    geometric_centre_calc();
}

Eightangle::Eightangle(int count, std::vector<double> xCoord, std::vector<double> yCoord): Figure(count, xCoord, yCoord){
    if(count != 8){
        throw std::logic_error("8-angle 8 sides");
    }
    geometric_centre_calc();
}

Eightangle::Eightangle(const std::initializer_list<std::pair<double, double>>& initialValues): Figure(initialValues){
    if(initialValues.size() != 8){
        throw std::logic_error("8-angle 8 sides");
    }
    geometric_centre_calc();
}

Eightangle::Eightangle(const Eightangle& other): Figure(other){}

Eightangle::Eightangle(Eightangle&& other) noexcept : Figure(std::move(other)){}

void Eightangle::geometric_centre_calc(){
    double xSum = 0.0;
    double ySum = 0.0;
    for(const auto& peak: peaks_coord){
        xSum += peak.first;
        ySum += peak.second;
    }
    geometric_centre.first = xSum / 8.0;
    geometric_centre.second = ySum / 8.0;
} 

Eightangle::operator double() const{
    double area = 0;
    double x1, y1, x2, y2;
    for(int i = 1; i < 8; ++i){
        area += (peaks_coord[i-1].first * peaks_coord[i].second - peaks_coord[i-1].second * peaks_coord[i].first);
    }
    area += (peaks_coord[7].first * peaks_coord[0].second - peaks_coord[7].second * peaks_coord[0].first);
    return fabs(area) / 2.0;
}

bool Eightangle::operator==(const Eightangle& other) const{
    std::vector<double> cpyThis = this->sidesLen;
    std::vector<double> cpyOther = other.sidesLen;

    std::sort(cpyThis.begin(), cpyThis.end());
    std::sort(cpyOther.begin(), cpyOther.end());

    for(int i = 0; i < 8; ++i){
        if(fabs(cpyThis[i] - cpyOther[i]) > 1e-12){
            return false;
        }
    }
    return true;
}

Eightangle& Eightangle::operator=(const Eightangle& other){
    if(this != &other){
        this->numberOfPeaks = other.numberOfPeaks;
        this->peaks_coord = other.peaks_coord;
        this->geometric_centre = other.geometric_centre;
        this->sidesLen = other.sidesLen;
    }
    return *this;
}

Eightangle& Eightangle::operator=(Eightangle&& other) noexcept {
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