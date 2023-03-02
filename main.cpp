#include <iostream>
#include "List.h"

int main()
{
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

    return 0;
}