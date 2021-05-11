#ifndef LAB2_LINKEDLIST_H
#define LAB2_LINKEDLIST_H
#include <stdexcept>
#include <string>
#include <sstream>
#pragma once
#endif //LAB2_LINKEDLIST_H
using namespace std;
const string INDEX_OUT_OF_RANGE = "Index out of range";
const string SIZE_LESS_0 = "Size is less than 0";


template <typename T> class Node{
public:
    T value;
    Node<T>* next_el;

    Node(){
        value = 0;
        next_el = nullptr;
    };
    Node(T value, Node<T>* next_el){
        this->value = value;
        this->next_el = next_el;
    };
};

template <typename T> class LinkedList {
private:
    Node<T>* head = nullptr;
    int size;
    int cap;
public:
    //Constructor

    LinkedList(){
        size = 0;
        cap = 0;
        head = nullptr;
    }
    LinkedList(int size){
        this->size = size;
        cap = cap;
        head = nullptr;
    }
    LinkedList(T* items, int count){
        if (count < 0){
            throw length_error(SIZE_LESS_0);
        };
        for(int i = 0; i < count; i++){
            Append(items[i]);
        };
    };
    LinkedList(const LinkedList<T>& list){
        for (int i = 0; i < list.GetLength(); i++){
            this->Append(list.Get(i));
        }
    };
    LinkedList(LinkedList<T>* list){
        head = list->head;
        size = list->size;
        cap = list->cap;
    }
    //Destructor
    ~LinkedList(){
        Delete_LinkedList();
    };
    void Delete_LinkedList(){
        Node<T>* buf = new Node<T>();
        head = nullptr;
        while (head != nullptr){
            buf = head;
            delete buf;
            head = head->next_el;
        }
        size = 0;
        cap = 0;
    }

    //Decomposition
    T GetFirst() const{
        if (head == nullptr){
            throw out_of_range(INDEX_OUT_OF_RANGE);
        }
        return head->value;
    };
    T GetLast() const{
        if (head == nullptr){
            throw out_of_range(INDEX_OUT_OF_RANGE);
        }
        return Get(size-1);
    };
    T Get(int index) const{
        if (index < 0 || index >= size){
            throw out_of_range(INDEX_OUT_OF_RANGE);
        }
        Node<T>* buff = head;
        for(int i = 0; i < index; i++){
            buff = buff->next_el;
        }
        return buff->value;
    };
    LinkedList<T>* GetSublist(int start, int end){
        if (start >= size || end >= size || start < 0 || end < 0){
            throw out_of_range(INDEX_OUT_OF_RANGE);
        }

        LinkedList<T>* new_list = new LinkedList<T>();
        for(int i = start; i < end; i++){
            new_list->Append(this->Get(i));
        }
        new_list->size = end - start;
        return new_list;
    };
    int GetLength() const{
        return size;
    };


    //Operations
    void Append(T value){
        Node<T>* newElem = new Node<T>;
        newElem->value = value;
        newElem->next_el = nullptr;
        if(head == nullptr) {
            head = newElem;
            size = 1;
            cap = 1;
            return;
        } else{
            Node<T>* buf;
            buf = head;
            //after while buf point on last el in list
            while(buf->next_el != nullptr){
                buf = buf->next_el;
            }
            size++;
            buf->next_el = newElem;
        }
    };
    void Prepend(T value){
        this->head = new Node<T>(value, this->head);
        size++;
    };
    void InsertAt(T value, int index){
        if(index < 0 || index > this->size){
            throw out_of_range("InsertAt : Index out of range");
        }
        Node<T>* buff = head;
        for(int i = 0; i < index-1; i++){
            buff = buff->next_el;
        }
        Node<T>* new_node = new Node<T>(value, buff->next_el);
        buff->next_el = new_node;
        size++;
    };
    void Set(T value, int index){
        if (index < 0 || index > size - 1)
            throw out_of_range(INDEX_OUT_OF_RANGE);
        Node<T>* buff = head;
        for (int i = 0; i < index; i++)
            buff = buff->next_el;
        buff->value = value;
    }
    LinkedList<T>* Concat(LinkedList<T>* list){
        LinkedList<T>* newList = new LinkedList<T>();
        newList->head = this->head;
        Node<T>* buff = this->head;
        for(int i = 0; i < this->GetLength() - 1; i++){
            buff = buff->next_el;
        };
        newList->size = list->size + this->size;
        buff->next_el = list->head;
        return newList;
    };


    //Operators
    Node<T>* operator[] (int index){
        if (index < 0 || index > this->size-1) {
            throw out_of_range(INDEX_OUT_OF_RANGE);
        }
        Node<T>* buff = head;
        for (int i = 0; i < index; i++) {
            buff = buff->next_el;
        }
        return buff;
    };

};
