// by mhgffqwoer
#include <iostream>

// func merge memory O(n)
void mergeN(int* arr, const int& left, const int& mid, const int& right) {
  int it1 = 0;
  int it2 = 0;
  int result[right - left];

  while ((left + it1 < mid) && (mid + it2 < right)) {
    if (arr[left + it1] < arr[mid + it2]) {
      result[it1 + it2] = arr[left + it1];
      ++it1;
    } else {
      result[it1 + it2] = arr[mid + it2];
      ++it2;
    }
  }

  while (left + it1 < mid) {
    result[it1 + it2] = arr[left + it1];
    ++it1;
  }

  while (mid + it2 < right) {
    result[it1 + it2] = arr[mid + it2];
    ++it2;
  }

  for (int i = 0; i < it1 + it2; ++i) {
    arr[left + i] = result[i];
  }
}

// recursive calls
void mergeSortRecursive(int* arr, const int& left, const int& right) {
  if ((left + 1) >= right) return;
  int mid = (left + right) / 2;
  mergeSortRecursive(arr, left, mid);
  mergeSortRecursive(arr, mid, right);
  mergeN(arr, left, mid, right);
}

// iterative calls
void mergeSortIterative(int* arr, const int& size) {
  for (int i = 1; i < size; i *= 2) {
    for (int j = 0; j < size - i; j += 2 * i) {
      mergeN(arr, j, j + i, std::min(j + 2 * i, size));
    }
  }
}

int main(void) {
  int arr[] = {10, 6, 4, 2, 7, 3, 8, 5, 1, 9, 0};
  int size = sizeof(arr) / sizeof(arr[0]);

  mergeSortIterative(arr, size);
  // mergeSortRecursive(arr, 0, size);

  for (int i = 0; i < size; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}
