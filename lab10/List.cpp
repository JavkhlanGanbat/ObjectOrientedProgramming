#include "List.hpp"
#include "shapes.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
List<T>::List() : head(nullptr), len(0){} //constructor

template <typename T> //destructor
List<T>::~List(){
    while (head){
        Node<T>* tmp = head;
        head = head->next;
        delete tmp;
    }
}

template <typename T> //push_front uildel
void List<T>::add(T* obj){
    Node<T>* newNd = new Node<T>(obj);
    if (!head){
        head = newNd;
    } else{
        Node<T>* tmp = head;
        while (tmp->next){
            tmp = tmp->next;
        }
        tmp->next = newNd;
    }
    len++;
}

template <typename T>
void List<T>::insert(T* obj, int index){ // i index-d shine zangilaa oruulah
    if (index < 0 || index > len){
        cout << "No." << "\n";
        return;
    }

    Node<T>* newNd = new Node<T>(obj);

    if (index == 0){
        newNd->next = head;
        head = newNd;
    } else{
        Node<T>* tmp = head;
        for (int i = 0; i < index - 1; i++){ // i-s hoish baiga zangilaanuudiig hoishluulah
            tmp = tmp->next;
        }
        newNd->next = tmp->next;
        tmp->next = newNd;
    }
    len++;
}

template <typename T>
T* List<T>::getInfo(int index){
    if (index < 0 || index >= len){ // range check
        cout << "No." << "\n";
        return nullptr;
    }

    Node<T>* tmp = head;
    for (int i = 0; i < index; i++){
        tmp = tmp->next;
    }
    return tmp->data;
}

template <typename T>
void List<T>::remove(int index){
    if (index < 0 || index >= len){ // range check
        cout << "No." << "\n";
        return;
    }

    Node<T>* tmp = head;

    if (index == 0){
        head = head->next; // ehnii elem-g ustgah tohioldold
        delete tmp;
    } else{
        Node<T>* prev = nullptr;
        for (int i = 0; i < index; i++){ // index-s hoish bga zangilaanuudiig 1-eer uragshluulah
            prev = tmp;
            tmp = tmp->next;
        }
        prev->next = tmp->next;
        delete tmp;
    }
    len--;
}

template <typename T>
int List<T>::length(){
    return len;
}

template <typename T>
void List<T>::display() const{
    if (len == 0){ // range check
        cout << "The list is empty." << "\n";
        return;
    }

    cout << "\n" 
         << left << setw(10) << "Index" 
         << left << setw(15) << "Shape" 
         << left << setw(15) << "A" 
         << "P" << "\n" << "\n";

    Node<T>* tmp = head;
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

template <typename T>
void List<T>::sortByArea(){
    if (!head || !head->next) return;
    
    bool swapped;
    Node<T>* crnt;
    Node<T>* last = nullptr;
    
    do{
        swapped = false;
        crnt = head;
        
        while (crnt->next != last){
            if (crnt->data->getArea() > crnt->next->data->getArea()){
                T* temp = crnt->data;
                crnt->data = crnt->next->data;
                crnt->next->data = temp;
                swapped = true;
            }
            crnt = crnt->next;
        }
        last = crnt;
    } while (swapped);
}

template class List<TwoDShape>;