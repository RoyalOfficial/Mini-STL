#pragma once
#include <iterator>
#include <algorithm>

namespace mini_stl {

// Simple linear search 
template<typename Iter, typename T>
Iter find(Iter begin, Iter end, const T& val) {
    for (Iter it = begin; it != end; ++it){
        if (*it == val)
            return it;
    }
    return end;
}

// Bubble sort ascending 
template<typename Iter>
void sort_ascending(Iter begin, Iter end){
    for (Iter i = begin; i != end; ++i)
        for (Iter j = begin; std::next(j) != end; ++j)
            if (*(std::next(j)) < *j) 
            std::swap(*j, *(std::next(j)));
    }

// Bubble sort descending
template<typename Iter>
void sort_descending(Iter begin, Iter end){
    for (Iter i = begin; i != end; ++i)
        for (Iter j = begin; std::next(j) != end; ++j)
            if (*(std::next(j)) > *j) 
            std::swap(*j, *(std::next(j)));
    }

} // namespace mini_stl