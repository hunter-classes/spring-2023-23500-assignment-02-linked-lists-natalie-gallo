#include <iostream>
#include "List.h"
#include "OList.h"

int main()
{
    //PART 1
    std::cout << "----------PART I-----------\n\n";
    List *l = new List();
    std::cout << l->toString() << " " << l->length() << "\n";
    std::cout << "Testing Contain: ";
    std::cout << "Contains \'a\'? " << std::boolalpha << l->contains("a") << "\n\n"; //Testing Contain

    l->insert(0,"a");
    std::cout << l->toString() << " " << l->length() << "\n";
    std::cout << "Testing Contain: ";
    std::cout << "Contains \'a\'? " << std::boolalpha << l->contains("a") << "\n\n";

    l->insert(0,"b");
    l->insert(0,"c");
    l->insert(0,"d");

    try {
        l->insert(10,"x");
    } catch (std::exception e){
        std::cout << "Insert x didn't work\n";
    }
    std::cout << l->toString() << "\n";
    std::cout << "Testing Contain: ";
    std::cout << "Contains \'b\'? " << std::boolalpha << l->contains("b") << "\n\n";

    l->insert(2,"inserted at 2");
    std::cout << l->toString() << "\n";

    l->insert(5,"inserted at end");
    std::cout << l->toString() << " " << l->length() << "\n";
    
    std::cout << "\nTesting Remove: \n\n";
    l->remove(6); //out of range
    l->remove(0); //should remove d
    std::cout << l->toString() << " " << l->length() << "\n";
    l->remove(1); //should remove "inserted at 2"
    std::cout << l->toString() << " " << l->length() << "\n";

    std::cout << "Testing Contain: ";
    std::cout << "Contains \'d\'? " << std::boolalpha << l->contains("d") << "\n";

    //call constructor
    delete l;


    //PART 2
    std::cout << "----------PART II-----------\n\n";
    OList *l2 = new OList();
    std::cout << l2->toString() << " " << l2->length() << "\n";
    l2->insert("2");
    std::cout << l2->toString() << " " << l2->length() << "\n";
    l2->insert("1");
    std::cout << l2->toString() << " " << l2->length() << "\n";
    l2->insert("3");
    std::cout << l2->toString() << " " << l2->length() << "\n";
    l2->insert("5");
    std::cout << l2->toString() << " " << l2->length() << "\n";
    l2->insert("4");
    std::cout << l2->toString() << " " << l2->length() << "\n";

    std::cout << "At location 2: " << l2->get(2) << std::endl; //3
    std::cout << "Contains \'3\'? " << std::boolalpha << l2->contains("3") << "\n"; //Testing Contain
    std::cout << "\nTesting Remove: \n\n";
    l2->remove(6); //out of range
    l2->remove(2); //should remove 3 at loc 2
    std::cout << l2->toString() << " " << l2->length() << "\n";
    std::cout << "\nTesting Reverse: \n\n";
    l2->reverse();
    std::cout << l2->toString() << " " << l2->length() << "\n";
    
    delete l2;

    return 0;
}