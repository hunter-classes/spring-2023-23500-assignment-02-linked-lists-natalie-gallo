#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include <string>
#include "Node.h"
#include "OList.h"
#include "List.h"
#include "doctest.h"

OList *l = new OList();
TEST_CASE("Insertion & get Case"){
    l->insert("1"); 
    CHECK(l->get(0) == "1");
    l->insert("3"); 
    CHECK(l->get(1) == "3");
    l->insert("2"); 
    CHECK(l->get(1) == "2");
    CHECK(l->get(2) == "3");
}

TEST_CASE("contains case"){
    CHECK(l->contains("3") == true);
    CHECK(l->contains("5") == false);
    CHECK(l->contains("2") == true);
    CHECK(l->contains("1") == true);
    CHECK(l->contains("0") == false);
}

TEST_CASE("remove case"){
    l->remove(2);
    CHECK(l->get(2) == "-1");
    l->remove(1);
    CHECK(l->get(2) == "-1");
    l->remove(0);
    CHECK(l->get(2) == "-1");
}

TEST_CASE("reverse case"){
    l->insert("1"); 
    l->insert("3"); 
    l->insert("2"); 
    l->reverse();
    CHECK(l->get(0) == "3");
    CHECK(l->get(1) == "2");
    CHECK(l->get(2) == "1");
}

TEST_CASE("destructor case"){
    delete l;
    CHECK(l->emptyList() == true);
}