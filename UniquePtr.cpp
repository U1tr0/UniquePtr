#include "UniquePtr.h"

template<typename T>
UniquePtr<T>::UniquePtr() {
    this->_ptr = nullptr;
}

template<typename T>
UniquePtr<T>::UniquePtr(T* ptr) {
    this->_ptr = ptr;
}

template<typename T>
UniquePtr<T>::UniquePtr(UniquePtr<T>&& other) noexcept{
    this->_ptr = other->_ptr;
    other->_ptr = nullptr;
}

template<typename T>
UniquePtr<T>::~UniquePtr() {
    delete[] _ptr;
    this->_ptr = nullptr;
}

template<typename T>
UniquePtr<T>& UniquePtr<T>::operator=(UniquePtr<T>&& other) noexcept {
    this->reset();
    _ptr = other._ptr;
    other._ptr = nullptr;
    return *this;
}

template<typename T>
UniquePtr<T>& UniquePtr<T>::operator=(T* ptr) {
     this->reset();
    _ptr = ptr;
    return *this;
}

template<typename T>
T& UniquePtr<T>::operator*() const {
    return *_ptr;
}

template<typename T>
T* UniquePtr<T>::operator->() const {
    return _ptr;
}

template<typename T>
T& UniquePtr<T>::operator[](const size_t idx) {
    return _ptr[idx];
}

template<typename T>
const T& UniquePtr<T>::operator[](const size_t idx) const {
    return _ptr[idx];
}

template<typename T>
T* UniquePtr<T>::get() const {
    return _ptr;
}

template<typename T>
UniquePtr<T>::operator bool() const {
    return _ptr != nullptr;
}

template<typename T>
void UniquePtr<T>::reset() {
    delete _ptr;
    _ptr = nullptr;
}

template<typename T>
void UniquePtr<T>::reset(T* ptr) {
    delete _ptr;
    _ptr = ptr;
}

template<typename T>
void UniquePtr<T>::release() {
    delete _ptr;
    _ptr = nullptr;
}








