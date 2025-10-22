#include <gtest/gtest.h>
#include <sstream>
#include <cmath>
#include "../include/point.h"
#include "../include/rhomb.h"
#include "../include/pentagon.h"
#include "../include/hexagon.h"
#include "../include/array_of_figures.h"

/* !!!!!!!!!!!!
Особое внимание что в тестах не обязательно присутствуют правильные фигуры (т.е.
очень тяжело задать правильный пятиугольник поэтотому где я просто брал произвольные точки чтобы
проверить что например центр вычисляется корректно)
И также точки фигуры вводятся по порядку по часовой или против часовой
*/

// Константа для сравнения вещественных чисел
const double EPSILON = 1e-6;

// тесты для Point 

TEST(PointTest, DefaultConstructor) {
    Point p;
    EXPECT_DOUBLE_EQ(p.x, 0.0);
    EXPECT_DOUBLE_EQ(p.y, 0.0);
}

TEST(PointTest, ParameterizedConstructor) {
    Point p(3.5, 4.2);
    EXPECT_DOUBLE_EQ(p.x, 3.5);
    EXPECT_DOUBLE_EQ(p.y, 4.2);
}

TEST(PointTest, OutputOperator) {
    Point p(1.5, 2.5);
    std::ostringstream oss;
    oss << p;
    EXPECT_EQ(oss.str(), "[1.5, 2.5]");
}

TEST(PointTest, InputOperator) {
    Point p;
    std::istringstream iss("3.14 2.71");
    iss >> p;
    EXPECT_DOUBLE_EQ(p.x, 3.14);
    EXPECT_DOUBLE_EQ(p.y, 2.71);
}

// тесты для Rhomb 

TEST(RhombTest, DefaultConstructor) {
    Rhomb r;
    EXPECT_DOUBLE_EQ(r.center_of_figure().x, 0.0);
    EXPECT_DOUBLE_EQ(r.center_of_figure().y, 0.0);
}

TEST(RhombTest, ParameterizedConstructor) {
    Rhomb r(Point(0, 1), Point(1, 0), Point(0, -1), Point(-1, 0));
    Point center = r.center_of_figure();
    EXPECT_NEAR(center.x, 0.0, EPSILON);
    EXPECT_NEAR(center.y, 0.0, EPSILON);
}

TEST(RhombTest, AreaCalculation) {
    // Ромб с диагоналями длиной 2 и 2
    Rhomb r(Point(0, 1), Point(1, 0), Point(0, -1), Point(-1, 0));
    double area = r.area_of_figure();
    EXPECT_NEAR(area, 2.0, EPSILON);
}

TEST(RhombTest, CenterCalculation) {
    Rhomb r(Point(1, 2), Point(3, 1), Point(1, 0), Point(-1, 1));
    Point center = r.center_of_figure();
    EXPECT_NEAR(center.x, 1.0, EPSILON);
    EXPECT_NEAR(center.y, 1.0, EPSILON);
}

TEST(RhombTest, CopyAssignment) {
    Rhomb r1(Point(0, 1), Point(1, 0), Point(0, -1), Point(-1, 0));
    Rhomb r2;
    r2 = r1;
    EXPECT_TRUE(r1 == r2);
}

TEST(RhombTest, MoveAssignment) {
    Rhomb r1(Point(0, 1), Point(1, 0), Point(0, -1), Point(-1, 0));
    Rhomb r2;
    r2 = std::move(r1);
    Point center = r2.center_of_figure();
    EXPECT_NEAR(center.x, 0.0, EPSILON);
    EXPECT_NEAR(center.y, 0.0, EPSILON);
}

TEST(RhombTest, EqualityOperator) {
    Rhomb r1(Point(0, 1), Point(1, 0), Point(0, -1), Point(-1, 0));
    Rhomb r2(Point(0, 1), Point(1, 0), Point(0, -1), Point(-1, 0));
    EXPECT_TRUE(r1 == r2);
}

TEST(RhombTest, InequalityOperator) {
    Rhomb r1(Point(0, 1), Point(1, 0), Point(0, -1), Point(-1, 0));
    Rhomb r2(Point(0, 2), Point(2, 0), Point(0, -2), Point(-2, 0));
    EXPECT_FALSE(r1 == r2);
}

