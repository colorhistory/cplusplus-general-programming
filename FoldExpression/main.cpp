/****************************************************************************
**
** Copyright (C) 2019 Xiaohai <xiaohaidotpro@outlook.com>.
** Contact: http://xiaohai.pro
**
** This file is part of cplusplus-general-programming
**
**
****************************************************************************/

#include "bits/stdc++.h"

#include "FoldExpression.hpp"

int main(int /* argc */, char ** /* argv */) {
    GP::Node *root = new GP::Node{0};
    root->left = new GP::Node{1};
    root->left->right = new GP::Node{2};

    GP::Node *node = GP::traverse(root, GP::left, GP::right);
    std::cout << node->value << std::endl;

    return 0;
}
