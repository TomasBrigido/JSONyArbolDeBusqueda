#include "TreeNode.h"

TreeNode::TreeNode() {
    key = "N";
    value = "N";
    left = nullptr;
    right = nullptr;
}

TreeNode::TreeNode(string parentID, string key, string value) {
    this->parentID = parentID;
    this->key = key;
    this->value = value;
    left = nullptr;
    right = nullptr;
}

string TreeNode::getValue(TreeNode* rootNode, string key) {

    TreeNode* aux = rootNode;

    if (aux->key == key) { return value; }

    else {
        aux = aux->left;
        while (true) {
            if(aux == nullptr){
                return "00";
            }

            if (aux->key == key) { break; }

            if (aux->value == "$") {
                aux = aux->left;
            }
            else { aux = aux->right; }
        }
        return aux->value;
    }
}

//void TreeNode::setValue(TreeNode* rootNode, string key, string newValue) {
//
//    TreeNode* aux = rootNode->left;
//
//    while (aux->key != key) {
//
//        if (aux->value == "$") {
//            aux = aux->left;
//        }
//        else { aux = aux->right; }
//    }
//    aux->value = newValue;
//}