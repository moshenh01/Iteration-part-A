#include "MagicalContainer.hpp"

//insert O(1)
void ariel::MagicalContainer::addElement(int element)
{
    elements.push_back(element);
}
//remove O(n)
void ariel::MagicalContainer::removeElement(int element)
{
    bool deleted = false;
    if(elements.size() == 0)
    {
        throw std::runtime_error("the container is empty");
    }
   
   for(auto it = elements.begin(); it != elements.end(); ++it)
   {
       if(*it == element)
       {
           elements.erase(it);
           deleted = true;
           break;
       }
   }
   if(deleted == false){
        throw std::runtime_error("was not able to find this elem");
   }
}
//size O(1)
int ariel::MagicalContainer::size()
{
    return elements.size();
}
//assignement operator

ariel::MagicalContainer& ariel::MagicalContainer::operator=(const MagicalContainer& other) {
    if (this != &other) {
        elements = other.elements;//copy the elements
    }
    return *this;
}




