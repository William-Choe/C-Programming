#ifndef LAB3_FUNCTIONS_H
#define LAB3_FUNCTIONS_H

template <typename T>
class functions {
public:
    void bubbleSort(T *arr, T n);

    void swap(T &val1, T &val2);
};

/* bubble sort */
template <typename T>
void functions<T>::bubbleSort(T *arr, T n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

/* swap to values */
template <typename T>
void functions<T>::swap(T &val1, T &val2) {
    T temp = val1;
    val1 = val2;
    val2 = temp;
}

#endif