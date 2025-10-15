#pragma once

#include "figure.h"
#include <cstddef>
#include <iostream>


// класс ArrayOfFigures представляет из себя реализацию массива для хранения фигур (в массиве хранятся указатели на фигуры)
class ArrayOfFigures{
    private:
        size_t number_of_figures; // количество фигур в массиве
        size_t array_capacity; // вместимость массива, по умолчанию вместимость равна пяти эментам 
        Figure **figures;  // указатели на фигуры (если фигур меньше чем вместимость массива, то пустые ячейки заполнены nullptr)

        // дополнительный для увеличения вместимости массива
        void resize_capacity(); // реализовано

    public:
        ArrayOfFigures(); // реализовано
        ArrayOfFigures(Figure* figure); // реализовано

        void add_figure(Figure* figure); // реализовано
        
        /*
        реализовать!!!
        Вызывать для всего массива общие функции (1-3 см. выше).Т.е. распечатывать для 
        каждой фигуры в массиве геометрический центр и площадь. 
        */
        
        /*
         Необходимо уметь вычислять общую площадь фигур в массиве. 
        */ 
        double area_of_all_figures(ArrayOfFigures& array);
        
        /*
        Удалять из массива фигуру по индексу;  
        */ 
        bool delete_figure_by_index(size_t index); // реализовано

        Figure* operator[](size_t index); // может быт реализвую, посмотрим, под вопросом ?

        ~ArrayOfFigures(); // реализовано

        size_t number_of_figures_value() const; // реализовано
        size_t capacity_value() const; // реализовано
};
