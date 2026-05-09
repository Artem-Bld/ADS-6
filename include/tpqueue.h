// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
  struct Node {
    T data;
    Node* next;
    Node(const T& val) : data(val), next(nullptr) {}
  };
  Node* head;
 public:
  TPQueue() : head(nullptr) {}
  ~TPQueue() {
    while (head != nullptr) {
      Node* tmp = head;
      head = head->next;
      delete tmp;
    }
  }
  TPQueue(const TPQueue&) = delete;
  TPQueue& operator=(const TPQueue&) = delete;
  void push(const T& val) {
    Node* newNode = new Node(val);
    if (head == nullptr || val.prior > head->data.prior) {
      newNode->next = head;
      head = newNode;
    } else {
      Node* curr = head;
      while (curr->next != nullptr && curr->next->data.prior >= val.prior) {
        curr = curr->next;
      }
      newNode->next = curr->next;
      curr->next = newNode;
    }
  }
  T pop() {
    if (head == nullptr) {
      throw std::out_of_range("TPQueue is empty");
    }
    Node* tmp = head;
    T result = head->data;
    head = head->next;
    delete tmp;
    return result;
  }
  bool isEmpty() const {
    return head == nullptr;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
