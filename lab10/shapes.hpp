#pragma once 

class Shape {
    protected:
        char* name;
    public:
        Shape(const char* name = "");
        Shape(const Shape& other);
        Shape& operator=(const Shape& other);
        virtual ~Shape();
        void setName(const char* name);
        const char* getName();
};

class TwoDShape : virtual public Shape{ 
    protected: 
        double sideLength; 
    public: 
        double getSideLength();  
        void setSideLength(double sideLength); 
        TwoDShape(double sideLength = 0, const char* name = "o"); 
        virtual double getArea() = 0; 
        virtual double getPerimeter() = 0;
}; 
 
class Circle : public TwoDShape{ 
    public: 
        Circle(double radius = 0); 
        double getRadius(); 
        void setRadius(double radius);  
        double getCircumference(); 
        double getArea() override; 
        double getPerimeter() override; 
        const char* getShapeName(); 
}; 
 
class Square : public TwoDShape { 
    public: 
        Square(double sideLength = 0); 
        double getSideLength(); 
        void setSideLength(double sideLength); 
        double getArea() override; 
        double getPerimeter() override; 
        const char* getShapeName(); 

}; 
 
class Triangle : public TwoDShape { 
    public: 
        Triangle(double sideLength = 0); 
        double getSideLength(); 
        void setSideLength(double sideLength); 
        double getArea() override; 
        double getPerimeter() override; 
        const char* getShapeName(); 
    
    private: 
        double calculateHeight(); 
};
