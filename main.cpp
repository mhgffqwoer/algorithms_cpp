// by mhgffqwoer
#include <iostream>

int max_arr(int *arr, const int& size){
	int m = 0;
	for (int i = 0; i < size; ++i){
		if (arr[i] > m) m = arr[i];
	}
	return m;
}

void CountingSort(int* arr, const int& size, const int& max_elem) {
	int count[max_elem + 1];
  for (int i = 0; i < max_elem + 1; ++i){
        count[i] = 0;
	}
  for (int i = 0; i < size; ++i){
    count[arr[i]] += 1;
	}
	int pos = 0;
  for (int i = 0; i < max_elem+1; ++i){
    for (int j = 0;  j < count[i]; ++j){
      arr[pos] = i;
    	++pos;
		}
	}
}

int main(void) {
    int arr[] = {10, 6, 4, 2, 7, 3, 8, 5, 1, 9, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
		int max_elem = max_arr(arr, size);

    CountingSort(arr, size, max_elem);

    for (int i = 0; i < size; ++i) {
      std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
