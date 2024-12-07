#include "shapes.hpp"

Shape::Shape(const char* name) {
    setName(name);
}

Shape::Shape(const Shape& other) {
    setName(other.name);
}

Shape& Shape::operator=(const Shape& other) {
    if (this != &other) {
        setName(other.name);
    }
    return *this;
}

Shape::~Shape() {
    delete[] name;
}

void Shape::setName(const char* name) { 
    char* newName = new char[strlen(name) + 1]; 
    strcpy(newName, name); 
    delete[] this->name;
    this->name = newName;
    newName = nullptr;
} 

const char* Shape::getName() {
    return name; 
} 
 
//2d shape
TwoDShape::TwoDShape(double sideLength, 
const char* name) : Shape(name){
    setSideLength(sideLength); 
} 
 
double TwoDShape::getSideLength(){ 
    return this->sideLength; 
} 
 
//sets side length 
void TwoDShape::setSideLength(double sideLength){ 
    this->sideLength = sideLength; 
} 
 
//Circle 
Circle::Circle(double radius) : Shape("Circle"), TwoDShape(radius) {} 
 
double Circle::getRadius(){ 
    return sideLength; 
} 
void Circle::setRadius(double radius){ 
    setSideLength(radius); 
} 
double Circle::getArea(){ 
    return M_PI * sideLength * sideLength; 
} 
double Circle::getPerimeter(){ 
    return M_PI * 2 * sideLength; 
} 
double Circle::getCircumference(){ 
    return getPerimeter(); 
} 
const char* Circle::getShapeName(){ 
    return getName(); 
} 
 
//Square 
Square::Square(double sideLength) : Shape("Square"), TwoDShape(sideLength) {}
 
double Square::getSideLength() { 
    return sideLength; 
} 
 
void Square::setSideLength(double sideLength) { 
    this->sideLength = sideLength; 
} 
 
double Square::getArea() { 
    return sideLength * sideLength; 
} 
 
double Square::getPerimeter() { 
    return 4 * sideLength; 
} 
 
const char* Square::getShapeName() { 
    return getName(); 
} 
 
//Perfect triangle 
Triangle::Triangle(double sideLength) : Shape("Triangle"), TwoDShape(sideLength) {}
 
double Triangle::getSideLength() { 
    return sideLength; 
} 
 
void Triangle::setSideLength(double sideLength) { 
    this->sideLength = sideLength; 
} 
 
double Triangle::getArea() { 
    return (sideLength * calculateHeight()) / 2; 
} 
 
double Triangle::getPerimeter() { 
    return 3 * sideLength; 
} 
 
const char* Triangle::getShapeName() { 
    return getName(); 
} 
 
double Triangle::calculateHeight() { 
    return (sqrt(3) / 2) * sideLength; 
} 