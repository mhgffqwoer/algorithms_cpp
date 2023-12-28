// by mhgffqwoer
#include <iostream>
#include <stack>

// partition into two subset
int partition(int *arr, const int &left, const int &right) {
  int mid = arr[(left + right) / 2];
  int i = left;
  int j = right;
  while (i <= j) {
    while (arr[i] < mid) ++i;
    while (arr[j] > mid) --j;
    if (i >= j) break;
    std::swap(arr[i++], arr[j--]);
  }
  return j;
}

// recursive calls
void QuickSortRecursive(int *arr, const int &left, const int &right) {
  if (left < right) {
    int p = partition(arr, left, right);
    QuickSortRecursive(arr, left, p);
    QuickSortRecursive(arr, p + 1, right);
  }
}

// iterative calls
void QuickSortIterative(int *arr, int left, int right) {
  std::stack<std::pair<int, int>> stack;
  stack.push({left, right});
  while (!stack.empty()) {
    left = stack.top().first;
    right = stack.top().second;
    stack.pop();
    if (right <= left) continue;
    int i = partition(arr, left, right);
    stack.push({left, i});
    stack.push({i + 1, right});
  }
}

int main(void) {
  int arr[] = {10, 6, 4, 2, 7, 3, 8, 5, 1, 9, 0};
  int size = sizeof(arr) / sizeof(arr[0]);

  QuickSortIterative(arr, 0, size - 1);

  for (int i = 0; i < size; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}