TEST(RhombTest, PrintOperator) {
    Rhomb r(Point(0, 1), Point(1, 0), Point(0, -1), Point(-1, 0));
    std::ostringstream oss;
    oss << r;
    EXPECT_EQ(oss.str(), "Rhomb coordinates: [0, 1] [1, 0] [0, -1] [-1, 0]");
}

TEST(RhombTest, ReadOperator) {
    Rhomb r;
    std::istringstream iss("0 1 1 0 0 -1 -1 0");
    iss >> r;
    Point center = r.center_of_figure();
    EXPECT_NEAR(center.x, 0.0, EPSILON);
    EXPECT_NEAR(center.y, 0.0, EPSILON);
}

// тесты для Pentagon 

TEST(PentagonTest, DefaultConstructor) {
    Pentagon p;
    EXPECT_DOUBLE_EQ(p.center_of_figure().x, 0.0);
    EXPECT_DOUBLE_EQ(p.center_of_figure().y, 0.0);
}

TEST(PentagonTest, ParameterizedConstructor) {
    Pentagon p(Point(0, 2), Point(1.9, 0.6), Point(1.2, -1.6), 
               Point(-1.2, -1.6), Point(-1.9, 0.6));
    Point center = p.center_of_figure();
    EXPECT_NEAR(center.x, 0.0, EPSILON);
    EXPECT_NEAR(center.y, 0.0, EPSILON);
}

TEST(PentagonTest, CenterCalculation) {
    Pentagon p(Point(1, 1), Point(2, 2), Point(3, 3), Point(4, 4), Point(5, 5));
    Point center = p.center_of_figure();
    EXPECT_NEAR(center.x, 3.0, EPSILON);
    EXPECT_NEAR(center.y, 3.0, EPSILON);
}

TEST(PentagonTest, CopyAssignment) {
    Pentagon p1(Point(0, 2), Point(1.9, 0.6), Point(1.2, -1.6), 
                Point(-1.2, -1.6), Point(-1.9, 0.6));
    Pentagon p2;
    p2 = p1;
    EXPECT_TRUE(p1 == p2);
}

TEST(PentagonTest, MoveAssignment) {
    Pentagon p1(Point(0, 2), Point(1.9, 0.6), Point(1.2, -1.6), 
                Point(-1.2, -1.6), Point(-1.9, 0.6));
    Pentagon p2;
    p2 = std::move(p1);
    Point center = p2.center_of_figure();
    EXPECT_NEAR(center.x, 0.0, EPSILON);
}

TEST(PentagonTest, EqualityOperator) {
    Pentagon p1(Point(1, 1), Point(2, 2), Point(3, 3), Point(4, 4), Point(5, 5));
    Pentagon p2(Point(1, 1), Point(2, 2), Point(3, 3), Point(4, 4), Point(5, 5));
    EXPECT_TRUE(p1 == p2);
}

TEST(PentagonTest, InequalityOperator) {
    Pentagon p1(Point(1, 1), Point(2, 2), Point(3, 3), Point(4, 4), Point(5, 5));
    Pentagon p2(Point(0, 2), Point(1.9, 0.6), Point(1.2, -1.6), 
                Point(-1.2, -1.6), Point(-1.9, 0.6));
    EXPECT_FALSE(p1 == p2);
}

TEST(PentagonTest, PrintOperator) {
    Pentagon p(Point(1, 1), Point(2, 2), Point(3, 3), Point(4, 4), Point(5, 5));
    std::ostringstream oss;
    oss << p;
    EXPECT_EQ(oss.str(), "Pentagon coordinates: [1, 1] [2, 2] [3, 3] [4, 4] [5, 5]");
}

TEST(PentagonTest, ReadOperator) {
    Pentagon p;
    std::istringstream iss("1 1 2 2 3 3 4 4 5 5");
    iss >> p;
    Point center = p.center_of_figure();
    EXPECT_NEAR(center.x, 3.0, EPSILON);
    EXPECT_NEAR(center.y, 3.0, EPSILON);
}

// тесты для Hexagon 

TEST(HexagonTest, DefaultConstructor) {
    Hexagon h;
    EXPECT_DOUBLE_EQ(h.center_of_figure().x, 0.0);
    EXPECT_DOUBLE_EQ(h.center_of_figure().y, 0.0);
}

