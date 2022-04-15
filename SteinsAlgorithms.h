//
// Created by real0 on 08.04.2022.
//

#ifndef OOP3_STEINSALGORITHMS_H
#define OOP3_STEINSALGORITHMS_H


namespace steinsReading {
    ////declarations ***

    template<class InputIt, class UnaryPredicate>
    InputIt find_if_count(InputIt first, InputIt last, UnaryPredicate predicate);

    template<class InputIt, class UnaryPredicate>
    bool all_of(InputIt first, InputIt last, UnaryPredicate predicate);

    template<class InputIt, class UnaryPredicate>
    bool any_of(InputIt first, InputIt last, UnaryPredicate predicate);

    template<class InputIt, class UnaryPredicate>
    bool none_of(InputIt first, InputIt last, UnaryPredicate predicate);

    template<class InputIt, class UnaryPredicate>
    bool one_of(InputIt first, InputIt last, UnaryPredicate predicate);

    template<class InputIt, class UnaryPredicate>
    InputIt find_if_not(InputIt first, InputIt last, UnaryPredicate predicate);

    template<class InputIt, class UnaryPredicate>
    InputIt find_if(InputIt first, InputIt last, UnaryPredicate predicate);

    template<class InputIt, class T>
    InputIt find(InputIt first, InputIt last, const T &value);

    template<class ForwardIt>
    bool is_sorted(ForwardIt first, ForwardIt last);

    template<class ForwardIt, class Compare>
    ForwardIt is_sorted_check(ForwardIt first, ForwardIt last, Compare cmp);

    template<class InputIt, class UnaryPredicate>
    bool is_partitioned(InputIt first, InputIt last, UnaryPredicate predicate);

    template<class InputIt, class T>
    InputIt find_not(InputIt first, InputIt last, const T &value);
    ////definitions ***

    template<class InputIt, class UnaryPredicate>
    bool all_of(InputIt first, InputIt last, UnaryPredicate predicate) {
        return steinsReading::find_if_not(first, last, predicate) == last;
    }

    template<class InputIt, class UnaryPredicate>
    bool any_of(InputIt first, InputIt last, UnaryPredicate predicate) {
        return find_if(first, last, predicate) != last;
    }

    template<class InputIt, class UnaryPredicate>
    bool none_of(InputIt first, InputIt last, UnaryPredicate predicate) {
        return find_if(first, last, predicate) == last;
    }

    template<class InputIt, class UnaryPredicate>
    bool one_of(InputIt first, InputIt last, UnaryPredicate predicate) {
        return find_if_count(first, last, predicate) == last;
    }

    template<class InputIt, class UnaryPredicate>
    InputIt find_if_not(InputIt first, InputIt last, UnaryPredicate predicate) {
        for (; first != last; ++first) {
            if (!predicate(*first)) {
                return first;
            }
        }
        return last;
    }

    template<class InputIt, class UnaryPredicate>
    InputIt find_if_count(InputIt first, InputIt last, UnaryPredicate predicate) {
        size_t cnt = 0;
        for (; first != last; ++first) {
            if (predicate(*first)) {
                cnt++;
            }
            if (cnt > 1) {
                return first;
            }
        }
        if (cnt != 0) {
            return last;
        }
        return first - 1;
    }

    template<class InputIt, class UnaryPredicate>
    InputIt find_if(InputIt first, InputIt last, UnaryPredicate predicate) {
        for (; first != last; ++first) {
            if (predicate(*first)) {
                return first;
            }
        }
        return last;
    }

    template<class InputIt, class T>
    InputIt find(InputIt first, InputIt last, const T &value) {
        for (; first != last; ++first) {
            if (*first == value) {
                return first;
            }
        }
        return last;
    }

    template<class ForwardIt>
    bool is_sorted(ForwardIt first, ForwardIt last) {
        return (is_sorted_check(first, last, std::less<>()) == last);
    }

    template<class ForwardIt, class Compare>
    ForwardIt is_sorted_check(ForwardIt first, ForwardIt last, Compare cmp) {
        if (first != last) {
            ForwardIt next = first;
            while (++next != last) {
                if (cmp(*next, *first )) {
                    return next;
                }
                first = next;
            }
        }
        return last;
    }

    template<class InputIt, class UnaryPredicate>
    bool is_partitioned(InputIt first, InputIt last, UnaryPredicate predicate) {
        for (; first != last; ++first) {
            if (!predicate(*first)) {
                break;
            }
        }
        for (; first != last; ++first) {
            if (predicate(*first)) {
                return false;
            }
        }
        return true;
    }

    template<class InputIt, class T>
    InputIt find_not(InputIt first, InputIt last, const T &value) {
        for (; first != last; ++first) {
            if (*first != value) {
                return first;
            }
        }
        return last;
    }

    template<class InputIt, class T>
    InputIt find_backward(InputIt first, InputIt last, const T &value) {
        InputIt ans = last;
        for (; first != last; ++first) {
            if (*first == value) {
                ans = first;
            }
        }
        return ans;
    }
    template<class BidirectionalIt>
    bool is_palindrome(BidirectionalIt first, BidirectionalIt last) {
        if (first == last - 1) {
            return true;
        }
        last--;
        while (first <= last) {
            if (*first == *last) {
                first++;
                last--;
            } else {
                return false;
            }
        }
        return true;
    }
}
#endif //OOP3_STEINSALGORITHMS_H
