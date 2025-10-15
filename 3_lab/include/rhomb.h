#pragma once

#include <iostream>
#include <ostream>
#include "figure.h"


class Rhomb: public Figure{
    private:
        Point points[4];

    public:
        Rhomb(); // реализовано 
        Rhomb(const Point &p1, const Point &p2, const Point &p3, const Point &p4); // реализовано 

        void print(std::ostream& output) const override;
        void read(std::istream& input) override;
         /*
        Фигуры должны иметь переопределенные операции копирования (=), перемещения (=) и 
        сравнения (==) 
        */
        Rhomb& operator=(const Rhomb& other);
        Rhomb& operator=(const Rhomb&& other) noexcept;
        bool operator==(const Rhomb& other) noexcept;

        double area_of_figure() const override; // реализовано 
        Point center_of_figure() const override; // реализовано 

        ~Rhomb() override;
};

