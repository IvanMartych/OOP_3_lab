#include "../include/rhomb.h"
#include <cmath>


Rhomb::Rhomb(){
    for (int i = 0; i < 4; i++){
        points[i] = Point();
    }
}

Rhomb::Rhomb(const Point &p1, const Point &p2, const Point &p3, const Point &p4){
    points[0] = p1;
    points[1] = p2;
    points[2] = p3;
    points[3] = p4;
}

double Rhomb::area_of_figure() const{
    double diag1, diag2, result_area;
    diag1 = sqrt(pow(points[0].x - points[2].x, 2) + pow(points[0].y - points[2].y, 2));
    diag2 = sqrt(pow(points[1].x - points[3].x, 2) + pow(points[1].y - points[3].y, 2));
    result_area = 0.5 * diag1 * diag2;
    return result_area;
}

Point Rhomb::center_of_figure() const{
    return Point((points[0].x - points[2].x)/2, (points[0].y - points[2].y)/2);
}

