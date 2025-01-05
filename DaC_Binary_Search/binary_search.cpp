#include <iostream>
#include <vector>
#include <algorithm>

// Binary search function
bool binary_search(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Avoid overflow
        if (arr[mid] == target) {
            return true;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return false;
}

// Main function to test the binary search
int main() {
    std::vector<int> arr = { 1, 3, 5, 7, 9, 11, 13, 15 };
    int target;

    std::cout << "Enter a number to search: ";
    std::cin >> target;

    // Ensure the array is sorted
    std::sort(arr.begin(), arr.end());

    if (binary_search(arr, target)) {
        std::cout << "Number " << target << " is found in the array." << std::endl;
    }
    else {
        std::cout << "Number " << target << " is not in the array." << std::endl;
    }

    return 0;
}
