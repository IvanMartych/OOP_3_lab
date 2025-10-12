#include "../include/figure.h"
#include <cstddef>
#include <new>


ArrayOfFigures::ArrayOfFigures(){
    this->arrayCapacity = 5;
    this->numberOfFigures = 0;
    this->figures = new Figure*[arrayCapacity];
    for (size_t i = 0; i < arrayCapacity; i++){
        figures[i] = nullptr;
    }
}

ArrayOfFigures::ArrayOfFigures(Figure* figure){
    this->arrayCapacity = 5;
    this->numberOfFigures = 1;
    figures = new Figure*[arrayCapacity];
    for (size_t i = 0; i < arrayCapacity; i++){
        if (i == 0){
            figures[i] = figure;
        } else {
            figures[i] = nullptr;
        }   
    }
}

ArrayOfFigures::~ArrayOfFigures(){
    for (size_t i = 0; i < arrayCapacity; i++){
        delete figures[i];
        figures[i] = nullptr;
    }
    delete[] figures;
    this->arrayCapacity = 0;
    this->numberOfFigures = 0;
    figures = nullptr;
}


void ArrayOfFigures::addFigure(Figure *figure){
    if (figures[arrayCapacity - 1] != nullptr){
        resizeCapacity();
    }

    figures[numberOfFigures] = figure;
    numberOfFigures++;
}

bool ArrayOfFigures::deleteFigureByIndex(size_t index){
    if (index >= numberOfFigures){
        return false;
    } else if (index == (arrayCapacity - 1) && figures[index] != nullptr) {
        delete figures[index];
        figures[index] = nullptr;
        numberOfFigures--;
        
        return true;
    } else {
        delete figures[index];
        figures[index] = nullptr;
    }
        
    for (size_t i = index; i < (arrayCapacity - 1); i++){
        figures[i] = figures[i+1];
    }
    numberOfFigures--;

    return true;
}

void ArrayOfFigures::resizeCapacity(){
    size_t newCapacity = (this->arrayCapacity) * 2;
    Figure **newFigures = new Figure*[newCapacity];

    for (size_t i = 0; i < arrayCapacity; i++){
        newFigures[i] = figures[i]; 
    }
    for (size_t j = arrayCapacity; j < newCapacity; j++){
        newFigures[j] = nullptr; 
    }
    
    delete[] figures;
    figures = newFigures;
    arrayCapacity = newCapacity;
}


size_t ArrayOfFigures::capacityValue() const {
    return this->arrayCapacity;
}

size_t ArrayOfFigures::numbersOfFiguresValue() const {
    return this->numberOfFigures;
}