TEST(HexagonTest, ParameterizedConstructor) {
    Hexagon h(Point(2, 0), Point(1, 1.73), Point(-1, 1.73), 
              Point(-2, 0), Point(-1, -1.73), Point(1, -1.73));
    Point center = h.center_of_figure();
    EXPECT_NEAR(center.x, 0.0, EPSILON);
    EXPECT_NEAR(center.y, 0.0, EPSILON);
}

TEST(HexagonTest, CenterCalculation) {
    Hexagon h(Point(3, 0), Point(2, 2), Point(0, 2), 
              Point(-1, 0), Point(0, -2), Point(2, -2));
    Point center = h.center_of_figure();
    EXPECT_NEAR(center.x, 1.0, EPSILON);
    EXPECT_NEAR(center.y, 0.0, EPSILON);
}

TEST(HexagonTest, CopyAssignment) {
    Hexagon h1(Point(2, 0), Point(1, 1.73), Point(-1, 1.73), 
               Point(-2, 0), Point(-1, -1.73), Point(1, -1.73));
    Hexagon h2;
    h2 = h1;
    EXPECT_TRUE(h1 == h2);
}

TEST(HexagonTest, MoveAssignment) {
    Hexagon h1(Point(2, 0), Point(1, 1.73), Point(-1, 1.73), 
               Point(-2, 0), Point(-1, -1.73), Point(1, -1.73));
    Hexagon h2;
    h2 = std::move(h1);
    Point center = h2.center_of_figure();
    EXPECT_NEAR(center.x, 0.0, EPSILON);
}

TEST(HexagonTest, EqualityOperator) {
    Hexagon h1(Point(1, 1), Point(2, 2), Point(3, 3), Point(4, 4), Point(5, 5), Point(6, 6));
    Hexagon h2(Point(1, 1), Point(2, 2), Point(3, 3), Point(4, 4), Point(5, 5), Point(6, 6));
    EXPECT_TRUE(h1 == h2);
}

TEST(HexagonTest, InequalityOperator) {
    Hexagon h1(Point(1, 1), Point(2, 2), Point(3, 3), Point(4, 4), Point(5, 5), Point(6, 6));
    Hexagon h2(Point(2, 0), Point(1, 1.73), Point(-1, 1.73), 
               Point(-2, 0), Point(-1, -1.73), Point(1, -1.73));
    EXPECT_FALSE(h1 == h2);
}

TEST(HexagonTest, PrintOperator) {
    Hexagon h(Point(1, 1), Point(2, 2), Point(3, 3), Point(4, 4), Point(5, 5), Point(6, 6));
    std::ostringstream oss;
    oss << h;
    EXPECT_EQ(oss.str(), "Hexagon coordinates: [1, 1] [2, 2] [3, 3] [4, 4] [5, 5] [6, 6]");
}

TEST(HexagonTest, ReadOperator) {
    Hexagon h;
    std::istringstream iss("1 1 2 2 3 3 4 4 5 5 6 6");
    iss >> h;
    Point center = h.center_of_figure();
    EXPECT_NEAR(center.x, 3.5, EPSILON);
    EXPECT_NEAR(center.y, 3.5, EPSILON);
}

// тесты для Array_of_figures 

TEST(ArrayOfFiguresTest, DefaultConstructor) {
    Array_of_figures arr;
    EXPECT_EQ(arr.number_of_figures_value(), 0);
    EXPECT_EQ(arr.capacity_value(), 5);
}

TEST(ArrayOfFiguresTest, ConstructorWithFigure) {
    Rhomb* r = new Rhomb(Point(0, 1), Point(1, 0), Point(0, -1), Point(-1, 0));
    Array_of_figures arr(r);
    EXPECT_EQ(arr.number_of_figures_value(), 1);
    EXPECT_EQ(arr.capacity_value(), 5);
}

TEST(ArrayOfFiguresTest, AddFigure) {
    Array_of_figures arr;
    Rhomb* r = new Rhomb(Point(0, 1), Point(1, 0), Point(0, -1), Point(-1, 0));
    arr.add_figure(r);
    EXPECT_EQ(arr.number_of_figures_value(), 1);
}

