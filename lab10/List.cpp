#include "List.hpp"
#include "shapes.hpp"

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), count(0) {}

template <typename T>
LinkedList<T>::~LinkedList() {
    while (head) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void LinkedList<T>::add(T* shape) {
    Node<T>* newNode = new Node<T>(shape);
    if (!head) {
        head = newNode;
    } else {
        Node<T>* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    count++;
}

template <typename T>
void LinkedList<T>::insert(T* shape, int index) {
    if (index < 0 || index > count) {
        cout << "Invalid index!" << endl;
        return;
    }

    Node<T>* newNode = new Node<T>(shape);

    if (index == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        Node<T>* temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    count++;
}

template <typename T>
T* LinkedList<T>::get(int index) {
    if (index < 0 || index >= count) {
        cout << "Invalid index!" << endl;
        return nullptr;
    }

    Node<T>* temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp->data;
}

template <typename T>
void LinkedList<T>::remove(int index) {
    if (index < 0 || index >= count) {
        cout << "Invalid index!" << endl;
        return;
    }

    Node<T>* temp = head;

    if (index == 0) {
        head = head->next;
        delete temp;
    } else {
        Node<T>* prev = nullptr;
        for (int i = 0; i < index; i++) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        delete temp;
    }
    count--;
}

template <typename T>
int LinkedList<T>::length() {
    return count;
}

template <typename T>
void LinkedList<T>::display() const {
    Node<T>* temp = head;
    int index = 0;
    while (temp) {
        cout << "Index " << index << " -> Shape: " << temp->data->getName() 
             << ", Area: " << temp->data->getArea()
             << ", Perimeter: " << temp->data->getPerimeter() << endl;
        temp = temp->next;
        index++;
    }
}

template class LinkedList<TwoDShape>;
