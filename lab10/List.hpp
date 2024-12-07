#pragma once
#include <iostream>

template <typename T>

class Node {
public:
    T* data;
    Node* next;

    Node(T* data) : data(data), next(nullptr) {}
    ~Node() { delete data; }
};

template <typename T>

class LinkedList {
private:
    Node<T>* head;
    int len;

public:
    LinkedList();
    ~LinkedList();

    void add(T* shape);
    void insert(T* shape, int index);
    T* get(int index);
    void remove(int index);
    int length();
    void display() const;
};
