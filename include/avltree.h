#ifndef AVLTREE_H_
#define AVLTREE_H_

template <typename T>
class AVLTree {
public:
  struct Node {
    int height;
    T const value;
    Node *left;
    Node *right;
    Node *parent;
  };

  AVLTree() = default;
  ~AVLTree() = default;

  Node *Find(T const &value) const;
  Node const *Insert(T const &value);
  bool IsEmpty() const;
  Node *GetPrevious(T const &value) const;
  Node *GetNext(T const &value) const;
  Node *GetUpperBound(T const &value) const;
};

#endif
