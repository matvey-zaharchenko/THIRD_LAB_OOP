#include "figure.h"

class Eightangle: public Figure{
public:
    Eightangle();
    Eightangle(int count, std::vector<double> xCoord, std::vector<double> yCoord);
    Eightangle(const std::initializer_list<std::pair<double, double>>& initialValues);
    Eightangle(const Eightangle& other);
    Eightangle(Eightangle&& other) noexcept;

    void geometric_centre_calc();
    
    operator double() const;
    
    bool operator==(const Eightangle& other) const;
    Eightangle& operator=(const Eightangle& other); //copy
    Eightangle& operator=(Eightangle&& other) noexcept; //replace
};