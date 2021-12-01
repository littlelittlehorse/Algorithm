#include <bits/stdc++.h>

using namespace std;

class Iterator {
    struct Data;
    Data *data;
public:
    Iterator(const vector<int> &nums);
    Iterator(const Iterator &iter);

    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
    int nextValue;
    bool exist;
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        exist = Iterator::hasNext();
        if (exist)
            nextValue = Iterator::next();
    }

    int peek() {
        return nextValue;
    }

    int next() {
        int tmpValue = nextValue;
        exist = Iterator::hasNext();
        if (exist)
            nextValue = Iterator::next();
        return tmpValue;
    }

    bool hasNext() const {
        return exist;
    }
};
