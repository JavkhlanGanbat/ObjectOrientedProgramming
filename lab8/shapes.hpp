#pragma once

#include <iostream>
#include <vector>
#include <math.h> 
#include <cstring> 

using namespace std; 

class Shape {
    protected:
        char* name;
        static int ObjCount;
    public:
        Shape(const char* name = "");
        Shape(const Shape& other);
        Shape& operator=(const Shape& other);
        virtual ~Shape();
        void setName(const char* name);
        const char* getName();
        static int getObjCount();
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
        TwoDShape(double x = 0, double y = 0, double sideLength = 0, const char* name = "o"); 
        virtual double getArea() = 0; 
        virtual double getPerimeter() = 0;
}; 
 
class Circle : public TwoDShape{ 
    public: 
        Circle(double x = 0, double y = 0, double radius = 0); 
        double getRadius(); 
        void setRadius(double radius); 
        void setCenterX(double x); 
        void setCenterY(double y); 
        double getCenterX(); 
        double getCenterY(); 
        double getCircumference(); 
        double getArea() override; 
        double getPerimeter() override; 
        const char* getShapeName(); 
}; 
 
class Square : public TwoDShape { 
    public: 
        Square(double x = 0, double y = 0, double sideLength = 0); 
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
}; 
 
class Triangle : public TwoDShape { 
    public: 
        Triangle(double x = 0, double y = 0, double sideLength = 0); 
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
    
    private: 
        double calculateHeight(); 
};
