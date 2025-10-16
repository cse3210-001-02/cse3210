#ifndef AVLTREE_H_
#define AVLTREE_H_

#include <optional>

template <typename T>
class AVLTree {
public:
  struct Node {
    int height;
    T value;
    std::optional<Node const> *left;
    std::optional<Node const> *right;
    std::optional<Node const> *parent;
  };

  AVLTree();
  ~AVLTree();

  std::optional<Node const *> Find(T const &value) const;
  Node const Insert(T const &value);
  bool IsEmpty() const;
  std::optional<Node const *> GetPrevious(T const &value) const;
  std::optional<Node const *> GetNext(T const &value) const;
  std::optional<Node const *> GetUpperBound() const;
};

#endif
