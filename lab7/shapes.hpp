#include <cstring>
#include <cmath>
#include <iostream>

class Shape {
protected:
    double x, y, sideLength;
    char* name;

public:
    Shape(double x = 0, double y = 0, double sideLength = 0, const char* name = "");
    Shape(const Shape& other);
    Shape& operator=(const Shape& other);
    virtual ~Shape();

    virtual double getArea() const = 0;
    
    double getSideLength() const;
    double getX() const;
    double getY() const;
    void setSideLength(double sideLength);
    void setX(double x);
    void setY(double y);
    void setName(const char* name);
    const char* getName() const;
    
    virtual void print() const;
};

class TwoDimensionalShape : public Shape {
protected:
    int numOfSides;

public:
    TwoDimensionalShape(double x = 0, double y = 0, double sideLength = 0, const char* name = "twodshape", int numOfSides = 1);
    virtual ~TwoDimensionalShape();
    
    int getNumOfSides() const;
    void setNumOfSides(int numOfSides);
    void print() const override;
};

class Circle : public TwoDimensionalShape {
public:
    Circle(double x = 0, double y = 0, double radius = 0);
    
    double getRadius() const;
    void setRadius(double radius);
    double getArea() const;
    double getCircumference() const;
    void print() const override;
};

class Square : public TwoDimensionalShape {
public:
    Square(double x = 0, double y = 0, double sideLength = 0);
    
    double getArea() const;
    double getPerimeter() const;
    void print() const override;
};

class Triangle : public TwoDimensionalShape {
public:
    Triangle(double x = 0, double y = 0, double sideLength = 0);
    
    double getArea() const;
    double getPerimeter() const;
    void print() const override;

private:
    double calculateHeight() const;
};

// Shape class implementation

Shape::Shape(double x, double y, double sideLength, const char* name) : x(x), y(y), sideLength(sideLength) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

Shape::~Shape() {
    delete[] name;
}

double Shape::getSideLength() const { return sideLength; }
double Shape::getX() const { return x; }
double Shape::getY() const { return y; }

void Shape::setSideLength(double sideLength) { this->sideLength = sideLength; }
void Shape::setX(double x) { this->x = x; }
void Shape::setY(double y) { this->y = y; }

void Shape::setName(const char* name) {
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}
Shape::Shape(const Shape& other) : x(other.x), y(other.y), sideLength(other.sideLength) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
}

Shape& Shape::operator=(const Shape& other) {
    if (this != &other) {
        delete[] name;
        x = other.x;
        y = other.y;
        sideLength = other.sideLength;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }
    return *this;
}

const char* Shape::getName() const { return name; }

void Shape::print() const {
    std::cout << "Shape: " << name << ", Position: (" << x << ", " << y << "), Side length: " << sideLength << std::endl;
}

// 2DShape class

TwoDimensionalShape::TwoDimensionalShape(double x, double y, double sideLength, const char* name, int numOfSides)
    : Shape(x, y, sideLength, name), numOfSides(numOfSides) {}

TwoDimensionalShape::~TwoDimensionalShape() {}

int TwoDimensionalShape::getNumOfSides() const { return numOfSides; }

void TwoDimensionalShape::setNumOfSides(int numOfSides) {
    this->numOfSides = numOfSides > 0 ? numOfSides : 1;
}

void TwoDimensionalShape::print() const {
    Shape::print();
    std::cout << "Number of sides: " << numOfSides << std::endl;
}

// Circle class

Circle::Circle(double x, double y, double radius) : TwoDimensionalShape(x, y, radius, "Circle", 1) {}

double Circle::getRadius() const { return sideLength; }
void Circle::setRadius(double radius) { setSideLength(radius); }

double Circle::getArea() const { return M_PI * sideLength * sideLength; }
double Circle::getCircumference() const { return 2 * M_PI * sideLength; }

void Circle::print() const {
    std::cout << "Circle: Center: (" << getX() << ", " << getY() << "), Radius: " << getRadius()
              << ", Area: " << getArea() << ", Circumference: " << getCircumference() << std::endl;
}

// Square class

Square::Square(double x, double y, double sideLength) : TwoDimensionalShape(x, y, sideLength, "Square", 4) {}

double Square::getArea() const { return sideLength * sideLength; }
double Square::getPerimeter() const { return 4 * sideLength; }

void Square::print() const {
    std::cout << "Square: Position: (" << getX() << ", " << getY() << "), Side Length: " << getSideLength()
              << ", Area: " << getArea() << ", Perimeter: " << getPerimeter() << std::endl;
}

// Triangle class

Triangle::Triangle(double x, double y, double sideLength) : TwoDimensionalShape(x, y, sideLength, "Triangle", 3) {}

double Triangle::getArea() const { return (sideLength * calculateHeight()) / 2; }
double Triangle::getPerimeter() const { return 3 * sideLength; }

double Triangle::calculateHeight() const { return (sqrt(3) / 2) * sideLength; }

void Triangle::print() const {
    std::cout << "Triangle: Position: (" << getX() << ", " << getY() << "), Side length: " << getSideLength()
              << ", Area: " << getArea() << ", Perimeter: " << getPerimeter() << std::endl;
}
