/* python style range class to be used in range based for loops
 * examples:
 *   for (auto a : Range(0, 7, 3)) {
 *       std::cout << a << " ";
 *   }
 *   OUTPUT: 0 3 6
 *
 *   for (auto a : Range(-0.5, 1.5, 0.45)) {
 *      std::cout << a << " ";
 *   }
 *   OUTPUT: -0.5 -0.05 0.4 0.85 1.3
 *
 *   std::vector<int> l = {1,2,3,4,5,6,7,8,9};
 *   for (auto a : Range(l.begin(), l.end(), 3)) {
 *       std::cout << *a << " ";
 *   }
 *   OUTPUT: 1 4 7
 * */

template <typename T, typename I = int>
class RangeIterator {
    T iterator;
    const I increment;

public:

    RangeIterator(T iterator, I increment) : iterator(iterator), increment(increment)
    {};

    RangeIterator operator ++() {
        iterator += increment;
        return *this;
    }

    RangeIterator operator ++(int) {
        auto preIncremented = *this;
        iterator += increment;
        return preIncremented;
    }

    T operator *() {
        return iterator;
    }

    bool operator==(const RangeIterator &rhs) const {
        return iterator == rhs.iterator &&
               increment == rhs.increment;
    }

    bool operator!=(const RangeIterator &rhs) const {
        return !(rhs == *this) and (increment > I() ? iterator < rhs.iterator : iterator > rhs.iterator);
    }

};

template <typename T, typename I = int>
class Range {
    const T rangeBegin;
    const T rangeEnd;
    const I rangeIncrement;

public:
    Range(T start, T end, I increment) : rangeBegin(start), rangeEnd(end), rangeIncrement(increment) {};

    Range(T start, T end) : Range(start, end, start < end ? I(1) : I(-1)) {};

    explicit Range(T end) : Range(T(), end) {};

    [[nodiscard]] RangeIterator<T, I> begin() const {
        return RangeIterator(rangeBegin, rangeIncrement);
    };

    [[nodiscard]] RangeIterator<T, I> end() const {
        return RangeIterator(rangeEnd, rangeIncrement);
    };
};
