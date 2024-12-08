#pragma once

template <typename T>

class Node {
public:
    T* data;
    Node* next;

    Node(T* data) : data(data), next(nullptr) {}
    ~Node() { delete data; }
};

template <typename T>

class List {
private:
    Node<T>* head;
    int len;

public:
    List();
    ~List();

    void add(T* obj);
    void insert(T* obj, int index);
    T* get(int index);
    void remove(int index);
    int length();
    void display() const;
};
