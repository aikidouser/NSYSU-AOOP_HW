#ifndef __VECTOR_H_INCLUDED__
#define __VECTOR_H_INCLUDED__
#define __TRACE__

#include <iostream>

#include "Trace.h"

using std::cout;

template <typename T>
class vector {
   public:
    inline vector(const int& s = 0) {
        TRACE(dummy, "vector<T>::vector(int)");
        vec = new T[s];
        cout << "  count = " << ++count << endl;
    }
    ~vector() {
        TRACE(dummy, "vector<T>::~vector");
        cout << "  count = " << count-- << endl;

        delete[] vec;
    }

    inline T& operator[](int i) {
        return vec[i];
    };

   private:
    int count;
    T* vec;
};

template <>
class vector<void*> {
   public:
    vector(const int& s = 0) {
        TRACE(dummy, "vector<void*>::vector(int)");
        ptr = new void*[s];

        cout << "  count = " << ++count << endl;
    }
    ~vector() {
        TRACE(dummy, "vector<void*>::~vector");

        cout << "  count = " << count-- << endl;
        delete[] ptr;
    }

    inline void*& elem(int i) {
        return ptr[i];
    }

    inline void*& operator[](int i) {
        return ptr[i];
    }

   private:
    void** ptr;
    static int count;
};

template <typename T>
class vector<T*> : public vector<void*> {
   public:
    vector(const int& s = 0) : vector<void*>::vector(s) {
        TRACE(dummy, "vector<T*>::vector(int)");
    }
    ~vector() {
        TRACE(dummy, "vector<T*>::~vector");
    }

    inline T*& elem(int i) {
        return reinterpret_cast<T*&>(vector<void*>::elem(i));
    }

    inline T*& operator[](int i) {
        return reinterpret_cast<T*&>(vector<void*>::operator[](i));
    }
};

#endif  // __VECTOR_H_INCLUDED__