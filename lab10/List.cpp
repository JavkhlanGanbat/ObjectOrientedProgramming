#include "List.hpp"
#include "shapes.hpp"
#include <iostream>
using namespace std;

template <typename T>
List<T>::List() : head(nullptr), len(0) {}

template <typename T>
List<T>::~List() {
    while (head) {
        Node<T>* tmp = head;
        head = head->next;
        delete tmp;
    }
}

template <typename T>
void List<T>::add(T* obj) {
    Node<T>* newNd = new Node<T>(obj);
    if (!head) {
        head = newNd;
    } else {
        Node<T>* tmp = head;
        while (tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = newNd;
    }
    len++;
}

template <typename T>
void List<T>::insert(T* obj, int index) {
    if (index < 0 || index > len) {
        cout << "No." << endl;
        return;
    }

    Node<T>* newNd = new Node<T>(obj);

    if (index == 0) {
        newNd->next = head;
        head = newNd;
    } else {
        Node<T>* tmp = head;
        for (int i = 0; i < index - 1; i++) {
            tmp = tmp->next;
        }
        newNd->next = tmp->next;
        tmp->next = newNd;
    }
    len++;
}

template <typename T>
T* List<T>::get(int index) {
    if (index < 0 || index >= len) {
        cout << "No." << endl;
        return nullptr;
    }

    Node<T>* tmp = head;
    for (int i = 0; i < index; i++) {
        tmp = tmp->next;
    }
    return tmp->data;
}

template <typename T>
void List<T>::remove(int index) {
    if (index < 0 || index >= len) {
        cout << "No." << endl;
        return;
    }

    Node<T>* tmp = head;

    if (index == 0) {
        head = head->next;
        delete tmp;
    } else {
        Node<T>* prev = nullptr;
        for (int i = 0; i < index; i++) {
            prev = tmp;
            tmp = tmp->next;
        }
        prev->next = tmp->next;
        delete tmp;
    }
    len--;
}

template <typename T>
int List<T>::length() {
    return len;
}

template <typename T>
void List<T>::display() const {
    Node<T>* tmp = head;
    int index = 0;
    cout << "\n";
    while (tmp) {
        cout << index << " -> Shape: " << tmp->data->getName() 
             << ", Area: " << tmp->data->getArea()
             << ", Perimeter: " << tmp->data->getPerimeter() << endl;
        tmp = tmp->next;
        index++;
    }
}

template class List<TwoDShape>;
