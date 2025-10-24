#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>

class Figure{
protected:
    int numberOfPeaks;
    std::vector<double> sidesLen;
    std::pair<double, double> geometric_centre;
    std::vector<std::pair<double, double>> peaks_coord;

    void lenOfSidesCalc(const std::vector<std::pair<double, double>>& peaks);
public:
    Figure();
    Figure(int count, std::vector<double> xCoord, std::vector<double> yCoord);
    Figure(const std::initializer_list<std::pair<double, double>>& initialValues);
    Figure(const Figure& other);
    Figure(Figure&& other) noexcept;

    virtual void geometric_centre_calc();
    
    double getNumOfPeaks() const;

    std::pair<double, double> getGeomCentre() const;

    std::ostream& printGeomCentre(std::ostream& OutputStream);
    std::ostream& printArea(std::ostream& OutputStream);

    std::ostream& operator<<(std::ostream& os);
    friend std::istream& operator>>(std::istream& is, Figure& fig);

    virtual operator double() const;
    
    virtual bool operator==(const Figure& other) const;
    virtual Figure& operator=(const Figure& other); //copy
    virtual Figure& operator=(Figure&& other) noexcept; //replace
    virtual ~Figure() = default;
};
