#ifndef AVLTREE_H_
#define AVLTREE_H_

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
  Node *GetPrevious(T const &value) const;
  Node *GetNext(T const &value) const;
  Node *GetUpperBound(T const &value) const;

private:
  void RotateLeft(Node *node);
  void RotateRight(Node *node);
};

#endif
