// by mhgffqwoer
#include <iostream>

template <typename T>
class Queue {
 private:
  struct Node {
    T data_;
    Node* next_;
  };

  Node* head_;
  Node* tail_;
  int size_;

 public:
  Queue() : head_(nullptr), tail_(nullptr), size_(0) {}

  ~Queue() {
    Node* current = head_;
    while (current != nullptr) {
      Node* next_ = current->next_;
      delete current;
      current = next_;
    }
  }

  Queue(const Queue& other) : head_(nullptr), tail_(nullptr), size_(0) {
    Node* current = other.head_;
    while (current != nullptr) {
      push(current->data_);
      current = current->next_;
    }
  }

  Queue& operator=(const Queue& other) {
    if (this == &other) return *this;
    clear();
    Node* current = other.head_;
    while (current != nullptr) {
      push(current->data_);
      current = current->next_;
    }
    return *this;
  }

  bool empty() const { return size_ == 0; }

  int size() const { return size_; }

  T front() {
    if (empty()) throw std::out_of_range("queue is empty");
    return head_->data_;
  }

  T back() {
    if (empty()) throw std::out_of_range("queue is empty");
    return tail_->data_;
  }

  void push(const T& data_) {
    Node* node = new Node;
    node->data_ = data_;
    node->next_ = nullptr;

    if (empty()) head_ = node;
    else tail_->next_ = node;

    tail_ = node;
    size_++;
  }

  void pop() {
    if (empty()) throw std::out_of_range("queue is empty");
    Node* node = head_;
    head_ = head_->next_;
    delete node;
    size_--;
  }


  void clear() {
	Node* current = head_;
	while (current != nullptr) {
	  Node* next_ = current->next_;
	  delete current;
	  current = next_;
	}
	head_ = nullptr;
	tail_ = nullptr;
	size_ = 0;
  }
};

int main(void) {
  Queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  std::cout << q.front() << std::endl;
  std::cout << q.back() << std::endl;
  q.pop();
  std::cout << q.front() << std::endl;
  std::cout << q.back() << std::endl;
  q.clear();
  std::cout << q.empty() << std::endl;
}