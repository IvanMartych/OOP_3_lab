#pragma once

#include <iostream>
#include "figure.h"
#include "point.h"


class Hexagon: public Figure{
    private:
        Point points[6];
    
    public:
        Hexagon();
        Hexagon(const Point &p1, const Point &p2, const Point &p3, const Point &p4, const Point &p5, const Point &p6);


        
};

