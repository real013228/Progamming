//
// Created by real0 on 06.04.2022.
//

#ifndef OOP3_HOUOUINKYOUMA_H
#define OOP3_HOUOUINKYOUMA_H

#include <stdexcept>

template <typename T>
class RingBuffer {
private:
    // Fields of RingBuffer ***
    T *_values;
    int _head;
    int _tail;
    int _capacity;
    int _size;
public:
    // Constructor, destructor and boolean functions, that check the state of the container ***
    explicit RingBuffer(int capacity) : _head(0), _tail(0), _capacity(capacity), _size(0) {
        _values = reinterpret_cast<T *>(new char[sizeof(T) * capacity]);
    }

    RingBuffer() : _head(0), _tail(0), _capacity(0), _size(0) {}

    ~RingBuffer() {
        delete[] _values;
    }

    bool isFull() {
        return _size == _capacity;
    }

    bool isEmpty() {
        return _size == 0;
    }

public:
    // Methods of pushing and deleting ***
    void push_back(T value) {
        try {
            if (isFull()) {
                throw std::overflow_error("buffer is full");
            } else {
                _values[_head++] = value;
                _size++;
            }
        } catch (const char *whatArg) {
            std::cout << "Error : " << whatArg << '\n';
        }
    }

    void pop_back() {
        try {
            if (isEmpty()) {
                throw std::invalid_argument("buffer is empty");
            } else {
                _head--;
                _size--;
            }
        } catch (const char *whatArg) {
            std::cout << "Error: " << whatArg << '\n';
        }
    }

    void push_front(T value) {
        try {
            if (isFull()) {
                throw std::overflow_error("buffer is full");
            } else {
                if (_tail == 0) {
                    _values[_tail] = value;
                } else {
                    _values[_tail - 1] = value;
                    _tail--;
                    _size++;
                }
            }
        } catch (const char *whatArg) {
            std::cout << "Error : " << whatArg << '\n';
        }
    }

    void pop_front() {
        try {
            if (isEmpty()) {
                throw std::invalid_argument("buffer is empty");
            } else {
                _tail++;
                _size--;
            }
        } catch (const char *whatArg) {
            std::cout << "Error: " << whatArg << '\n';
        }
    }
    void reserve(size_t sz) {
        try {
            if (sz > _size) {
                T *tmp = reinterpret_cast<T *>(new char[sizeof(T) * sz]);
                for (int i = _tail; i < _head; ++i) {
                    tmp[i] = _values[i];
                }
                delete[] _values;
                _values = tmp;
            } else {
                throw std::invalid_argument("the size is too small");
            }
        } catch (const char *whatArg) {
            std::cout << "Error: " << whatArg << '\n';
        }
    }
//Random access iterator implementation ***
public:
    template<bool IsConst>
    struct common_iterator : public std::iterator<std::random_access_iterator_tag, T, std::ptrdiff_t, T *, T &> {
    private:
        std::conditional_t<IsConst, const T *, T *> ptr_;
    public:
        common_iterator() = default;
        explicit common_iterator(T *ptr) : ptr_(ptr) {}

        T &operator*() {
            return *ptr_;
        }

        T *operator->() {
            return ptr_;
        }

        common_iterator &operator++() {
            ++ptr_;
            return *this;
        }

        common_iterator operator++(int) {
            common_iterator tmp;
            tmp = *this;
            ++(*this);
            return tmp;
        }

        common_iterator &operator--() {
            this->ptr_--;
            return *this;
        }

        common_iterator operator--(int) {
            common_iterator tmp;
            tmp = *this;
            --(*this);
            return tmp;
        }

        common_iterator &operator+=(const ptrdiff_t step) {
            this->ptr_ += step;
            return (*this);
        }

        common_iterator operator+(const ptrdiff_t step) const {
            common_iterator tmp = *this;
            tmp += step;
            return tmp;
        }


        common_iterator &operator-=(const ptrdiff_t step) {
            *this += (-step);
            return *this;
        }

        common_iterator operator-(const ptrdiff_t step) const {
            common_iterator tmp = *this;
            tmp -= step;
            return tmp;
        }

//        common_iterator &operator=(const common_iterator& other) {
//            this->ptr_ = other.ptr_;
//        }

        bool operator>(const common_iterator &other) const {
            return ptr_ > other.ptr_;
        }

        bool operator>=(const common_iterator &other) const {
            return ptr_ >= other.ptr_;
        }

        bool operator==(const common_iterator &other) const {
            return ptr_ == other.ptr_;
        }

        bool operator<(const common_iterator &other) const {
            return !(*this >= other);
        }

        bool operator<=(const common_iterator &other) const {
            return !(*this > other);
        }

        bool operator!=(const common_iterator &other) const {
            return !((*this) == other);
        }

        int operator-(const common_iterator &other) {
            return this->ptr_ - other.ptr_;
        }
    };


    using iterator = common_iterator<false>;
    using const_iterator = common_iterator<true>;

    const_iterator cbegin() const {
        return const_iterator(_values + _tail);
    }

    const_iterator cend() const {
        return const_iterator(_values + _head);
    }

    iterator begin() {
        return iterator(_values + _tail);
    }

    iterator end() {
        return iterator(_values + _head);
    }

    T &operator[](const size_t index) {
        try {
            if (_size <= index) {
                throw std::out_of_range("index out of range");
            }
        } catch (const char *whatArg) {
            std::cout << "Error: " << whatArg << '\n';
        }
        return _values[_tail + index];
    }

    const T &operator[](const size_t index) const {
        if (_size <= index) {
            throw std::out_of_range("index out of range");
        }
        return *(cbegin() + index);
    }

    void print() {
        for (auto it: *this) {
            std::cout << it << ' ';
        }
        std::cout << '\n';
    }
};




#endif //OOP3_HOUOUINKYOUMA_H
