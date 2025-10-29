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

  enum ImbalnceType {
    kLeftLeft,
    kLeftRight,
    kRightRight,
    kRightLeft
  };

  AVLTree();
  ~AVLTree() = default;

  /**
   * 노드의 높이 반환
   */
  int GetHeight(Node *node) const;
  /**
   * 노드의 Balance Factor 반환
   */
  int GetBalanceFactor(Node *node) const;
  /**
   * 노드의 Imbalance Type 반환
   */
  ImbalnceType GetImbalanceType(Node *node) const;
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
  std::size_t size_;
  Node *root_;
  void RotateLeft(Node *node);
  void RotateRight(Node *node);
};

template <typename T>
AVLTree<T>::AVLTree() : root_(nullptr) {
}

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
AVLTree<T>::ImbalnceType AVLTree<T>::GetImbalanceType(Node *node) const {
  int balance_factor = GetBalanceFactor(node);

  // 각 불균형 유형을 반환
  if (balance_factor > 1) {
    if (GetBalanceFactor(node->left) >= 0) {
      return kLeftLeft;
    } else {
      return kLeftRight;
    }
  } else {
    if (GetBalanceFactor(node->right) <= 0) {
      return kRightRight;
    } else {
      return kRightLeft;
    }
  }
}

template <typename T>
AVLTree<T>::Node *AVLTree<T>::Insert(T const &value) {
  std::function<Node *(Node *)> insert = [&](Node *node) {
    if (node == nullptr) {
      // 노드가 들어갈 위치를 찾음
      return new Node{};
    }

    if (value < node->value) {
      return insert(node->left);
    } else if (value > node->value) {
      return insert(node->right);
    } else {
      // 중복된 값이 들어오는 경우
      return static_cast<Node *>(nullptr);
    }

    // 삽입 후 높이 갱신
    node->height = 1 + std::max(GetHeight(node->left), GetHeight(node->right));

    // 불균형 검사 및 회전
    auto imbalance_type = GetImbalanceType(node);
    switch (imbalance_type) {
    case kLeftLeft:
      RotateRight(node);
      break;
    case kLeftRight:
      RotateLeft(node->left);
      RotateRight(node);
      break;
    case kRightRight:
      RotateLeft(node);
      break;
    case kRightLeft:
      RotateRight(node->right);
      RotateLeft(node);
      break;
    }

    return node;
  };

  // 실제 삽입 수행
  auto node = insert(root_);

  // 삽입에 성공한 경우 크기 증가
  if (node != nullptr) {
    ++size_;
  }

  return node;
}

// 테스트를 위한 인스턴스화
template class AVLTree<int>;

#endif
