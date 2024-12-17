#pragma once 
#include <iostream>
#include <stdexcept>
#include "shapes.hpp"

// zangilaa struct
template <typename T>
struct Node {
    T data;
    Node* next;

    Node(T val) : data(val), next(nullptr){}
};

// zagvar linkedlist class
template <typename T>
class LinkedList {
private:
    Node<T>* head;
    int size; // jagsaaltiin urt

public:
    LinkedList() : head(nullptr), size(0){}

    // push_back functs
    void add(T t){
        Node<T>* newNode = new Node<T>(t);
        if (!head){
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->next){
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    // duriin indexd element oruulah functs
    void insert(int index){
        if (index < 0 || index > size){
            throw std::out_of_range("Index out of bounds");
        }

        T t;
        std::cout << "Enter the value to insert: ";
        std::cin >> t;

        Node<T>* newNode = new Node<T>(t);

        if (index == 0){
            newNode->next = head;
            head = newNode;
        } else {
            Node<T>* temp = head;
            for (int i = 0; i < index - 1; ++i){
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        size++;
    }


    // duriin indexd baigaa elementiin medeelliig avah functs
    T& get(int index){
        if (index < 0 || index >= size){
            throw std::out_of_range("Index out of bounds");  // Use std::out_of_range
        }

        Node<T>* temp = head;
        for (int i = 0; i < index; ++i){
            temp = temp->next;
        }
        return temp->data;
    }

    // durin indexd baigaa elementiig ustgah functs
    void deleteNode(int index){
        if (index < 0 || index >= size){
            throw std::out_of_range("Index out of bounds");  // Use std::out_of_range
        }

        Node<T>* toDelete = nullptr;
        if (index == 0){
            toDelete = head;
            head = head->next;
        } else {
            Node<T>* temp = head;
            for (int i = 0; i < index - 1; ++i){
                temp = temp->next;
            }
            toDelete = temp->next;
            temp->next = temp->next->next;
        }
        delete toDelete;
        size--;
    }

    // jagsaaltiin urtiig butsaah functs
    int length() const {
        return size;
    }

    // jagsaaltiig hevleh functs
    void print() const {
        Node<T>* temp = head;
        while (temp){
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }

    // jagsaaltiin ehnii element (head)-g avah functs
    Node<T>* getHead() const {
        return head;
    }

    // jagsaaltiin ehnii element (head)-g todorhoiloh functs
    void setHead(Node<T>* newHead){
        head = newHead;
    }
};
