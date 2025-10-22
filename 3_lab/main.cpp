#include <iostream>
#include "include/point.h"
#include "include/rhomb.h"
#include "include/pentagon.h"
#include "include/hexagon.h"
#include "include/array_of_figures.h"


int main() {
    // ромб
    Rhomb* rhomb = new Rhomb(Point(0, 1), Point(1, 0), Point(0, -1), Point(-1, 0));
    std::cout << *rhomb << std::endl;
    std::cout << "Площадь ромба: " << rhomb->area_of_figure() << std::endl;
    std::cout << "Центр ромба: " << rhomb->center_of_figure() <<"\n"<< std::endl;

    // пятиуголольник
    // опять же не прям точный правильный пятиугольник так как полностью правильный пятиугольник тяжело задать
    Pentagon* pentagon = new Pentagon(
        Point(0, 2),
        Point(1.9, 0.6),
        Point(1.2, -1.6),
        Point(-1.2, -1.6),
        Point(-1.9, 0.6)
    );
    std::cout << *pentagon << std::endl;
    std::cout << "Площадь пятиугольника: " << pentagon->area_of_figure() << std::endl;
    std::cout << "Центр пятиугольника: " << pentagon->center_of_figure() <<"\n"<< std::endl;

    // шестиугольник
    Hexagon* hexagon = new Hexagon(
        Point(2, 0),
        Point(1, 1.73),
        Point(-1, 1.73),
        Point(-2, 0),
        Point(-1, -1.73),
        Point(1, -1.73)
    );
    std::cout << *hexagon << std::endl;
    std::cout << "Площадь шестиугольника: " << hexagon->area_of_figure() << std::endl;
    std::cout << "Центр шестиугольника: " << hexagon->center_of_figure() <<"\n"<<std::endl;

    Array_of_figures array;
    
    array.add_figure(rhomb);
    array.add_figure(pentagon);
    array.add_figure(hexagon);

    std::cout << "Количество фигур: " << array.number_of_figures_value() << std::endl;
    std::cout << "Вместимость: " << array.capacity_value() <<"\n"<< std::endl;

    std::cout << "Площади всех фигур:" << std::endl;
    array.area_of_all_figures();
    std::cout << std::endl;

    std::cout << "Центры всех фигур:" << std::endl;
    array.center_of_all_figures();
    std::cout << std::endl;

    std::cout << "Общая площадь всех фигур: " << array.area_sum_of_all_figures() <<"\n"<< std::endl;

    if (array.delete_figure_by_index(1)) {
        std::cout << "Фигура успешно удалена" << std::endl;
        std::cout << "Количество фигур после удаления: " << array.number_of_figures_value() << std::endl;
    }


    Rhomb rhomb2;
    rhomb2 = Rhomb(Point(0, 2), Point(2, 0), Point(0, -2), Point(-2, 0));
    std::cout << "Новый ромб: " << rhomb2 << std::endl;

    Rhomb rhomb3(Point(0, 2), Point(2, 0), Point(0, -2), Point(-2, 0));
    if (rhomb2 == rhomb3) {
        std::cout << "Ромбы равны" << std::endl;
    }

    return 0;
}
// :)
