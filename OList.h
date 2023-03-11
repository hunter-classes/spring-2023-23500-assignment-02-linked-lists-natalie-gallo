#pragma once
#include <iostream>
#include "Node.h"

class OList{
private:
    Node *head;
public:
    OList(); //contructor
    ~OList(); //destructor
    void insert(std::string data); //insert a new node with value into the list in its proper location
    int length();
    
    std::string toString(); // for testing purposes: return a string representation of the full list
    bool contains(std::string item);
    std::string get(int loc);
    void remove(int loc);
    void reverse(); //This should “reverse” the list - that is reverse the pointers

    //for doctest
    bool emptyList(){
        if (head == nullptr){
            return true;
        } else {
        return false;
        }
    }
};