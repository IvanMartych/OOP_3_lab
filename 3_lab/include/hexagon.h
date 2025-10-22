#pragma once

#include <iostream>
#include "figure.h"


// класс шестиугольника
class Hexagon: public Figure{
    private:
        Point points[6];

    public:
        Hexagon(); 
        Hexagon(const Point &p1, const Point &p2, const Point &p3, const Point &p4, const Point &p5, const Point &p6); 

        void print(std::ostream& output) const override; 
        void read(std::istream& input) override; 
        /*
        Фигуры должны иметь переопределенные операции копирования (=), перемещения (=) и 
        сравнения (==) 
        */
        Hexagon& operator=(const Hexagon& other);
        Hexagon& operator=(Hexagon&& other) noexcept; 
        bool operator==(const Hexagon& other)const  noexcept;  

        double area_of_figure() const override;  
        Point center_of_figure() const override;  

        ~Hexagon() override = default;
}; 

