#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <stdexcept>

using namespace ariel;
using namespace std;

TEST_CASE("adding and removeing element"){
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
    CHECK(container.size() == 5);

    container.removeElement(1);
    container.removeElement(2);
    container.removeElement(3);
    CHECK(container.size() == 2);
    container.removeElement(4);
    container.removeElement(5);
    CHECK(container.size() == 0);
    CHECK_THROWS_AS(container.removeElement(1), std::runtime_error);
}

TEST_CASE("itaration test"){
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
    CHECK(container.size() == 5);

    MagicalContainer::AscendingIterator ascIter(container);
    CHECK(*ascIter == 1);
    ++ascIter;
    CHECK(*ascIter == 2);
    ++ascIter;
    CHECK(*ascIter == 3);
    ++ascIter;
    CHECK(*ascIter == 4);
    ++ascIter;
    CHECK(*ascIter == 5);
    ++ascIter;
    CHECK(ascIter == ascIter.end());

    MagicalContainer::SideCrossIterator crossIter(container);
    CHECK(*crossIter == 1);
    ++crossIter;
    CHECK(*crossIter == 5);
    ++crossIter;
    CHECK(*crossIter == 2);
    ++crossIter;
    CHECK(*crossIter == 4);
    ++crossIter;
    CHECK(*crossIter == 3);
    ++crossIter;
    CHECK(crossIter == crossIter.end());

    MagicalContainer::PrimeIterator primeIter(container);
    
    CHECK(*primeIter == 2);
    ++primeIter;
    CHECK(*primeIter == 3);
    ++primeIter;
    CHECK(*primeIter == 5);
    ++primeIter;
    CHECK(primeIter == primeIter.end());

}

TEST_CASE("compering iterators"){
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
    container.addElement(6);
    container.addElement(7);
    container.addElement(8);
    container.addElement(9);
    container.addElement(10);
    CHECK(container.size() == 10);
   

    MagicalContainer::AscendingIterator ascIter1(container);
    MagicalContainer::AscendingIterator ascIter2(container);
    MagicalContainer::SideCrossIterator crossIter1(container);
    MagicalContainer::SideCrossIterator crossIter2(container);
    MagicalContainer::PrimeIterator primeIter1(container);
    MagicalContainer::PrimeIterator primeIter2(container);

    CHECK(ascIter1 == ascIter2);
    CHECK(crossIter1 == crossIter2);
    CHECK(primeIter1 == primeIter2);

    CHECK(!(ascIter1 > ascIter2));
    CHECK(!(crossIter1 > crossIter2));
    CHECK(!(primeIter1 > primeIter2));

    CHECK(!(ascIter1 < ascIter2));
    CHECK(!(crossIter1 < crossIter2));
    CHECK(!(primeIter1 < primeIter2));

    ++ascIter1;
    ++crossIter1;
    ++primeIter1;

    CHECK(ascIter1 != ascIter2);    
    CHECK(crossIter1 != crossIter2);
    CHECK(primeIter1 != primeIter2);

    CHECK(ascIter1 > ascIter2);
    CHECK(crossIter1 > crossIter2);
    CHECK(primeIter1 > primeIter2);

    CHECK(!(ascIter1 < ascIter2));
    CHECK(!(crossIter1 < crossIter2));
    CHECK(!(primeIter1 < primeIter2));


}

TEST_CASE("INCREMENT ITERATOR"){

    MagicalContainer container;
    for (size_t i = 0; i < 1000; i++)
    {
        container.addElement(i);
    }
  
    SUBCASE("AscendingIterator"){
        MagicalContainer::AscendingIterator ascIter(container);
        while(ascIter != ascIter.end()){
            ++ascIter;
        }

        CHECK_THROWS_AS(++ascIter, std::runtime_error);
        
    }

    SUBCASE("SideCrossIterator"){
        MagicalContainer::SideCrossIterator crossIter(container);
        while(crossIter != crossIter.end()){
            ++crossIter;
        }

        CHECK_THROWS_AS(++crossIter, std::runtime_error);
        
    }

    SUBCASE("PrimeIterator"){
        MagicalContainer::PrimeIterator primeIter(container);
        while(primeIter != primeIter.end()){
            ++primeIter;
        }

        CHECK_THROWS_AS(++primeIter, std::runtime_error);
        
    }
}


