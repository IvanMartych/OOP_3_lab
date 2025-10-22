#pragma once

#include "figure.h"
#include "rhomb.h"
#include "pentagon.h"
#include "hexagon.h"
#include "point.h"
#include <cstddef>
#include <iostream>


// класс Array_of_figures представляет из себя реализацию массива для хранения фигур (в массиве хранятся указатели на фигуры)
class Array_of_figures{
    private:
        size_t number_of_figures; // количество фигур в массиве
        size_t array_capacity; // вместимость массива, по умолчанию вместимость равна пяти эментам 
        Figure **figures;  // указатели на фигуры (если фигур меньше чем вместимость массива, то пустые ячейки заполнены nullptr)

        // дополнительный метод для увеличения вместимости массива
        void resize_capacity(); 

    public:
        Array_of_figures(); 
        Array_of_figures(Figure* figure); 

        void add_figure(Figure* figure); 
        
        /*
        Вызывать для всего массива общие функции (1-3 см. выше).Т.е. распечатывать для 
        каждой фигуры в массиве геометрический центр и площадь. 
        */
        void area_of_all_figures() const; 
        void center_of_all_figures() const; 
        /*
        Необходимо уметь вычислять общую площадь фигур в массиве. 
        */ 
        double area_sum_of_all_figures()const; 
        
        /*
        Удалять из массива фигуру по индексу;  
        */ 
        bool delete_figure_by_index(size_t index); 

        Figure* operator[](size_t index); 

        ~Array_of_figures(); 

        size_t number_of_figures_value() const; 
        size_t capacity_value() const; 
};
