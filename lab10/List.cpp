#include "List.hpp"
#include "shapes.hpp"
#include <iostream>
using namespace std;

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), len(0) {}

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
    len++;
}

template <typename T>
void LinkedList<T>::insert(T* shape, int index) {
    if (index < 0 || index > len) {
        cout << "No." << endl;
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
    len++;
}

template <typename T>
T* LinkedList<T>::get(int index) {
    if (index < 0 || index >= len) {
        cout << "No." << endl;
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
    if (index < 0 || index >= len) {
        cout << "No." << endl;
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
    len--;
}

template <typename T>
int LinkedList<T>::length() {
    return len;
}

template <typename T>
void LinkedList<T>::display() const {
    Node<T>* temp = head;
    int index = 0;
    cout << "\n";
    while (temp) {
        cout << index << " -> Shape: " << temp->data->getName() 
             << ", Area: " << temp->data->getArea()
             << ", Perimeter: " << temp->data->getPerimeter() << endl;
        temp = temp->next;
        index++;
    }
}

template class LinkedList<TwoDShape>;
