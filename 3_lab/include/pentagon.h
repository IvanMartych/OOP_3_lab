#pragma once

#include <iostream>
#include "figure.h"


// класс пятиугольника
class Pentagon: public Figure{ 
    private:
        Point points[5];

    public:
        Pentagon(); // переделано
        Pentagon(const Point &p1, const Point &p2, const Point &p3, const Point &p4, const Point &p5); // переделано

        void print(std::ostream& output) const override; // переделано
        void read(std::istream& input) override; // переделано
        /*
        Фигуры должны иметь переопределенные операции копирования (=), перемещения (=) и 
        сравнения (==) 
        */
        Pentagon& operator=(const Pentagon& other); // переделано
        Pentagon& operator=(const Pentagon&& other) noexcept; // переделано
        bool operator==(const Pentagon& other)const  noexcept; // переделано

        double area_of_figure() const override;  // переделано
        Point center_of_figure() const override; // переделано

        ~Pentagon() override = default; // так как точка у нас не динамический объект, то дефолтный деструктор полностью почистит ромб, без утечки памяти
}; 

