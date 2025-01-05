#include <iostream>
#include <vector>

// Partition function
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1;       // Index for the smaller element

    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++; // Move the index for the smaller element
            std::swap(arr[i], arr[j]); // Swap elements
        }
    }
    // Place the pivot in its correct position
    std::swap(arr[i + 1], arr[high]);
    return i + 1; // Return the partition index
}

// Quick sort function
void quick_sort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after the partition
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int main() {
    std::vector<int> arr = { 10, 7, 8, 9, 1, 5 };

    std::cout << "Original array: ";
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;

    quick_sort(arr, 0, arr.size() - 1);

    std::cout << "Sorted array: ";
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}
