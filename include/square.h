#include "figure.h"

class Square: public Figure{
public:
    Square();
    Square(int count, std::vector<double> xCoord, std::vector<double> yCoord);
    Square(const std::initializer_list<std::pair<double, double>>& initialValues);
    Square(const Square& other);
    Square(Square&& other) noexcept;

    void geometric_centre_calc();
    
    operator double() const;

    bool operator==(const Square& other) const;
    Square& operator=(const Square& other); //copy
    Square& operator=(Square&& other) noexcept; //replace
};