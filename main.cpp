#include "include/triangle.h"
#include "include/eightangle.h"
#include "include/square.h"
#include "include/figure.h"

void resize(Figure**& array, size_t& size){
    size *= 2;
    Figure** tempArray = new Figure*[size];
    for(size_t i = 0; i < size / 2; ++i){
        tempArray[i] = array[i];
    }
    
    for(size_t i = size / 2; i < size*2; ++i){
        tempArray[i] = nullptr;
    }
    delete[] array;
    array = tempArray;
}

int main(){
    std::cout << "Action List:" << std::endl;
    std::cout << "1. Input figure" << std::endl;
    std::cout << "2. Print data of figure" << std::endl;
    std::cout << "3. Calculate sum of area of figure" << std::endl;
    std::cout << "4. Delete figure from array" << std::endl;
    std::cout << "0. Quit" << std::endl;

    char c;
    int numberOfSize;
    size_t size = 25;
    size_t count = 0;

    Figure** arrayOfFigure = new Figure*[size];
    for(size_t i = 0; i < size; ++i) {
        arrayOfFigure[i] = nullptr;
    }
    while(1){
        std::cin >> c;
        if(c == '0'){
            break;
        }else if(c == '1'){
            if(count >= size){
                resize(arrayOfFigure, count);
            }

            std::cout << "Input count of sides:" << std::endl;
            std::cin >> numberOfSize;

            if(numberOfSize == 3){
                std::cout << "Input 3 peaks coordinates (x y): " << std::endl;
                Triangle* inputTriangle = new Triangle();
                std::cin >> *inputTriangle;
                arrayOfFigure[count] = inputTriangle;
            }else if(numberOfSize == 4){
                std::cout << "Input 4 peaks coordinates (x y): " << std::endl;
                Square* inputSquare = new Square();
                std::cin >> *inputSquare;
                arrayOfFigure[count] = inputSquare;
            }else if(numberOfSize == 8){
                std::cout << "Input 8 peaks coordinates (x y): " << std::endl;
                Eightangle* input8Angle = new Eightangle();
                std::cin >> *input8Angle;
                arrayOfFigure[count] = input8Angle;
            }else{
                std::cout << "Incorrect number of sides. Try again" << std::endl;
                continue;
            }
            ++count;
        }else if(c == '2'){
            if(count == 0){
                std::cout << "Array is empty. Use command 1" <<std::endl;
                continue;
            }
            for(size_t i = 0; i < count; ++i){
                if(arrayOfFigure[i] != nullptr){
                    std::cout << "Figure " << i+1 << ":" << std::endl;
                    arrayOfFigure[i]->operator<<(std::cout);
                    arrayOfFigure[i]->printGeomCentre(std::cout);
                    arrayOfFigure[i]->printArea(std::cout);
                    std::cout << "-----------------" << std::endl;
                    }
            }
        }else if(c == '3'){
            double sum = 0;
            for(size_t i = 0; i < count; ++i){
                if(arrayOfFigure[i] != nullptr){
                    sum += (double)*arrayOfFigure[i];
                }  
            }
            std::cout << "Sum of areas: " << sum << std::endl;
            std::cout << "Input next command" << std::endl;
        }else if(c == '4'){
            if(count == 0){
                std::cout << "Array is empty. Use command 1" << std::endl;
                continue;
            }
            size_t index;
            std::cout << "Input index: ";
            std::cin >> index;
            while(index < 0 || index >= count){
                std::cout << "Index out of range. Try again ";
                std::cin >> index;
            }
            delete arrayOfFigure[index];
            arrayOfFigure[index] = nullptr;
            for(size_t i = index + 1; i < count; ++i){
                arrayOfFigure[i-1] = arrayOfFigure[i];
            }
            arrayOfFigure[count-1] = nullptr;
            --count;
            std::cout << "Done. Input next command" << std::endl;
        }else{
            std::cout << "Incorrect number of command. Try again" << std::endl;
            continue;
        }
    }
    for(size_t i = 0; i < count; ++i){
        if(arrayOfFigure[i] != nullptr){
            delete arrayOfFigure[i];
        }
    }
    delete[] arrayOfFigure;

    return 0;   
}