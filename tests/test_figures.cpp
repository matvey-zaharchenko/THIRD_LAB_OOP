#include <gtest/gtest.h>
#include <vector>
#include <cmath>
#include "figure.h"
#include "triangle.h"
#include "square.h"
#include "eightangle.h"

// Тесты для базового класса Figure
TEST(FigureTest, DefaultConstructor) {
    Figure fig;
    EXPECT_EQ(fig.getNumOfPeaks(), 3);
}

TEST(FigureTest, ParameterizedConstructor) {
    std::vector<double> x = {0, 2, 1};
    std::vector<double> y = {0, 0, sqrt(3)};
    
    Figure fig(3, x, y);
    EXPECT_EQ(fig.getNumOfPeaks(), 3);
}

TEST(FigureTest, ParameterizedConstructorInvalidCount) {
    std::vector<double> x = {0, 1};
    std::vector<double> y = {0, 1};
    
    EXPECT_THROW(Figure(2, x, y), std::logic_error);
}

TEST(FigureTest, InitializerListConstructor) {
    Figure fig{{0, 0}, {2, 0}, {1, sqrt(3)}};
    EXPECT_EQ(fig.getNumOfPeaks(), 3);
}

TEST(FigureTest, CopyConstructor) {
    Figure fig1;
    Figure fig2(fig1);
    
    EXPECT_EQ(fig1.getNumOfPeaks(), fig2.getNumOfPeaks());
}

TEST(FigureTest, MoveConstructor) {
    Figure fig1;
    Figure fig2(std::move(fig1));
    
    EXPECT_EQ(fig2.getNumOfPeaks(), 3);
    EXPECT_EQ(fig1.getNumOfPeaks(), 0);
}

// Тесты для класса Triangle
TEST(TriangleTest, DefaultConstructor) {
    Triangle tri;
    EXPECT_EQ(tri.getNumOfPeaks(), 3);
}

TEST(TriangleTest, ParameterizedConstructor) {
    std::vector<double> x = {0, 3, 1.5};
    std::vector<double> y = {0, 0, 2.598};
    
    Triangle tri(3, x, y);
    EXPECT_EQ(tri.getNumOfPeaks(), 3);
}

TEST(TriangleTest, ParameterizedConstructorInvalidCount) {
    std::vector<double> x = {0, 1, 2, 3};
    std::vector<double> y = {0, 1, 2, 3};
    
    EXPECT_THROW(Triangle(4, x, y), std::logic_error);
}

TEST(TriangleTest, InitializerListConstructor) {
    Triangle tri{{0, 0}, {3, 0}, {1.5, 2.598}};
    EXPECT_EQ(tri.getNumOfPeaks(), 3);
}

TEST(TriangleTest, GeometricCentreCalculation) {
    Triangle tri{{0, 0}, {3, 0}, {1.5, 2.598}};
    tri.geometric_centre_calc();
    
    EXPECT_NEAR(tri.getGeomCentre().first, 1.5, 1e-12);
    EXPECT_NEAR(tri.getGeomCentre().second, 0.866, 1e-3);
}

TEST(TriangleTest, AreaCalculation) {
    Triangle tri{{0, 0}, {3, 0}, {1.5, 2.598}};
    double area = static_cast<double>(tri);
    
    EXPECT_NEAR(area, 3.897, 1e-3);
}

TEST(TriangleTest, EqualityOperator) {
    Triangle tri1{{0, 0}, {3, 0}, {1.5, 2.598}};
    Triangle tri2{{0, 0}, {3, 0}, {1.5, 2.598}};
    
    EXPECT_TRUE(tri1 == tri2);
}

TEST(TriangleTest, CopyAssignment) {
    Triangle tri1{{0, 0}, {3, 0}, {1.5, 2.598}};
    Triangle tri2;
    tri2 = tri1;
    
    EXPECT_TRUE(tri1 == tri2);
}

TEST(TriangleTest, MoveAssignment) {
    Triangle tri1{{0, 0}, {3, 0}, {1.5, 2.598}};
    Triangle tri2;
    tri2 = std::move(tri1);
    
    EXPECT_EQ(tri2.getNumOfPeaks(), 3);
}

// Тесты для класса Square
TEST(SquareTest, DefaultConstructor) {
    Square sq;
    EXPECT_EQ(sq.getNumOfPeaks(), 4);
}

TEST(SquareTest, ParameterizedConstructor) {
    std::vector<double> x = {0, 0, 2, 2};
    std::vector<double> y = {0, 2, 2, 0};
    
    Square sq(4, x, y);
    EXPECT_EQ(sq.getNumOfPeaks(), 4);
}

TEST(SquareTest, InitializerListConstructor) {
    Square sq{{0, 0}, {0, 2}, {2, 2}, {2, 0}};
    EXPECT_EQ(sq.getNumOfPeaks(), 4);
}

TEST(SquareTest, GeometricCentreCalculation) {
    Square sq{{0, 0}, {0, 2}, {2, 2}, {2, 0}};
    sq.geometric_centre_calc();
    
    EXPECT_NEAR(sq.getGeomCentre().first, 1.0, 1e-12);
    EXPECT_NEAR(sq.getGeomCentre().second, 1.0, 1e-12);
}

