#include "MagicalContainer.hpp"
using namespace std;


bool isPrime(int num){
    if(num == 2)
        return true;
    if(num <2 || num%2 == 0)
        return false;
  
    for(int i =3 ;i*i <= num; i+=2)
    {
        if(num % i == 0)
            return false;
    }
    return true;
}




//prime iterator constructor
ariel::MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container):
container(container), index(0)
{
    for(size_t i = 0; i < container.elements.size(); i++)
    {
        if(isPrime(container.elements.at(i)))
            this->primes.push_back(container.elements.at(i));
    }
   
}

//copy constructor
ariel::MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other):
container(other.container), index(other.index){
   
    this->primes = other.primes;
}
//assignment operator
ariel::MagicalContainer::PrimeIterator& ariel::MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other)
{    if(&this->container != &other.container){
        throw std::runtime_error("diff containers");
    }
    //check for self assignment
    if(this != &other)
    {
        this->container = other.container;
        this->index = other.index;
        this->primes = other.primes;
    }
    //return reference to this
    return *this;
}
bool ariel::MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const
{
    //comperes the index of the iterators
    return this->index == other.index;
}
bool ariel::MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const
{
    //comperes the index of the iterators
    return this->index != other.index;
}
bool ariel::MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const
{
    //comperes the index of the iterators
    return this->index > other.index;
}
bool ariel::MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const
{
    //comperes the index of the iterators
    return this->index < other.index;
}
int ariel::MagicalContainer::PrimeIterator::operator*() const
{
    //return the element in the index
    return this->primes.at(this->index);
}
//• Pre-increment operator (operator++)
ariel::MagicalContainer::PrimeIterator& ariel::MagicalContainer::PrimeIterator::operator++()
{
    if(this->index == this->primes.size())
    {
        throw std::runtime_error("the iterator is out of range");
    }
    //increment the index
    ++this->index;
    //return reference to this
    return *this;
}
ariel::MagicalContainer::PrimeIterator ariel::MagicalContainer::PrimeIterator::begin()
{
    //return iterator to the first element
    PrimeIterator it (this->container);
    it.primes = this->primes;
    it.index = 0;
    return it;
}
ariel::MagicalContainer::PrimeIterator ariel::MagicalContainer::PrimeIterator::end()
{
    //return iterator to the last element
    PrimeIterator it (this->container);
    it.primes = this->primes;
    it.index = this->primes.size();
    return it;
}
void ariel::MagicalContainer::PrimeIterator::print(){
    for(size_t i = 0;i < primes.size();i++ ){
            cout<< primes.at(i)<<endl;
    }
}

