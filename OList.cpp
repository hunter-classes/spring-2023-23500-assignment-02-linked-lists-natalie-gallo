#include <iostream>
#include <string>
#include "Node.h"
#include "OList.h"

OList::OList(){ // constructor - creates a head (start of list) pointer
    head = nullptr;
}

OList::~OList(){ //destructor
    std::cerr << "Called the destructor\n";
    Node *walker, *trailer;
    walker = this->head;
    trailer = nullptr;

    while (walker!=nullptr){
        trailer = walker;
        walker = walker->getNext();
        delete trailer;
        trailer = nullptr;
    }
    delete walker;
    walker = nullptr;
    head = nullptr;
}

void OList::insert(std::string data){
    Node *walker, *trailer;
    walker = this->head; // start of the list
    trailer = nullptr;   // one behind

    if (walker == nullptr){ // first item in the list
        Node *tmp = new Node(data);
        tmp->setNext(head);
        head = tmp;
        return;
    }

    while (walker != nullptr){
        if (data > walker->getData()){
            trailer = walker;
            walker = walker->getNext();
        } else {
            break;
        }
    }

    Node *newNode = new Node(data);
    if (trailer == nullptr){
        newNode->setNext(head);
        head = newNode;
    } else {
        newNode->setNext(walker);
        trailer->setNext(newNode);
    }
}

int OList::length(){
    int count = 0;
    Node *walker = head;
    while (walker != nullptr){
        count++;
        walker = walker->getNext();
    }
    return count;
}

std::string OList::toString(){
    Node *tmp = this->head;
    std::string result = "";
    while (tmp != nullptr){
        result = result + tmp->getData();
        result = result + "-->";
        tmp = tmp->getNext();
    }
    result = result + "nullptr";
    return result;
}

bool OList::contains(std::string item){
    Node *walker = head;
    while (walker != nullptr){
        if (walker->getData() == item){
            return true;
        }
        walker = walker->getNext();
    }
    return false;
}

std::string OList::get(int loc){
    Node *walker, *trailer;
    walker = this->head; // start of the list
    trailer = nullptr;   // one behind

    while (loc > 0 && walker != nullptr){
        loc = loc - 1;
        trailer = walker;
        walker = walker->getNext();
    }

    if (walker == nullptr){
        std::cout << "out of range \n";
        return "-1";
    }

    return walker->getData();
}

void OList::remove(int loc){
    Node *walker, *trailer;
    walker = this->head; // start of the list
    trailer = nullptr;   // one behind

    while (loc > 0 && walker != nullptr){
        loc = loc - 1;
        trailer = walker;
        walker = walker->getNext();
    }

    if (walker == nullptr){
        std::cout << "out of range \n"; //or a throw like in insert()
        return;
    }

    if (trailer == nullptr){ //if first item in list
        head = walker->getNext();
        delete walker;
        walker = nullptr;
    } else {
        // do the regular case
        trailer->setNext(walker->getNext());
        delete walker;
        walker = nullptr;
    }
}

void OList::reverse(){
    Node *walker, *trailer, *stalker;
    walker = this->head;
    trailer = nullptr;
    stalker = nullptr; 

    while (walker != nullptr){
        trailer = walker->getNext();
        walker->setNext(stalker);
        stalker = walker;
        walker = trailer;
    }

    head = stalker;
}