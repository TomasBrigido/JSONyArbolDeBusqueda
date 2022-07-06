#ifndef TP_2_ALGORITMOS_BINARYTREE_H
#define TP_2_ALGORITMOS_BINARYTREE_H

#pragma once

#include <iostream>
#include <string>
#include "TreeNode.h"
#include "TreeNodeStack.h"
#include <stack>
using namespace std;

class BinaryTree{
public:

    TreeNode* root;
    int count;

    BinaryTree();
    //BinaryTree(TreeNode* root);
    void insert(TreeNode* node, string parent, string key, string value);
    void preorderPrint(TreeNode* root, string sortParameter, bool flagAllJSON);
    void print(TreeNode* treeRoot, int space);
    void setRoot(TreeNode* root);
    TreeNode* getLastSubRoot();

};
#endif //TP_2_ALGORITMOS_BINARYTREE_H
