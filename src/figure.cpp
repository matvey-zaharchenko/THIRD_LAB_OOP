#include "../include/figure.h"

void Figure::lenOfSidesCalc(const std::vector<std::pair<double, double>>& peaks){
    size_t len = peaks.size();
    double x1, x2, y1, y2;
    double size;

    for(size_t i = 1; i < len; ++i){
        x1 = peaks[i-1].first; y1 = peaks[i-1].second;
        x2 = peaks[i].first; y2 = peaks[i].second;
        
        size = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        if(fabs(size) < 1e-12){
            throw std::logic_error("Length of side can't be zero");
        }
        sidesLen.push_back(size);
    }
    x1 = peaks[len-1].first; y1 = peaks[len-1].second;
    x2 = peaks[0].first; y2 = peaks[0].second;
    size = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    if(fabs(size) < 1e-12){
            throw std::logic_error("Length of side can't be zero");
        }

    sidesLen.push_back(size);
}

Figure::Figure(){
    numberOfPeaks = 3;
    peaks_coord = {{0, 0}, {2, 0}, {1, sqrt(3)}};
    lenOfSidesCalc(peaks_coord);
}

Figure::Figure(int count, std::vector<double> xCoord, std::vector<double> yCoord){
    size_t xSize = xCoord.size();
    size_t ySize = yCoord.size();

    if(count != xSize || count != ySize){
        throw std::logic_error("Not enough or too many coordinates");
    } else if(count <= 2){
        throw std::logic_error("Figure must have 3 or more peaks");
    } else if(xSize != ySize){
        throw std::logic_error("X coordinates must be equal Y coordinates");
    }

    std::pair<double, double> pair;
    this->numberOfPeaks = count;
    for(size_t i = 0; i < count; ++i){
        pair = {xCoord[i], yCoord[i]};
        this->peaks_coord.push_back(pair);
    }
    lenOfSidesCalc(peaks_coord);
}

Figure::Figure(const std::initializer_list<std::pair<double, double>>& initialValues){
    size_t len = initialValues.size();
    if(len <= 2){
        throw std::logic_error("Figure must have 3 or more peaks");
    }
    this->numberOfPeaks = len;

    for(const auto& val: initialValues){
        this->peaks_coord.push_back(val);
    }
    lenOfSidesCalc(peaks_coord);
}

Figure::Figure(const Figure& other){
    this->numberOfPeaks = other.numberOfPeaks;
    this->peaks_coord = other.peaks_coord;
    this->sidesLen = other.sidesLen;
    this->geometric_centre = other.geometric_centre;
}

Figure::Figure(Figure&& other) noexcept{
    this->numberOfPeaks = other.numberOfPeaks;
    this->peaks_coord = other.peaks_coord;
    this->geometric_centre = other.geometric_centre;
    this->sidesLen = other.sidesLen;

    other.numberOfPeaks = 0;
    other.peaks_coord.clear();
    other.geometric_centre = {0, 0};
    other.sidesLen.clear();
}

void Figure::geometric_centre_calc(){}

double Figure::getNumOfPeaks() const{
        return numberOfPeaks;
}

std::pair<double, double> Figure::getGeomCentre() const{
    return geometric_centre;
}

std::ostream& Figure::printGeomCentre(std::ostream& OutputStream){
    OutputStream << "Geometric centre: ";
    OutputStream << "x = " << geometric_centre.first << " y = " << geometric_centre.second;
    OutputStream << std::endl;
    return OutputStream;
}

std::ostream& Figure::printArea(std::ostream& OutputStream){
    OutputStream << "Area: ";
    OutputStream << (double)*this;
    OutputStream << std::endl;
    return OutputStream;
}

std::ostream& Figure::operator<<(std::ostream& os){
    int index = 1;
    for(const auto& elem: this->peaks_coord){
        os << "Peak " << index << " coordinates: " << "x = " << elem.first << " y = " << elem.second << std::endl;
        ++index;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Figure& fig){
    for(int i = 0; i < fig.numberOfPeaks; ++i){
        std::cout << "Input peak coordinate:" << std::endl;
        is >> fig.peaks_coord[i].first >> fig.peaks_coord[i].second;
    }
    std::cout << "Done" << std::endl;
    fig.sidesLen.clear();
    fig.lenOfSidesCalc(fig.peaks_coord);
    fig.geometric_centre_calc();
    return is;
}

Figure::operator double() const{return 0.0;}

bool Figure::operator==(const Figure& other) const{ return true;}
Figure& Figure::operator=(const Figure& other) {return *this;} //copy
Figure& Figure::operator=(Figure&& other) noexcept {return *this;} //replace