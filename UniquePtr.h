#pragma once
#include <cstdlib>

template<typename T>
class UniquePtr {
public:
    UniquePtr();
    explicit UniquePtr(T* ptr);
    UniquePtr(const T& other) = delete;
    UniquePtr(UniquePtr&& other) noexcept;
    UniquePtr(const UniquePtr& other) = delete;

    ~UniquePtr();

    UniquePtr& operator=(UniquePtr&& other) noexcept;
    UniquePtr& operator=(const UniquePtr& other) = delete;
    UniquePtr& operator=(T* ptr);

    T& operator*() const;
    T* operator->() const;
    T& operator[](const size_t idx);
    const T& operator[](const size_t idx) const;
    T* get() const;
    operator bool() const;

    void reset();
    void reset(T* ptr);
    void release();
private:
    T* _ptr;
};


