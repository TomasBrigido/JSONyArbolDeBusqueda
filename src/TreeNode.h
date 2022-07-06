#ifndef TP_2_ALGORITMOS_TREENODE_H
#define TP_2_ALGORITMOS_TREENODE_H


#pragma once

#include <iostream>
#include <string>
using namespace std;

class TreeNode{

public:

    TreeNode* left;    // info
    TreeNode* right;  // hermano
    string key;
    string value;
    string parentID;

    TreeNode();
    TreeNode(string parentID,string key,string value);
    string getValue(TreeNode* rootNode, string key);
    //void setValue(TreeNode* rootNode, string key, string newValue);
};

#endif //TP_2_ALGORITMOS_TREENODE_H
