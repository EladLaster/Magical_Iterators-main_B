#include <iostream>
#include <vector>
#include <cmath>
#include "MagicalContainer.hpp"

using namespace std;

using namespace ariel;

bool isPrime(int number)  {
        if (number < 2)
            return false;
        for (int i = 2; i <= sqrt(number); ++i) {
            if (number % i == 0)
                return false;
        }
        return true;
    }

void MagicalContainer::addElement(int element) {
    auto it = find(elements.begin(), elements.end(), element);
    if (it == elements.end()) {
        this->elements.push_back(element);
        sort(this->elements.begin(),this->elements.end());
        this->point_to_elements_prime.clear();
        for(int i=0;i<this->elements.size();++i)
            if(isPrime(this->elements[(vector<int>::size_type)i]))
                this->point_to_elements_prime.push_back(&this->elements[(vector<int>::size_type)i]);
    }
}


void MagicalContainer::removeElement(int element) {
        auto it = find(elements.begin(), elements.end(), element);
        if (it != elements.end()) {
            elements.erase(it);
        }
        else
            throw runtime_error("Can't remove element that not exist");
    }

int MagicalContainer::size() const {
        return elements.size();
    }

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
        return &cont == &other.cont && index == other.index;
    }

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
        return !(*this == other);
    }

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
        return index > other.index;
    }

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
        return index < other.index;
    }

int MagicalContainer::AscendingIterator::operator*() const {
        return cont.elements[(vector<int>::size_type)index];
    }

bool MagicalContainer::AscendingIterator::operator>=(const AscendingIterator& other) const {
    return (*this > other) || (*this == other);
}

bool MagicalContainer::AscendingIterator::operator<=(const AscendingIterator& other) const {
    return (*this < other) || (*this == other);
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(AscendingIterator const &other) {
    if(&this->cont != &other.cont)
        throw runtime_error("");
    if (this != &other) {
        cont = other.cont;
        index = other.index;
    }
    return *this;
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
    if(index==this->cont.size())
        throw runtime_error("");
    ++index;
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
    return AscendingIterator(cont);
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
     AscendingIterator iterator(cont);
    iterator.index = cont.elements.size();
    return iterator;
}



// SideCrossIterator

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
        return &cont == &other.cont && index == other.index;
    }

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
        return !(*this == other);
    }

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
        return index > other.index;
    }

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
        return index < other.index;
    }

int MagicalContainer::SideCrossIterator::operator*() const {
        return cont.elements[(vector<int>::size_type)index];
    }


bool MagicalContainer::SideCrossIterator::operator>=(const SideCrossIterator& other) const {
    return (*this > other) || (*this == other);
}

bool MagicalContainer::SideCrossIterator::operator<=(const SideCrossIterator& other) const {
    return (*this < other) || (*this == other);
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(SideCrossIterator const &other) {
    if(&this->cont != &other.cont)
        throw runtime_error("");
    if (this != &other) {
        cont = other.cont;
        index = other.index;
    }
    return *this;
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
    if(*this == this->end())
        throw runtime_error("");
    if (start_index == end_index)
        index = this->cont.size();
    else if (this->index < this->cont.size()/2) {
        index = end_index;
        end_index--;
    } else {
        start_index++;
        index = start_index;
    }
    return *this;
}


MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
    return SideCrossIterator(cont);
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
    SideCrossIterator iterator(cont);
    iterator.index = cont.elements.size();
    return iterator;
}

// PrimeIterator

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
        return &cont == &other.cont && index == other.index;
    }

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
        return !(*this == other);
    }

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
        return index > other.index;
    }

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
        return index < other.index;
    }

int MagicalContainer::PrimeIterator::operator*() const {
        return *(this->cont.point_to_elements_prime[(vector<int>::size_type)index]);
    }


bool MagicalContainer::PrimeIterator::operator>=(const PrimeIterator& other) const {
    return (*this > other) || (*this == other);
}

bool MagicalContainer::PrimeIterator::operator<=(const PrimeIterator& other) const {
    return (*this < other) || (*this == other);
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(PrimeIterator const &other) {
    if(&this->cont != &other.cont)
        throw runtime_error("");
    if (this != &other) {
        cont = other.cont;
        index = other.index;
    }
    return *this;
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
    if(*this == this->end())
        throw runtime_error("");
    this->index++;
    return  *this;
}


MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {
    return PrimeIterator(cont);
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
    PrimeIterator iterator(cont);
    iterator.index = cont.point_to_elements_prime.size();
    return iterator;
}


