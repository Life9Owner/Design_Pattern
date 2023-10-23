#include <iostream>  // Include this for debugging

template <class ForwardIterator, class T>
ForwardIterator remove(ForwardIterator first, ForwardIterator last, const T& val) {
    ForwardIterator result = first;

    while (first != last) {
        if (!(*first == val)) {
            if (result != first)
                *result = *first;
            ++result;
        }
        ++first;
    }

    return result;
}

int main() {
    // Example usage and debugging
    int arr[] = {1, 2, 3, 2, 4, 5, 2};
    int* end = arr + 7;

    std::cout << "Original array: ";
    for (int* ptr = arr; ptr != end; ++ptr) {
        std::cout << *ptr << " ";
    }
    std::cout << "\n";

    int* newEnd = remove(arr, end, 2);

    std::cout << "Array after removing 2s: ";
    for (int* ptr = arr; ptr != newEnd; ++ptr) {
        std::cout << *ptr << " ";
    }
    std::cout << "\n";

    return 0;
}
