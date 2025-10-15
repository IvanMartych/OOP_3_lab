#pragma once

#include <iostream>
#include "figure.h"
#include "point.h"


class Pentagon: public Figure{
    private:
        Point points[5];
    
    public:
        Pentagon();
        Pentagon(const Point &p1, const Point &p2, const Point &p3, const Point &p4, const Point &p5);




};

