#include "MagicalContainer.hpp"
using namespace std;
#include<unistd.h>    

void showlist(list<int> g)
{
    list<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}

void ariel::MagicalContainer::SideCrossIterator::sort()
{
    if(this->container.size()== 0){
        return;
    }
    size_t i = 0,j = this->container.elements.size() - 1;
    while(i<j){
        this->elemnts.push_back(this->container.elements.at(i));
        this->elemnts.push_back(this->container.elements.at(j));
        i++;
        j--;
    }
    if(i == j){
        this->elemnts.push_back(this->container.elements.at(i));
    }
    //showlist(this->elemnts);

}
ariel::MagicalContainer::SideCrossIterator:: SideCrossIterator (MagicalContainer& container)
:container(container){
    sort();
    this->index = 0;
    this->it = this->elemnts.begin();
      
        
}

ariel :: MagicalContainer :: SideCrossIterator :: SideCrossIterator ( const SideCrossIterator& other)
   :container(other.container){
    this->index = other.index;
    this->elemnts = other.elemnts;
    this->it = other.it;
}

ariel::MagicalContainer::SideCrossIterator& ariel::MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other)
{
    if(&this->container != &other.container){
        throw std::runtime_error("diff containers");
    }
    //check for self assignment
    if(this != &other)
    {
        this->container = other.container;
        this->index = other.index;
        this->elemnts = other.elemnts;
        this->it = other.it;

    }
    //return reference to this
    return *this;
}
bool ariel::MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const
{
    //comperes the index of the iterators
    return this->index == other.index;
}
bool ariel::MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const
{
    //comperes the index of the iterators
    return this->index != other.index;
}
bool ariel::MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const
{
    //comperes the index of the iterators
    return  this->index > other.index;
}
bool ariel::MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const
{
    //comperes the index of the iterators
    return  this->index < other.index;
}
const int& ariel::MagicalContainer::SideCrossIterator::operator*() const
{
    //return the element in the index

    return *this->it;
}

//• Pre-increment operator (operator++)
ariel::MagicalContainer::SideCrossIterator& ariel::MagicalContainer::SideCrossIterator::operator++()
{
    if(this->index == this->elemnts.size())
        throw std::runtime_error("the iterator is out of range");
    
    //increment the index
    ++this->index;
    ++this->it;
    //return reference to this
    return *this;
}
ariel::MagicalContainer::SideCrossIterator ariel::MagicalContainer::SideCrossIterator::begin()
{
    //return iterator to the first element
    SideCrossIterator it (*this);
    it.it = this->elemnts.begin();
    it.index = 0;
    return it;
}
ariel::MagicalContainer::SideCrossIterator ariel::MagicalContainer::SideCrossIterator::end()
{
    //return iterator to thelast element
    SideCrossIterator it (*this);
    it.it = this->elemnts.end();
    it.index = this->elemnts.size();
    return it;
   
}