#include "shapes.hpp"
#include "List.hpp"
#include <iomanip>
#include <cstdlib>
#include <ctime> 
using namespace std;

// Display function
template <typename T>
void display(List<T>& list){
    if (list.length() == 0){ 
        cout << "The list is empty.\n";
        return;
    }

    cout << "\n"
         << left << setw(10) << "Index"
         << left << setw(15) << "Shape"
         << left << setw(15) << "Area"
         << "Perimeter" << "\n\n";

    Node<T>* tmp = list.getHead();
    int index = 0;
    while (tmp){
        cout << left << index << setw(9) << " ->"
             << left << setw(15) << tmp->data->getName()
             << left << setw(15) << fixed << setprecision(2) << tmp->data->getArea()
             << tmp->data->getPerimeter() << "\n";

        tmp = tmp->next;
        index++;
    }
}

// Sorting function
template <typename T>
void sortByArea(List<T>& list){
    if (!list.getHead() || !list.getHead()->next) return;

    bool swapped;
    Node<T>* c;
    Node<T>* last = nullptr;

    do {
        swapped = false;
        c = list.getHead();

        while (c->next != last){
            if (c->data->getArea() > c->next->data->getArea()){
                T temp = c->data;
                c->data = c->next->data;
                c->next->data = temp;
                swapped = true;
            }
            c = c->next;
        }
        last = c;
    } while (swapped);
}

int main(){
    srand(time(0)); // rand num generator

    List<TwoDShape*> shapes;

    // 30 random shapes
    for (int i = 0; i < 30; ++i){
        int shapeType = rand() % 3;
        double randomSize = (rand() % 10 + 1) + (rand() % 100) / 100.0;

        if (shapeType == 0){
            shapes.add(new Circle(randomSize));
        } else if (shapeType == 1){
            shapes.add(new Square(randomSize));
        } else {
            shapes.add(new Triangle(randomSize));
        }
    }

    cout << "Original list:\n";
    display(shapes);

    sortByArea(shapes);

    cout << "\nSorted list (area):\n";
    display(shapes);

    cout << "Jagsaaltiin tugsguld rad = 5 Circle objectiig nemj baina " << endl;
    shapes.add(new Circle(5));
    display(shapes);

    cout << "Jagsaaltiin ehnii elementiig ustgaj baina " << endl;
    shapes.deleteNode(0);
    display(shapes);
    return 0;
}


