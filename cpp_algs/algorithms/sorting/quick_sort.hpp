#pragma once

/**
 * Algorithms - sorting
 * quick_sort.hpp
 * Purpose: Performs quick sort on an array
 * 
 * @author Prabhsimran Singh
 * @version 1.0 11/09/18
*/
#include <bits/stdc++.h>
#include <iostream>

namespace al {

template <typename T>
int partition(T *, const int &, const int &);

template <typename T>
void qsort(T *, const int &, const int &);

/**
 * Sorts an array using Quick Sort algorithm.
 * 
 * @param arr the array to sort (type T).
 * @param size the size of the array.
*/
template <typename T>
void quickSort(T *, const int &, bool = true);

template <typename T>
int partition(T *arr, const int &lo, const int &hi) {
    int i = lo;
    int j = hi + 1;
    T v = arr[lo];
    while (true) {
        while (arr[++i] < v)
            if (i == hi)
                break;
        while (v < arr[--j])
            if (j == lo)
                break;
        if (i >= j)
            break;
        std::swap(arr[i], arr[j]);
    }
    std::swap(arr[lo], arr[j]);
    return j;
}

template <typename T>
void qsort(T *arr, const int &lo, const int &hi) {
    if (hi <= lo)
        return;
    int p = partition(arr, lo, hi);
    qsort(arr, lo, p - 1);
    qsort(arr, p + 1, hi);
}

template <typename T>
void quickSort(T *arr, const int &size) {
    // randomize the array to make
    // worst case time O(nlogn) - has
    // huge affect with very large inputs
    // i.e. ~1M elements.
    std::random_shuffle(arr, arr + size);
    qsort(arr, 0, size - 1);
}
} // namespace al