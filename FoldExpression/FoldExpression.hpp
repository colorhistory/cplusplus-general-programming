#ifndef FOLDEXPRESSION_HPP
#define FOLDEXPRESSION_HPP

namespace GP {

    struct Node {
        Node(int i = 0) : value{i}, left{nullptr}, right{nullptr} {
        }

        int value;
        Node *left;
        Node *right;
    };

    auto left = &Node::left;
    auto right = &Node::right;

    template <typename T, typename... TP>
    Node *traverse(T np, TP... paths) {
        return (np->*...->*paths);
    }

}  // namespace GP

#endif  // FOLDEXPRESSION_HPP
