#pragma once

#include <cstddef>
#include <iostream>
#include <cmath>
#include <istream>


// класс Point для координаты точки по осям X и Y
class Point{
    public:
        Point(double x = 0, double y = 0);
        double x; // координата по оси x
        double y; // координата по оси y
        friend std::ostream& operator<<(std::ostream& output, const Point &p); 
        friend std::istream& operator>>(std::istream& input, Point &p);
};


// класс Figure, от которого уже потом будут наследоваться классы ромба, пятиугольника и шестиугольника
/*
Каждая фигура задаётся 3 координатами, мы можем так делать, так как фигуры у нас равносторонние, и мы сможем найти угол между сторонами в случае ромба,
а у пятиугольника и шестиугольника угол между сторонами всегда равен 108° и 120° соответственно.

ЗАМЕЧАНИЕ: Так как у ромба угол может быть тоже 108° или 120°, следовательно ромб будет задвать сторонами угол между которыми острый, т.е. меньше 90°!!!

Благодаря трём координатам мы сможем найти площадь фигуры, а также геометрический центр фигур
*/
class Figure{
    protected:
        Point points[3]; // массив с координатами фигуры

    public:
        Figure(); // реализовано
        Figure(const Point& p1, const Point& p2, const Point& p3); // реализовано

        /*
        Вывод в стандартный поток вывода std::cout координат вершин фигуры через 
        перегрузку оператора << для std::ostream; 
        Чтение из стандартного потока данных фигур через перегрузку оператора >> для 
        std::istream
        */
        friend std::ostream& operator<<(std::ostream& output, Figure &figure); 
        friend std::istream& operator>>(std::istream& input, Figure &figure);

        /*
        Фигуры должны иметь переопределенные операции копирования (=), перемещения (=) и 
        сравнения (==) 
        */
        Figure& operator=(const Figure& figure);
        Figure& operator=(const Figure&& figure) noexcept;
        bool operator==(const Figure& figure);


        /*
         Вызывать для всего массива общие функции (1-3 см. выше).Т.е. распечатывать для 
        каждой фигуры в массиве геометрический центр и площадь. 
        */
        virtual double areaOfFigure() const = 0; 
        virtual Point centerOfFigure() const = 0; 
        

        // деструктор
        virtual ~Figure() = default;
};

// класс ArrayOfFigures, который представляет из себя реализацию массива для хранения фигур (в массиве хранятся указатели на фигуры)
class ArrayOfFigures{
    private:
        size_t numberOfFigures; // количество фигур в массиве
        size_t arrayCapacity; // вместимость массива, по умолчанию вместимость равна пяти эментам 
        Figure **figures;  // указатели на фигуры (если фигур меньше чем вместимость массива, то пустые ячейки заполнены nullptr)

        // дополнительный для увеличения вместимости массива
        void resizeCapacity(); // реализовано

    public:
        ArrayOfFigures(); // реализовано
        ArrayOfFigures(Figure* figure); // реализовано

        void addFigure(Figure* figure); // реализовано

        /*
        реализовать!!!
        Вызывать для всего массива общие функции (1-3 см. выше).Т.е. распечатывать для 
        каждой фигуры в массиве геометрический центр и площадь. 
        */
        

        /*
         Необходимо уметь вычислять общую площадь фигур в массиве. 
        */ 
        double areaOfAllFigures(ArrayOfFigures& array);
        
        /*
        Удалять из массива фигуру по индексу;  
        */ 
        bool deleteFigureByIndex(size_t index); // реализовано

        Figure* operator[](size_t index); // может быт реализвую, посмотрим, под вопросом ?

        ~ArrayOfFigures(); // реализовано

        size_t numbersOfFiguresValue() const;
        size_t capacityValue() const; // реализовано
};