TEST(ArrayOfFiguresTest, AddMultipleFigures) {
    Array_of_figures arr;
    arr.add_figure(new Rhomb(Point(0, 1), Point(1, 0), Point(0, -1), Point(-1, 0)));
    arr.add_figure(new Pentagon(Point(1, 1), Point(2, 2), Point(3, 3), Point(4, 4), Point(5, 5)));
    arr.add_figure(new Hexagon(Point(1, 1), Point(2, 2), Point(3, 3), Point(4, 4), Point(5, 5), Point(6, 6)));
    EXPECT_EQ(arr.number_of_figures_value(), 3);
}

TEST(ArrayOfFiguresTest, ResizeCapacity) {
    Array_of_figures arr;
    for (int i = 0; i < 6; i++) {
        arr.add_figure(new Rhomb(Point(0, 1), Point(1, 0), Point(0, -1), Point(-1, 0)));
    }
    EXPECT_EQ(arr.number_of_figures_value(), 6);
    EXPECT_GE(arr.capacity_value(), 6);
}

TEST(ArrayOfFiguresTest, DeleteFigureByIndex) {
    Array_of_figures arr;
    arr.add_figure(new Rhomb(Point(0, 1), Point(1, 0), Point(0, -1), Point(-1, 0)));
    arr.add_figure(new Pentagon(Point(1, 1), Point(2, 2), Point(3, 3), Point(4, 4), Point(5, 5)));
    arr.add_figure(new Hexagon(Point(1, 1), Point(2, 2), Point(3, 3), Point(4, 4), Point(5, 5), Point(6, 6)));
    
    EXPECT_TRUE(arr.delete_figure_by_index(1));
    EXPECT_EQ(arr.number_of_figures_value(), 2);
}

TEST(ArrayOfFiguresTest, DeleteFigureByInvalidIndex) {
    Array_of_figures arr;
    arr.add_figure(new Rhomb(Point(0, 1), Point(1, 0), Point(0, -1), Point(-1, 0)));
    
    EXPECT_FALSE(arr.delete_figure_by_index(5));
    EXPECT_EQ(arr.number_of_figures_value(), 1);
}

TEST(ArrayOfFiguresTest, SubscriptOperator) {
    Array_of_figures arr;
    Rhomb* r = new Rhomb(Point(0, 1), Point(1, 0), Point(0, -1), Point(-1, 0));
    arr.add_figure(r);
    
    Figure* fig = arr[0];
    EXPECT_NE(fig, nullptr);
    EXPECT_NEAR(fig->center_of_figure().x, 0.0, EPSILON);
}

TEST(ArrayOfFiguresTest, SubscriptOperatorInvalidIndex) {
    Array_of_figures arr;
    arr.add_figure(new Rhomb(Point(0, 1), Point(1, 0), Point(0, -1), Point(-1, 0)));
    
    Figure* fig = arr[10];
    EXPECT_EQ(fig, nullptr);
}

TEST(ArrayOfFiguresTest, AreaSumOfAllFigures) {
    Array_of_figures arr;
    arr.add_figure(new Rhomb(Point(0, 1), Point(1, 0), Point(0, -1), Point(-1, 0))); // area = 2
    arr.add_figure(new Rhomb(Point(0, 2), Point(2, 0), Point(0, -2), Point(-2, 0))); // area = 8
    
    double total_area = arr.area_sum_of_all_figures();
    EXPECT_NEAR(total_area, 10.0, EPSILON);
}

TEST(ArrayOfFiguresTest, AreaSumOfEmptyArray) {
    Array_of_figures arr;
    double total_area = arr.area_sum_of_all_figures();
    EXPECT_DOUBLE_EQ(total_area, 0.0);
}

TEST(ArrayOfFiguresTest, DeleteAllFigures) {
    Array_of_figures arr;
    arr.add_figure(new Rhomb(Point(0, 1), Point(1, 0), Point(0, -1), Point(-1, 0)));
    arr.add_figure(new Pentagon(Point(1, 1), Point(2, 2), Point(3, 3), Point(4, 4), Point(5, 5)));
    arr.add_figure(new Hexagon(Point(1, 1), Point(2, 2), Point(3, 3), Point(4, 4), Point(5, 5), Point(6, 6)));
    
    arr.delete_figure_by_index(0);
    arr.delete_figure_by_index(0);
    arr.delete_figure_by_index(0);
    
    EXPECT_EQ(arr.number_of_figures_value(), 0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
