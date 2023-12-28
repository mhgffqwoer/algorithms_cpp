// by mhgffqwoer
#include <iostream>

void InsertionSort(int* arr, const int& size) {
  for (int i = 1; i < size; ++i) {
    int temp = i;
    for (int j = i - 1; j >= 0; --j) {
      if (arr[j] > arr[temp]) {
        std::swap(arr[j], arr[temp]);
        temp = j;
      } else break;
    }
  }
}

int main(void) {
  int arr[] = {10, 6, 4, 2, 7, 3, 8, 5, 1, 9, 0};
  int size = sizeof(arr) / sizeof(arr[0]);

  InsertionSort(arr, size);

  for (int i = 0; i < size; ++i)
    std::cout << arr[i] << " ";
  std::cout << std::endl;
}
