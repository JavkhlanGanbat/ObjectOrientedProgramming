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
        virtual double getPerimeter() = 0;
        virtual double getArea() = 0;
};
 
class TwoDimensionalShape : virtual public Shape{ 
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
        TwoDimensionalShape(double x=0, double y=0, double sideLength=0,const 
char* name="EMPTY"); 
        virtual double getArea() = 0; 
}; 
 
class Circle : public TwoDimensionalShape{ 
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
 
class Square : public TwoDimensionalShape { 
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
 
class Triangle : public TwoDimensionalShape { 
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
TwoDimensionalShape::TwoDimensionalShape(double x, double y, double sideLength, 
const char* name): Shape(name){ 
    setX(x); 
    setY(y); 
    setSideLength(sideLength); 
} 
 
//returns length of the side 
double TwoDimensionalShape::getSideLength(){ 
    return this->sideLength; 
} 
 
//returns X 
double TwoDimensionalShape::getX(){ 
    return this->x; 
} 
 
//returns Y 
double TwoDimensionalShape::getY(){ 
    return this->y; 
} 
 
//sets side length 
void TwoDimensionalShape::setSideLength(double sideLength){ 
    this->sideLength=sideLength; 
} 
 
//sets X 
void TwoDimensionalShape::setX(double x){ 
    this->x=x; 
} 
 
//sets Y 
void TwoDimensionalShape::setY(double y){ 
    this->y=y; 
} 
 
//Circle 
Circle::Circle(double x, double y, double radius): 
TwoDimensionalShape(x,y,radius), Shape("Circle"){ 
     
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
TwoDimensionalShape(x,y,sideLength), Shape("Square"){ 
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
 
// Top-left corner (original center point) 
double Square::getTopLeftX() { 
    return getX(); 
} 
 
double Square::getTopLeftY() { 
    return getY(); 
} 
 
// Top-right corner 
double Square::getTopRightX() { 
    return getX() + sideLength; 
} 
 
double Square::getTopRightY() { 
    return getY(); 
} 
 
// Bottom-left corner 
double Square::getBottomLeftX() { 
    return getX(); 
} 
 
double Square::getBottomLeftY() { 
    return getY() - sideLength; 
} 
 
// Bottom-right corner 
double Square::getBottomRightX() { 
    return getX() + sideLength; 
} 
 
double Square::getBottomRightY() { 
    return getY() - sideLength; 
} 
 
void Square::setTopLeftX(double x) { 
    setX(x); 
} 
 
void Square::setTopLeftY(double y) { 
    setY(y); 
} 
 
void Square::setTopRightX(double x){ 
    setX(x-sideLength); 
} 
 
void Square::setTopRightY(double y){ 
    setY(y); 
} 
 
void Square::setBottomLeftX(double x){ 
    setX(x); 
} 
 
void Square::setBottomLeftY(double y){ 
    setY(y+sideLength); 
} 
 
void Square::setBottomRightX(double x){ 
    setX(x-sideLength); 
} 
 
void Square::setBottomRightY(double y){ 
    setY(y+sideLength); 
} 
 
//Perfect Triangle 
 
Triangle::Triangle(double x, double y, double sideLength) : 
TwoDimensionalShape(x,y,sideLength), Shape("Perfect Triangle"){ 
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
 
// Calculate the height of the equilateral triangle 
double Triangle::calculateHeight() { 
    return (sqrt(3) / 2) * sideLength; 
} 
 
// Top vertex (main point) 
double Triangle::getTopX() { 
    return getX(); 
} 
 
double Triangle::getTopY() { 
    return getY(); 
} 
 
// Bottom-left vertex 
double Triangle::getBottomLeftX() { 
    return getX() - (sideLength / 2); 
} 
 
double Triangle::getBottomLeftY() { 
    return getY() - calculateHeight(); 
} 
 
// Bottom-right vertex 
double Triangle::getBottomRightX() { 
    return getX() + (sideLength / 2); 
} 
 
double Triangle::getBottomRightY() { 
    return getY() - calculateHeight(); 
} 
 
// Setters for the top vertex, split by x and y 
void Triangle::setTopX(double x) { 
    setX(x); 
} 
 
void Triangle::setTopY(double y) { 
    setY(y); 
} 
 
void Triangle::setBottomLeftX(double x){ 
    setX(x + (sideLength / 2)); 
} 
 
void Triangle::setBottomLeftY(double y){ 
    setY(y + calculateHeight()); 
} 
 
void Triangle::setBottomRightX(double x){ 
    setX(x - (sideLength / 2)); 
} 
 
void Triangle::setBottomRightY(double y){ 
    setY(y + calculateHeight()); 
} 
 