TEST(SquareTest, AreaCalculation) {
    Square sq{{0, 0}, {0, 2}, {2, 2}, {2, 0}};
    double area = static_cast<double>(sq);
    
    EXPECT_NEAR(area, 4.0, 1e-12);
}

TEST(SquareTest, EqualityOperator) {
    Square sq1{{0, 0}, {0, 2}, {2, 2}, {2, 0}};
    Square sq2{{0, 0}, {0, 2}, {2, 2}, {2, 0}};
    
    EXPECT_TRUE(sq1 == sq2);
}

TEST(SquareTest, CopyAssignment) {
    Square sq1{{0, 0}, {0, 2}, {2, 2}, {2, 0}};
    Square sq2;
    sq2 = sq1;
    
    EXPECT_TRUE(sq1 == sq2);
}

// Тесты для класса Eightangle
TEST(EightangleTest, DefaultConstructor) {
    Eightangle oct;
    EXPECT_EQ(oct.getNumOfPeaks(), 8);
}

TEST(EightangleTest, ParameterizedConstructor) {
    std::vector<double> x = {0, 1, 2, 3, 3, 2, 1, 0};
    std::vector<double> y = {0, 1, 1, 0, -1, -2, -2, -1};
    
    Eightangle oct(8, x, y);
    EXPECT_EQ(oct.getNumOfPeaks(), 8);
}

TEST(EightangleTest, InitializerListConstructor) {
    Eightangle oct{{0, 0}, {1, 1}, {2, 1}, {3, 0}, {3, -1}, {2, -2}, {1, -2}, {0, -1}};
    EXPECT_EQ(oct.getNumOfPeaks(), 8);
}

TEST(EightangleTest, GeometricCentreCalculation) {
    Eightangle oct{{0, 0}, {1, 1}, {2, 1}, {3, 0}, {3, -1}, {2, -2}, {1, -2}, {0, -1}};
    oct.geometric_centre_calc();
    
    // Среднее арифметическое всех координат
    double expected_x = (0 + 1 + 2 + 3 + 3 + 2 + 1 + 0) / 8.0;
    double expected_y = (0 + 1 + 1 + 0 - 1 - 2 - 2 - 1) / 8.0;
    
    EXPECT_NEAR(oct.getGeomCentre().first, expected_x, 1e-12);
    EXPECT_NEAR(oct.getGeomCentre().second, expected_y, 1e-12);
}

TEST(EightangleTest, AreaCalculation) {
    Eightangle oct{{0, 0}, {1, 1}, {2, 1}, {3, 0}, {3, -1}, {2, -2}, {1, -2}, {0, -1}};
    double area = static_cast<double>(oct);
    
    // Проверяем что площадь вычисляется (значение будет зависеть от конкретных координат)
    EXPECT_NEAR(area, 7.0, 1e-12);
}

TEST(EightangleTest, EqualityOperator) {
    Eightangle oct1{{0, 0}, {1, 1}, {2, 1}, {3, 0}, {3, -1}, {2, -2}, {1, -2}, {0, -1}};
    Eightangle oct2{{0, 0}, {1, 1}, {2, 1}, {3, 0}, {3, -1}, {2, -2}, {1, -2}, {0, -1}};
    
    EXPECT_TRUE(oct1 == oct2);
}

TEST(EightangleTest, CopyAssignment) {
    Eightangle oct1{{0, 0}, {1, 1}, {2, 1}, {3, 0}, {3, -1}, {2, -2}, {1, -2}, {0, -1}};
    Eightangle oct2;
    oct2 = oct1;
    
    EXPECT_TRUE(oct1 == oct2);
}

TEST(EightangleTest, MoveAssignment) {
    Eightangle oct1{{0, 0}, {1, 1}, {2, 1}, {3, 0}, {3, -1}, {2, -2}, {1, -2}, {0, -1}};
    Eightangle oct2;
    oct2 = std::move(oct1);
    
    EXPECT_EQ(oct2.getNumOfPeaks(), 8);
}

// Тесты на исключения
TEST(ExceptionTest, ZeroLengthSide) {
    std::vector<double> x = {0, 0, 0};
    std::vector<double> y = {0, 1, 0};
    
    EXPECT_THROW(Triangle(3, x, y), std::logic_error);
}

TEST(ExceptionTest, CoordinateMismatch) {
    std::vector<double> x = {0, 1, 2};
    std::vector<double> y = {0, 1}; // Не хватает одной координаты y
    
    EXPECT_THROW(Triangle(3, x, y), std::logic_error);
}

// Тесты полиморфного поведения
TEST(PolymorphismTest, VirtualFunctions) {
    Figure* fig1 = new Triangle();
    Figure* fig2 = new Square();
    Figure* fig3 = new Eightangle();
    
    // Проверяем что можно вызвать виртуальные функции
    fig1->geometric_centre_calc();
    fig2->geometric_centre_calc();
    fig3->geometric_centre_calc();
    
    delete fig1;
    delete fig2;
    delete fig3;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}