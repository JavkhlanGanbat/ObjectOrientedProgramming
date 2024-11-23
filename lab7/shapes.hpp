#include <iostream>
#include <vector>
#include <math.h> 
#include <cstring> 
using namespace std; 

class Shape {
    protected:
        char* name;
    public:
        Shape(const char* name = "");
        virtual ~Shape();
        void setName(const char* name);
        const char* getName();
};
 
class TwoDShape : virtual public Shape{ 
    protected: 
        double x; 
        double y; 
        double sideLength; 
    public: 
        double getSideLength(); 
        double getX(); 
        double getY(); 
        void setSideLength(double sideLength); 
        void setX(double x); 
        void setY(double y); 
        TwoDShape(double x=0, double y=0, double sideLength=0, const char* name="o"); 
        virtual double getArea() = 0; 
        virtual double getPerimeter() = 0;
}; 
 
class Circle : public TwoDShape{ 
    private: 
        double getPerimeter() override; 
    public: 
        Circle(double x=0, double y=0, double radius=0); 
        double getRadius(); 
        void setRadius(double radius); 
        void setCenterX(double x); 
        void setCenterY(double y); 
        double getCenterX(); 
        double getCenterY(); 
        double getCircumference(); 
        double getArea() override; 
        const char* getShapeName(); 
}; 
 
class Square : public TwoDShape { 
public: 
    Square(double x=0, double y=0, double sideLength=0); 
    double getSideLength(); 
    void setSideLength(double sideLength); 
    double getArea() override; 
    double getPerimeter() override; 
    const char* getShapeName(); 
 
    double getTopLeftX(); 
    double getTopLeftY(); 
    double getTopRightX(); 
    double getTopRightY(); 
    double getBottomLeftX(); 
    double getBottomLeftY(); 
    double getBottomRightX(); 
    double getBottomRightY(); 
 
    void setTopLeftX(double x); 
    void setTopLeftY(double y); 
    void setTopRightX(double x); 
    void setTopRightY(double y); 
    void setBottomLeftX(double x); 
    void setBottomLeftY(double y); 
    void setBottomRightX(double x); 
    void setBottomRightY(double y); 
}; 
 
class Triangle : public TwoDShape { 
public: 
    Triangle(double x=0, double y=0, double sideLength=0); 
    double getSideLength(); 
    void setSideLength(double sideLength); 
    double getArea() override; 
    double getPerimeter() override; 
    const char* getShapeName(); 
 
    double getTopX(); 
    double getTopY(); 
    double getBottomLeftX(); 
    double getBottomLeftY(); 
    double getBottomRightX(); 
    double getBottomRightY(); 
 
    void setTopX(double x); 
    void setTopY(double y); 
    void setBottomLeftX(double x); 
    void setBottomLeftY(double y); 
    void setBottomRightX(double x); 
    void setBottomRightY(double y); 
 
private: 
    double calculateHeight(); 
};
 
Shape::Shape(const char* name){ 
    this->name = new char[strlen(name)+1]; 
    strcpy(this->name,name); 
} 
 
//deconstructor 
Shape::~Shape(){ 
    if(name) 
        delete name; 
} 
 
const char* Shape::getName(){ 
    return (const char*)name; 
} 
 
void Shape::setName(const char* name){ 
    if(this->name!=NULL) 
        delete this->name; 
    this->name = new char[strlen(name)+1]; 
    strcpy(this->name,name); 
} 
 
//2d shape
TwoDShape::TwoDShape(double x, double y, double sideLength, 
const char* name): Shape(name){ 
    setX(x); 
    setY(y); 
    setSideLength(sideLength); 
} 
 
//returns length of the side 
double TwoDShape::getSideLength(){ 
    return this->sideLength; 
} 
 
//returns X 
double TwoDShape::getX(){ 
    return this->x; 
} 
 
//returns Y 
double TwoDShape::getY(){ 
    return this->y; 
} 
 
//sets side length 
void TwoDShape::setSideLength(double sideLength){ 
    this->sideLength=sideLength; 
} 
 
//sets X 
void TwoDShape::setX(double x){ 
    this->x=x; 
} 
 
//sets Y 
void TwoDShape::setY(double y){ 
    this->y=y; 
} 
 
//Circle 
Circle::Circle(double x, double y, double radius): 
TwoDShape(x,y,radius), Shape("Circle"){ 
     
} 
 
double Circle::getRadius(){ 
    return sideLength; 
} 
void Circle::setRadius(double radius){ 
    setSideLength(radius); 
} 
void Circle::setCenterX(double x){ 
    setX(x); 
} 
void Circle::setCenterY(double y){ 
    setY(y); 
} 
double Circle::getArea(){ 
    return M_PI*sideLength*sideLength; 
} 
double Circle::getPerimeter(){ 
    return M_PI*2*sideLength; 
} 
double Circle::getCircumference(){ 
    return getPerimeter(); 
} 
const char* Circle::getShapeName(){ 
    return getName(); 
} 
double Circle::getCenterX(){ 
    return getX(); 
} 
double Circle::getCenterY(){ 
    return getY(); 
} 
 
//Square 
Square::Square(double x, double y, double sideLength) : 
TwoDShape(x,y,sideLength), Shape("Square"){ 
} 
 
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
 
// Top-left corner
double Square::getTopLeftX() { 
    return getX() - (sideLength / 2); 
} 

double Square::getTopLeftY() { 
    return getY() + (sideLength / 2); 
} 

// Top-right corner 
double Square::getTopRightX() { 
    return getX() + (sideLength / 2); 
} 

double Square::getTopRightY() { 
    return getY() + (sideLength / 2); 
} 

// Bottom-left corner 
double Square::getBottomLeftX() { 
    return getX() - (sideLength / 2); 
} 

double Square::getBottomLeftY() { 
    return getY() - (sideLength / 2); 
} 

// Bottom-right corner 
double Square::getBottomRightX() { 
    return getX() + (sideLength / 2); 
} 

double Square::getBottomRightY() { 
    return getY() - (sideLength / 2); 
} 
 
//Perfect triangle 
Triangle::Triangle(double x, double y, double sideLength) : 
TwoDShape(x,y,sideLength), Shape("Triangle"){ 
} 
 
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
 
// Top vertex
double Triangle::getTopX() { 
    return getX(); 
} 

double Triangle::getTopY() { 
    return getY() + (calculateHeight() / 2); 
} 

// Bottom-left vertex 
double Triangle::getBottomLeftX() { 
    return getX() - (sideLength / 2); 
} 

double Triangle::getBottomLeftY() { 
    return getY() - (calculateHeight() / 2); 
} 

// Bottom-right vertex 
double Triangle::getBottomRightX() { 
    return getX() + (sideLength / 2); 
} 

double Triangle::getBottomRightY() { 
    return getY() - (calculateHeight() / 2); 
} 
 