#ifndef AVLTREE_H_
#define AVLTREE_H_

#include <cstddef>
template <typename T>
class AVLTree {
public:
  struct Node {
    int depth;
    int height;
    T const value;
    Node *left;
    Node *right;
    Node *parent;
  };

  AVLTree() = default;
  ~AVLTree() = default;

  Node *Find(T const &value) const;
  Node *Insert(T const &value);
  bool IsEmpty() const;
  std::size_t GetSize() const;
  Node *GetPrevious(T const &value) const;
  Node *GetNext(T const &value) const;
  Node *GetUpperBound(T const &value) const;

private:
  Node **Search(T const &value) const;
  void RotateLeft(Node *node);
  void RotateRight(Node *node);
};

#endif
