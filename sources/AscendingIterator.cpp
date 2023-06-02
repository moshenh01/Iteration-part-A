#include "MagicalContainer.hpp"

ariel::MagicalContainer::AscendingIterator:: AscendingIterator (MagicalContainer& container)
: container(container), index(0)
{
    std::sort(container.elements.begin(), container.elements.end());
}

ariel::MagicalContainer::AscendingIterator:: AscendingIterator (const AscendingIterator& other)
   :container(other.container), index(other.index){}

ariel::MagicalContainer::AscendingIterator& ariel::MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other)
{
     if(&this->container != &other.container){
        throw std::runtime_error("diff containers");
    }
    //check for self assignment
    if(this != &other)
    {
        this->container = other.container;
        this->index = other.index;
    }
    //return reference to this
    return *this;
}

bool ariel::MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const
{
    //comperes the index of the iterators
    return this->index == other.index;
}
bool ariel::MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const
{
    //comperes the index of the iterators
    return this->index != other.index;
}
bool ariel::MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const
{
    //comperes the index of the iterators
    return this->index > other.index;
}
bool ariel::MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const
{
    //comperes the index of the iterators
    return this->index < other.index;
}
int&  ariel::MagicalContainer::AscendingIterator::operator*() const
{
    //return the element in the index
    return this->container.elements.at(this->index);
}
//• Pre-increment operator (operator++)
ariel::MagicalContainer::AscendingIterator& ariel::MagicalContainer::AscendingIterator::operator++()
{
    if(this->index == this->container.elements.size())
    {
        throw std::runtime_error("the iterator is out of range");
    }
    //increment the index
    ++this->index;
    //return reference to this
    return *this;
}
ariel::MagicalContainer::AscendingIterator ariel::MagicalContainer::AscendingIterator::begin()
{
    //return iterator to the first element
    return AscendingIterator(this->container);
}
ariel::MagicalContainer::AscendingIterator ariel::MagicalContainer::AscendingIterator::end()
{
    //return iterator to the last element
    AscendingIterator it(this->container);
    it.index = this->container.elements.size();
    return it;
}
 