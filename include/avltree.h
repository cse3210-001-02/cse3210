#ifndef AVLTREE_H_
#define AVLTREE_H_

#include <cstddef>
#include <functional>

template <typename T>
class AVLTree {
public:
  struct Node {
    int height;
    T const value;
    Node *left;
    Node *right;
  };

  enum ImbalanceType {
    kLeftLeft,
    kLeftRight,
    kRightRight,
    kRightLeft,
    kBalanced
  };

  AVLTree() = default;
  ~AVLTree() = default;

  /**
   * 노드의 높이 반환
   */
  int GetHeight(Node *node) const;
  Node *Find(T const &value) const;
  Node *Insert(T const &value);
  Node *Erase(T const &value);
  /**
   * $O(1)$ 수행
   */
  bool IsEmpty() const;
  /**
   * $O(1)$ 수행
   */
  std::size_t GetSize() const;
  Node *GetPrevious(T const &value) const;
  Node *GetNext(T const &value) const;
  Node *GetUpperBound(T const &value) const;

private:
  std::size_t size_ = 0;
  Node *root_ = nullptr;
  /**
   * 노드의 Balance Factor 반환
   */
  int GetBalanceFactor(Node *node) const;
  /**
   * 노드의 Imbalance Type 반환
   */
  ImbalanceType GetImbalanceType(Node *node, T const &value) const;
  Node *RotateLeft(Node *node);
  Node *RotateRight(Node *node);
};

template <typename T>
int AVLTree<T>::GetHeight(Node *node) const {
  if (node == nullptr) {
    return 0;
  }

  return node->height;
}

template <typename T>
int AVLTree<T>::GetBalanceFactor(Node *node) const {
  if (node == nullptr) {
    return 0;
  }

  return GetHeight(node->left) - GetHeight(node->right);
}

template <typename T>
AVLTree<T>::ImbalanceType AVLTree<T>::GetImbalanceType(Node *node,
                                                       T const &value) const {
  int balance_factor = GetBalanceFactor(node);

  // 각 불균형 유형을 반환
  if (balance_factor > 1) {
    if (value < node->left->value) {
      return kLeftLeft;
    } else {
      return kLeftRight;
    }
  } else if (balance_factor < -1) {
    if (value > node->right->value) {
      return kRightRight;
    } else {
      return kRightLeft;
    }
  }

  return kBalanced;
}

template <typename T>
AVLTree<T>::Node *AVLTree<T>::Insert(T const &value) {
  std::function<Node *(Node *)> insert = [&](Node *node) {
    if (node == nullptr) {
      // 노드가 들어갈 위치를 찾음
      return new Node{1, value, nullptr, nullptr};
    }

    if (value < node->value) {
      node->left = insert(node->left);
    } else if (value > node->value) {
      node->right = insert(node->right);
    } else {
      // 중복된 값이 들어오는 경우
      return static_cast<Node *>(nullptr);
    }

    // 삽입 후 높이 갱신
    node->height = 1 + std::max(GetHeight(node->left), GetHeight(node->right));

    // 불균형 검사 및 회전
    auto imbalance_type = GetImbalanceType(node, value);
    switch (imbalance_type) {
    case kLeftLeft:
      return RotateRight(node);
    case kLeftRight:
      node->left = RotateLeft(node->left);
      return RotateRight(node);
    case kRightRight:
      return RotateLeft(node);
    case kRightLeft:
      node->right = RotateRight(node->right);
      return RotateLeft(node);
    case kBalanced:
      // 아무 작업도 수행하지 않음
      break;
    }

    return node;
  };

  // 실제 삽입 수행
  root_ = insert(root_);

  // 삽입에 성공한 경우 크기 증가
  if (root_ != nullptr) {
    ++size_;
  }

  return root_;
}

// 테스트를 위한 인스턴스화
template class AVLTree<int>;

#endif
