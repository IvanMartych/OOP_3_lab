#pragma once

#include <cstddef>
#include <iostream>
#include <cmath>
#include <istream>
#include <ostream>
#include "point.h"


// класс Figure, от которого уже потом будут наследоваться классы ромба, пятиугольника и шестиугольника
class Figure{
    protected:
         /*
        хоть и в задании явно не сказано чтобы класс Figure должен быть абстрактным, но я закину конструктор
        в protected, чтобы нельзя было явно создать объект типа Figure
         */
        Figure() = default;
           
    
    public:
        /*
        Вывод в стандартный поток вывода std::cout координат вершин фигуры через 
        перегрузку оператора << для std::ostream; 
        Чтение из стандартного потока данных фигур через перегрузку оператора >> для 
        std::istream
        */
        virtual void print(std::ostream& output) const = 0;
        virtual void read(std::istream& input) = 0; 
        friend std::ostream& operator<<(std::ostream& output, Figure &figure); // реализовано
        friend std::istream& operator>>(std::istream& input, Figure &figure); // реализовано
        /*
         Вызывать для всего массива общие функции (1-3 см. выше).Т.е. распечатывать для 
        каждой фигуры в массиве геометрический центр и площадь. 
        */
        virtual double area_of_figure() const = 0; 
        virtual Point center_of_figure() const = 0; 
        
        virtual ~Figure() = default;
};
