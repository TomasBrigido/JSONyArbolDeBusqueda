#ifndef TP_2_ALGORITMOS_SORT_H
#define TP_2_ALGORITMOS_SORT_H

#pragma once
#include "TreeNode.h"
class Sort{

public:
    Sort();
    void swap(TreeNode*& value1, TreeNode*& value2);

    TreeNode* partition(TreeNode* firstNode,TreeNode* lastNode,string sortParameter);
    bool compareString(string first, string second);
    void quickSort(TreeNode* firstNode,TreeNode* lastNode, string sortParameter);
    void bubbleSort(TreeNode* firstNode,string parameter);
    void selectionSort(TreeNode* firstNode,string sortParameter);
};

#endif //TP_2_ALGORITMOS_SORT_H
