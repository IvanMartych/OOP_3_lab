#include "../include/figure.h"


Figure::Figure(){
    this->points[0] = Point(0, 0);
    this->points[1] = Point(0, 0);
    this->points[2] = Point(0, 0);
}


Figure::Figure(const Point &p1, const Point &p2, const Point &p3){
    this->points[0] = p1;
    this->points[1] = p2;
    this->points[2] = p3;
}