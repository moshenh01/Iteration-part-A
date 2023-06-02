#ifndef HPP_MAGICALCONTAINER_DEFINED
#define HPP_MAGICALCONTAINER_DEFINED

#include <vector>
#include <iostream>
#include <algorithm> // for std::sort
#include <deque>
#include <iterator>
#include <list>

namespace ariel
{

class MagicalContainer
{
    private:
        std::vector<int> elements;
        
    public:
        void addElement(int element);
        void removeElement(int element);
        int size();
        //assingment operator
        MagicalContainer& operator = (const MagicalContainer& other);
        
        MagicalContainer &operator=(MagicalContainer &&other) noexcept = default;
        const std::vector<int>& getElements() const {
        return elements;
        }
       
       
         MagicalContainer() = default;
        ~MagicalContainer() = default;
        MagicalContainer(const MagicalContainer &other) = default;
        
        MagicalContainer(MagicalContainer &&other) noexcept = default;
        
         

     
        class AscendingIterator
        {
            private:
                MagicalContainer& container;
                size_t index;
            public:
                //constructor
                AscendingIterator(MagicalContainer& container);
                //copy constructor
                AscendingIterator(const AscendingIterator& other);
                //destructors
                ~AscendingIterator() = default;
                //assignment operator
                AscendingIterator& operator=(const AscendingIterator& other);
                  // Move constructor
                AscendingIterator(AscendingIterator&& other) noexcept : container(other.container), index(other.index)
                {
                    // Reset the other iterator's container reference
                    other.container.elements.clear();
                    other.index = 0;
                }
                  // Move assignment operator
                AscendingIterator& operator=(AscendingIterator&& other) noexcept
                {
                    if (this != &other)
                    {
                        container = other.container;
                        index = other.index;

                        // Reset the other iterator's container reference
                        other.container.elements.clear();
                        other.index = 0;
                    }
                    return *this;
                }
        
                //• Equality comparison (operator==)
                bool operator==(const AscendingIterator& other) const;
                //• Inequality comparison (operator!=)
                bool operator!=(const AscendingIterator& other) const;
                /*• GT, LT comparison (operator>, operatorn<) all comparison operators
                  only valid for iterators of the same type of order and should compair
                  the location of the iterator in the container and not the element 
                  inside. Example bellow. Using operators on iterators of differant
                   type or differant containers should throw an examtion.*/
                bool operator>(const AscendingIterator& other) const;
                bool operator<(const AscendingIterator& other) const;
                //• Dereference operator (operator*)
                int&  operator*() const;
                //• Pre-increment operator (operator++)
                AscendingIterator& operator++();
                AscendingIterator begin();
                AscendingIterator end();
        };
        class SideCrossIterator
        {
            private:
                MagicalContainer& container;  // Reference to the container
                std::list<int> elemnts;      // List of elements
                size_t index;  
                std:: list<int>::iterator it; // Iterator to the current element
                void sort();             // Index of the current element
            public:
                //constructor
                SideCrossIterator(MagicalContainer& container);
                //copy constructor
                SideCrossIterator(const SideCrossIterator& other);
                //destructors
                ~SideCrossIterator() = default;
                //assignment operator
                SideCrossIterator& operator=(const SideCrossIterator& other);

                // Move constructor
                SideCrossIterator(SideCrossIterator&& other) noexcept : container(other.container), index(other.index)
                {
                    // Reset the other iterator's container reference
                    other.container.elements.clear();
                    other.index = 0;
                }

                // Move assignment operator
                SideCrossIterator& operator=(SideCrossIterator&& other) noexcept
                {
                    if (this != &other)
                    {
                        container = other.container;
                        index = other.index;

                        // Reset the other iterator's container reference
                        other.container.elements.clear();
                        other.index = 0;
                    }
                    return *this;
                }
                //• Equality comparison (operator==)
                bool operator==(const SideCrossIterator& other) const;
                //• Inequality comparison (operator!=)
                bool operator!=(const SideCrossIterator& other) const;
                /*• GT, LT comparison (operator>, operatorn<) all comparison operators
                  only valid for iterators of the same type of order and should compair
                  the location of the iterator in the container and not the element 
                  inside. Example bellow. Using operators on iterators of differant
                   type or differant containers should throw an examtion.*/
                bool operator>(const SideCrossIterator& other) const;
                bool operator<(const SideCrossIterator& other) const;
                //• Dereference operator (operator*)
                const int& operator*() const;
                //• Pre-increment operator (operator++)
                SideCrossIterator& operator++();
                
                
                SideCrossIterator begin();
                SideCrossIterator end();
        };
        class PrimeIterator
        {
            private:
                MagicalContainer& container;
                std::vector<int> primes;
                size_t index;
            public:
                //constructor
                PrimeIterator(MagicalContainer& container);
                //copy constructor
                PrimeIterator(const PrimeIterator& other);
                //destructors
                ~PrimeIterator() = default;
                //assignment operator
                PrimeIterator& operator=(const PrimeIterator& other);
                // Move constructor
                PrimeIterator(PrimeIterator&& other) noexcept : container(other.container), index(other.index)
                {
                    // Reset the other iterator's container reference
                    other.container.elements.clear();
                    other.index = 0;
                }
                // Move assignment operator
                PrimeIterator& operator=(PrimeIterator&& other) noexcept
                {
                    if (this != &other)
                    {
                        container = other.container;
                        index = other.index;

                        // Reset the other iterator's container reference
                        other.container.elements.clear();
                        other.index = 0;
                    }
                    return *this;
                }
                //• Equality comparison (operator==)
                bool operator==(const PrimeIterator& other) const;
                //• Inequality comparison (operator!=)
                bool operator!=(const PrimeIterator& other) const;
                /*• GT, LT comparison (operator>, operatorn<) all comparison operators
                  only valid for iterators of the same type of order and should compair
                  the location of the iterator in the container and not the element 
                  inside. Example bellow. Using operators on iterators of differant
                   type or differant containers should throw an examtion.*/
                bool operator>(const PrimeIterator& other) const;
                bool operator<(const PrimeIterator& other) const;
                //• Dereference operator (operator*)
                int operator*() const;
                //• Pre-increment operator (operator++)
                PrimeIterator& operator++();

                PrimeIterator begin();
                PrimeIterator end();

                void print();
        };


};
}




















#endif // HPP_MAGICALCONTAINER_DEFINED