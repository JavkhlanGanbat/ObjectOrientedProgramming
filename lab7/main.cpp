#include "shapes.hpp"
#include <vector>
#include <iostream>

int main() {
    std::vector<Shape*> shapes;
    bool running = true;

    while (running) {
        std::cout << "\nChoose a shape to create (\n1 = Circle\n2 = Square\n3 = Triangle\n4 = Print objects\n5 = Sort objects by area\n0 = Exit\n): ";
        int choice;
        std::cin >> choice;

        Shape* newShape = nullptr;

        switch (choice) {
            case 1: {
                double x, y, radius;
                std::cout << "Enter x, y coordinates and radius: ";
                std::cin >> x >> y >> radius;
                newShape = new Circle(x, y, radius);
                break;
            }
            case 2: {
                double x, y, sideLength;
                std::cout << "Enter x, y coordinates and side length: ";
                std::cin >> x >> y >> sideLength;
                newShape = new Square(x, y, sideLength);
                break;
            }
            case 3: {
                double x, y, sideLength;
                std::cout << "Enter x, y coordinates and side length: ";
                std::cin >> x >> y >> sideLength;
                newShape = new Triangle(x, y, sideLength);
                break;
            }
            case 4:
                std::cout << "Printing all objects:\n";
                for (Shape* shape : shapes) {
                    shape->print();
                }
                continue;
            case 5:
                for (int i = 0; i < shapes.size(); ++i) {
                    for (int j = 0; j < shapes.size() - i - 1; ++j) {
                        if (shapes[j]->getArea() > shapes[j + 1]->getArea()) {
                            std::swap(shapes[j], shapes[j + 1]);
                        }
                    }
                }
                std::cout << "Sorted by area.\n";
                break;
            case 0:
                running = false;
                break;  
            default:
                std::cout << "Try again." << std::endl;
                continue;
        }

        if (newShape) {
            shapes.push_back(newShape);
            std::cout << "\nCreated " << newShape->getName() << " at ("
                      << newShape->getX() << ", " << newShape->getY() << ") with side length "
                      << newShape->getSideLength() << "\n";
        }
    }

    for (auto shape : shapes) {
        delete shape;
    }

    return 0;
}
