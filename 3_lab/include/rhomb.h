#pragma once

#include <iostream>
#include <ostream>
#include "figure.h"

// класс ромба
class Rhomb: public Figure{
    private:
        Point points[4];

    public:
        Rhomb(); // реализовано 
        Rhomb(const Point &p1, const Point &p2, const Point &p3, const Point &p4); // реализовано 

        void print(std::ostream& output) const override; // реализовано 
        void read(std::istream& input) override; // реализовано 
        /*
        Фигуры должны иметь переопределенные операции копирования (=), перемещения (=) и 
        сравнения (==) 
        */
        Rhomb& operator=(const Rhomb& other); // реализовано
        Rhomb& operator=(const Rhomb&& other) noexcept; // реализовано
        bool operator==(const Rhomb& other)const noexcept; // реализовано 

        double area_of_figure() const override; // реализовано 
        Point center_of_figure() const override; // реализовано 

        ~Rhomb() override = default; // так как точка у нас не динамический объект, то дефолтный деструктор полностью почистит ромб, без утечки памяти
}; 

