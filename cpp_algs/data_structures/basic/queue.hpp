/**
 * MIT License
 *
 * Copyright (c) 2018 Prabhsimran Singh
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#pragma once

/**
 * Data Structures - data
 * data.hpp
 * Purpose: Queue interface and impl.
 * 
 * @author Prabhsimran Singh
 * @version 2.0 03/12/18
*/
#include <algorithm>
#include <iostream>

#include "container.hpp"

namespace ds {

// ---------------------------------------------- Interface ---------------------------------------------------//

template <typename T>
class Queue : public Container {
  private:
    // current size of the queue i.e. only valid no. of elements
    int m_size = 0;

    // the total capacity of the queue including garbage space
    int m_capacity = 0;

  protected:
    // pointer to our queue data
    T *data;

    // extends the queue size by a factor of 2
    void extend() override;

  public:
    // default constructor
    Queue();

    // constructor with user defined capacity
    explicit Queue(const int &);

    // copy constructor to make deep copy of queue
    Queue(const Queue &);

    // destructor for freeing the queue memory once out of scope
    ~Queue();

    // appends an element to queue
    void enqueue(const T &);

    // removes and returns an element from front of queue
    T dequeue();

    // returns the front element of queue
    T peek() const;

    // overloading the + operator behaviour
    T operator+(int) const;

    // overloading the array access operator behaviour
    T operator[](int) const;

    // assignment operator to make deep copy
    Queue &operator=(const Queue &);

    // helper method to print the content of queue
    void print() const override;

    // method that check if queue is empty
    bool empty() const override;

    // returns the size of the queue
    inline int size() const override;

    // returns the capacity of the queue
    inline int capacity() const override;
};

// -------------------------------------------- Implementation --------------------------------------------------//

template <typename T>
Queue<T>::Queue() {
    data = new T[m_capacity];
}

template <typename T>
Queue<T>::Queue(const int &capacity) : m_capacity(capacity) {
    data = new T[capacity];
}

template <typename T>
Queue<T>::Queue(const Queue &q) {
    if (data)
        delete[] data;
    data = new T[q.capacity()];
    m_capacity = q.capacity();
    std::copy(q.data, q.data + q.size(), data);
    m_size = q.size();
}

template <typename T>
Queue<T>::~Queue() {
    delete[] data;
}

template <typename T>
void Queue<T>::extend() {
    T *aux = new T[2 * m_capacity];
    std::move(data, data + m_size, aux);
    delete[] data;
    data = aux;
    m_capacity *= 2;
}

template <typename T>
void Queue<T>::enqueue(const T &val) {
    if (m_size == m_capacity) {
        extend();
    }
    data[m_size++] = val;
}

template <typename T>
T Queue<T>::dequeue() {
    if (empty()) {
        throw std::runtime_error("data index out of bound");
    }
    T elem = peek();
    data++;
    m_size--;
    return elem;
}

template <typename T>
T Queue<T>::peek() const {
    if (empty()) {
        throw std::runtime_error("data index out of bound");
    }
    return data[0];
}

template <typename T>
T Queue<T>::operator+(int index) const {
    if (index >= m_size || index < 0) {
        throw std::runtime_error("data index out of bound");
    }
    return data[index];
}

template <typename T>
T Queue<T>::operator[](int index) const {
    if (index >= m_size || index < 0) {
        throw std::runtime_error("data index out of bound");
    }
    return data[index];
}

template <typename T>
Queue<T> &Queue<T>::operator=(const Queue &q) {
    if (this != &q) {
        if (data)
            delete[] data;
        data = new T[q.capacity()];
        m_capacity = q.capacity();
        std::copy(q.data, q.data + q.size(), data);
        m_size = q.size();
    }
    return *this;
}

template <typename T>
bool Queue<T>::empty() const {
    if (m_size == 0) {
        return true;
    }
    return false;
}

template <typename T>
void Queue<T>::print() const {
    for (int i = 0; i < m_size; i++) {
        std::cout << data[i] << ' ';
    }
    std::cout << '\n';
}

template <typename T>
inline int Queue<T>::size() const {
    return m_size;
}

template <typename T>
inline int Queue<T>::capacity() const {
    return m_capacity;
}
} // namespace ds