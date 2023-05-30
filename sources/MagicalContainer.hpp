#ifndef HPP_MAGICALCONTAINER_DEFINED
#define HPP_MAGICALCONTAINER_DEFINED

#include <vector>
#include <iostream>


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
        class AscendingIterator
        {
            private:
                MagicalContainer& container;
                int index;
            public:
                AscendingIterator(MagicalContainer& container);
                class iterator
                {
                    private:
                        AscendingIterator& ascIter;
                    public:
                        iterator(AscendingIterator& ascIter);
                        iterator& operator++();
                        iterator operator++(int);
                        bool operator==(const iterator& other) const;
                        bool operator!=(const iterator& other) const;
                        int operator*();
                };
                iterator begin();
                iterator end();
        };

};
}




















#endif // HPP_MAGICALCONTAINER_DEFINED