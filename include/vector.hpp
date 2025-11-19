// vector.hpp
#pragma once 
#include <cstddef>
/**
 * Custom implementation of vector.hpp
 * Author: Pietro Paniccia
 */
namespace mini_stl {

template<typename T>
class Vector {
private:
    T* data;
    size_t sz;
    size_t cap;

    // internal helper for resizing storage
    void reallocate(size_t newCap) {
        T* newData = new T[newCap];
        for (size_t i = 0; i < sz; i++){
            newData[i]= data[i];
        }
        delete[] data;
        data = newData;
        cap = newCap;
    };

public:
    // Constructor / Destructor
    Vector(){
        data = nullptr;
        sz = 0;
        cap = 0;
    };
    ~Vector(){
        delete [] data;
    };

    // Copy constructor 
    Vector(const Vector<T>& other) : sz(other.sz), cap(other.cap){
        data = new T[cap];
        for (size_t i = 0; i < sz; i++){
            data[i] = other.data[i];
        }
    }

    // Copy assignment
    Vector<T>& operator=(const Vector<T>& other){
        if (this != &other){ // protect against self assignment
            delete[] data;
            sz = other.sz;
            cap = other.cap;
            data = new T[cap];
            for (size_t i = 0; i < sz; i++){
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Capacity
    size_t size() const {
        return sz;
    };
    size_t capacity() const {
        return cap;
    };
    bool empty() const {
        return sz == 0; 
    };

    // Element access
    T& operator[](size_t index) {
        return data[index];
    };
    const T& operator[](size_t index) const {
        return data[index];
    };

    // Modifiers
    void push_back(const T& value) {
        if (sz == cap) {
            size_t newCap = (cap == 0 ? 1 : cap * 2); 
            reallocate(newCap);
        }
        data[sz] = value;
        sz++;
    };
    void pop_back() {
        if (sz > 0){
            sz--;
            data[sz].~T();
        }
    };
    void clear(){
        while (sz != 0){
            sz --;
            data[sz].~T();
        }
    };
    void reserve(size_t newCap){
        if (newCap > cap){
            reallocate(newCap);
        }
    };

    // Iterators
    T* begin() {
        return data;
    };
    T* end(){
        return data + sz;
    };
    const T* begin() const {
        return data;
    };
    const T* end() const{
        return data + sz;
    };

    // Dot product
    T dot(const Vector<T>& other) const {
        T result = 0; 
        if (sz == other.size()){
            for (int i = 0; i < sz; i++){
                result += (data[i] * other.data[i]);
            }
        }
        else {
            throw std::runtime_error("Vector sizes do not match for dot product");
        }
        return result;
    }

    // Vector addition 
    Vector<T> add(const Vector<T>& other) const {
        Vector<T> result;
        result.reserve(sz);
        if (sz == other.size()){
            for (size_t i = 0; i < sz; i++){
                result.push_back(data[i] + other.data[i]);
            }
            return result;
        }
        else {
            throw std::runtime_error("Vector sizes do not match for vector addition");
        }
    }
};
} // namespace mini_stl