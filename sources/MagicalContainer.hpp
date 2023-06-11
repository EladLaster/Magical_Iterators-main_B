#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
namespace ariel{

class MagicalContainer {
private:
    vector<int> elements;
    vector<int*> point_to_elements_prime;
    
public:

    MagicalContainer() = default;
    ~MagicalContainer() = default;
    void addElement(int elem);
    void removeElement(int elem);
    int size() const;

    // ------------------ tidy -------------------

    MagicalContainer(const MagicalContainer& other) = default;
    MagicalContainer& operator=(const MagicalContainer& other) = default;
    MagicalContainer(MagicalContainer&& other) = default;
    MagicalContainer& operator=(MagicalContainer&& other) = default;

    // AscendingIterator
    class AscendingIterator {
    private:
        MagicalContainer& cont;
        int index;

    public:
        AscendingIterator(MagicalContainer& cont) : cont(cont), index(0) {}

        AscendingIterator(const AscendingIterator& other) : cont(other.cont), index(other.index) {}

        ~AscendingIterator() = default;

        bool operator==(const AscendingIterator& other) const;

        bool operator!=(const AscendingIterator& other) const;

        bool operator>(const AscendingIterator& other) const;

        bool operator<(const AscendingIterator& other) const;

        bool operator>=(const AscendingIterator& other) const;

        bool operator<=(const AscendingIterator& other) const;

        int operator*() const;
        
        AscendingIterator& operator=(const AscendingIterator& other);

        AscendingIterator& operator++();

        AscendingIterator begin();

        AscendingIterator end();

         // ------------------ tidy -------------------

        AscendingIterator(AscendingIterator&& other) = default;

        AscendingIterator& operator=(AscendingIterator&& other) = delete;

    };

    

    // SideCrossIterator
    class SideCrossIterator {
    private:
        MagicalContainer& cont;
        int index;
        int start_index;
        int end_index;

    public:
        SideCrossIterator(MagicalContainer& cont) : cont(cont), index(0), start_index(0),end_index(cont.size()-1){}

        SideCrossIterator(const SideCrossIterator& other) : cont(other.cont), index(0) ,start_index(other.start_index), end_index(other.end_index){}
       
        ~SideCrossIterator() = default;

        bool operator==(const SideCrossIterator& other) const;

        bool operator!=(const SideCrossIterator& other) const;

        bool operator>(const SideCrossIterator& other) const;

        bool operator<(const SideCrossIterator& other) const;

        bool operator>=(const SideCrossIterator& other) const;

        bool operator<=(const SideCrossIterator& other) const;

        int operator*() const;

        SideCrossIterator& operator=(const SideCrossIterator& other);

        SideCrossIterator& operator++();
    
        SideCrossIterator begin();

        SideCrossIterator end();


        // ------------------ tidy -------------------

        SideCrossIterator(SideCrossIterator&& other) = default;

        SideCrossIterator& operator=(SideCrossIterator&& other) = delete;
        
    };

    // PrimeIterator
    class PrimeIterator {
    private:
        MagicalContainer& cont;
        int index;
        

    public:
        PrimeIterator(MagicalContainer& cont) : cont(cont), index(0){}

        PrimeIterator(const PrimeIterator& other) : cont(other.cont), index(other.index) {}

        ~PrimeIterator() = default;

        bool operator==(const PrimeIterator& other) const;

        bool operator!=(const PrimeIterator& other) const;

        bool operator>(const PrimeIterator& other) const;

        bool operator<(const PrimeIterator& other) const;

        bool operator>=(const PrimeIterator& other) const;

        bool operator<=(const PrimeIterator& other) const;

        int operator*() const;

        PrimeIterator& operator=(const PrimeIterator& other);

        PrimeIterator& operator++();

        PrimeIterator begin();

        PrimeIterator end();

        // ------------------ tidy -------------------

        PrimeIterator(PrimeIterator&& other) = default;

        PrimeIterator& operator=(PrimeIterator&& other) = delete;

    };
};

}