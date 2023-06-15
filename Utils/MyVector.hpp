#pragma once

#include "iostream"
template <typename T>
class MyVector{
private:
    T* data = nullptr;
    size_t size = 0;
    size_t capacity;

    void resize(size_t newCapacity);

    void validateIndex(size_t index) const;
    void upsizeIfNeeded();
    void downsizeIfNeeded();
public:
    MyVector();
    MyVector(size_t capacity);
    explicit MyVector(const T* elements, size_t length);
    MyVector(const MyVector<T>& other);
    MyVector<T>& operator=(const MyVector<T>& other);
    MyVector(MyVector<T>&& other); // move semantics
    MyVector<T>& operator=(MyVector<T>&& other);
    ~MyVector();

    size_t getSize() const;
    size_t getCapacity() const;

    void pushBack(const T& element);
    void pushBack(T&& element);
    void pushAt(const T& element, size_t index);
    void pushAt(T&& element, size_t index);
    T popBack();
    T popAt(size_t index);
    bool isEmpty() const;
    void clear();
    void shrinkToFit();

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

private:
    void free();
    void copyFrom(const MyVector<T>& other);
    void moveFrom(MyVector<T>&& other);
};

namespace {
    const short INITIAL_CAPACITY = 4;
    const short RESIZE_COEFFICIENT = 2;
}

template<class T>
MyVector<T>::MyVector() : MyVector(INITIAL_CAPACITY) {}

template<class T>
MyVector<T>::MyVector(size_t capacity) : capacity(capacity){
    data = new T[capacity];
}

template<class T>
MyVector<T>::MyVector(const MyVector<T> &other) {
    copyFrom(other);
}

template<class T>
MyVector<T> &MyVector<T>::operator=(const MyVector<T> &other) {
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}

template<class T>
MyVector<T>::MyVector(MyVector<T> &&other) {
    moveFrom(std::move(other));
}

template<class T>
MyVector<T> &MyVector<T>::operator=(MyVector<T> &&other) {
    if(this != &other){
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

template<class T>
MyVector<T>::~MyVector() {
    free();
}

template<class T>
void MyVector<T>::validateIndex(size_t index) const {
    if(index >= size){
        throw std::invalid_argument("Error");
    }
}

template<class T>
void MyVector<T>::upsizeIfNeeded() {
    if(size == capacity) // TODO: check why here is unreachable code
        resize(capacity * RESIZE_COEFFICIENT);
}

template<class T>
void MyVector<T>::downsizeIfNeeded() {
    if(size * RESIZE_COEFFICIENT * RESIZE_COEFFICIENT <= capacity)
        resize(capacity / RESIZE_COEFFICIENT);
}

template<class T>
void MyVector<T>::resize(size_t newCapacity) { // TODO: check why here is unreachable code
    this->capacity = newCapacity;
    T* temp = new T[newCapacity];
    if(size > newCapacity){
        size = newCapacity;
    }
    for (size_t i = 0; i < size; ++i) {
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;
}

template<class T>
size_t MyVector<T>::getSize() const {
    return this->size;
}

template<class T>
size_t MyVector<T>::getCapacity() const {
    return this->capacity;
}

template<class T>
void MyVector<T>::pushBack(const T &element) {
    upsizeIfNeeded();
    data[size++] = element;
}

template<class T>
void MyVector<T>::pushBack(T &&element) {
    upsizeIfNeeded();
    data[size++] = std::move(element);
}

template<class T>
void MyVector<T>::pushAt(const T &element, size_t index) {
    validateIndex(index);
    upsizeIfNeeded();
    for (int i = size; i > index; --i) {
        data[i] = data[i-1]; // push back the elements which are from the right of the index where we want to push
    }
    data[index] = element;
    size++;
}

template<class T>
void MyVector<T>::pushAt(T &&element, size_t index) {
    validateIndex(index);
    upsizeIfNeeded();
    for (int i = size; i > index; --i) {
        data[i] = data[i-1]; // push back the elements which are from the right of the index where we want to push
    }
    data[index] = std::move(element);
    size++;
}

template<class T>
T MyVector<T>::popBack() {
    if(isEmpty())
        throw std::invalid_argument("Vector is empty!");
    return data[--size];
}

template<class T>
T MyVector<T>::popAt(size_t index) {
    validateIndex(index);
    downsizeIfNeeded();
    T elementToReturn = data[index];
    size--;
    for (size_t i = index; i < size; ++i) {
        data[i] = data[i+1];
    }
    return elementToReturn;
}

template<class T>
bool MyVector<T>::isEmpty() const {
    return size == 0;
}

template<class T>
void MyVector<T>::clear() {
    size = 0;
}

template<class T>
void MyVector<T>::shrinkToFit() {
    resize(size);
}

template<class T>
T &MyVector<T>::operator[](size_t index) {
    validateIndex(index);
    return data[index];
}

template<class T>
const T &MyVector<T>::operator[](size_t index) const {
    validateIndex(index);
    return data[index];
}

template<class T>
void MyVector<T>::free() {
    delete[] data;
    data = nullptr;
    size = capacity = 0;
}

template<class T>
void MyVector<T>::copyFrom(const MyVector<T> &other) {
    size = other.size;
    capacity = other.capacity;
    data = new T[capacity];
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

template<class T>
void MyVector<T>::moveFrom(MyVector<T> &&other) {
    size = other.size;
    capacity = other.capacity;
    data = other.data;
    other.data = nullptr;
}

template<typename T>
MyVector<T>::MyVector(const T *elements, size_t length) {
    this->size = this->capacity = length;
    data = new T[length];
    for (int i = 0; i < length; ++i) {
        this->pushBack(elements[i]);
    }
}
