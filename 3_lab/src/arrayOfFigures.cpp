#include "../include/arrayofFigures.h"
#include <cstddef>
#include <new>


ArrayOfFigures::ArrayOfFigures(){
    this->array_capacity = 5;
    this->number_of_figures = 0;
    this->figures = new Figure*[array_capacity];
    for (size_t i = 0; i < array_capacity; i++){
        figures[i] = nullptr;
    }
}

ArrayOfFigures::ArrayOfFigures(Figure* figure){
    this->array_capacity = 5;
    this->number_of_figures = 1;
    figures = new Figure*[array_capacity];
    for (size_t i = 0; i < array_capacity; i++){
        if (i == 0){
            figures[i] = figure;
        } else {
            figures[i] = nullptr;
        }   
    }
}

ArrayOfFigures::~ArrayOfFigures(){
    for (size_t i = 0; i < array_capacity; i++){
        delete figures[i];
        figures[i] = nullptr;
    }
    delete[] figures;
    this->array_capacity = 0;
    this->number_of_figures = 0;
    figures = nullptr;
}


void ArrayOfFigures::add_figure(Figure *figure){
    if (figures[array_capacity - 1] != nullptr){
        resize_capacity();
    }

    figures[number_of_figures] = figure;
    number_of_figures++;
}

bool ArrayOfFigures::delete_figure_by_index(size_t index){
    if (index >= number_of_figures){
        return false;
    } else if (index == (array_capacity - 1) && figures[index] != nullptr) {
        delete figures[index];
        figures[index] = nullptr;
        number_of_figures--;
        
        return true;
    } else {
        delete figures[index];
        figures[index] = nullptr;
    }
        
    for (size_t i = index; i < (array_capacity - 1); i++){
        figures[i] = figures[i+1];
    }
    number_of_figures--;

    return true;
}

void ArrayOfFigures::resize_capacity(){
    size_t new_capacity = (this->array_capacity) * 2;
    Figure **new_figures = new Figure*[new_capacity];

    for (size_t i = 0; i < array_capacity; i++){
        new_figures[i] = figures[i]; 
    }
    for (size_t j = array_capacity; j < new_capacity; j++){
        new_figures[j] = nullptr; 
    }
    
    delete[] figures;
    figures = new_figures;
    array_capacity = new_capacity;
}


size_t ArrayOfFigures::capacity_value() const {
    return this->array_capacity;
}

size_t ArrayOfFigures::number_of_figures_value() const {
    return this->number_of_figures;
}