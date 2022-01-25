#pragma once
#include <iostream>
#include <algorithm>
template <typename T>
void mySort(T* array, size_t N) {
    /*size = N;*/
    std::sort(array, array + N);
}
template<>
void mySort<char>(char* array, size_t N) {
    char temp;
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (toupper(array[i]) > toupper(array[j])) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}


