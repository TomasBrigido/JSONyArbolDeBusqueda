#include "BinaryTree.h"

BinaryTree::BinaryTree() {root = nullptr;}

//BinaryTree::BinaryTree(TreeNode* root) { this->root = root;}

void BinaryTree::insert(TreeNode* node, string parentID, string key, string value) {

    // inserción del primer nodo(a la izquierda de la raiz)

    if (node == nullptr ) {
        TreeNode* newNode = new TreeNode(parentID, key, value);
        root->left = newNode;
        return;
    }

    TreeNode* aux = node;

    if (aux->key == key) {
        while (aux->right!=nullptr) {
            aux = aux->right;
        }
        TreeNode* newNode = new TreeNode(parentID, key, value);
        aux->right = newNode;
        return;
    }

    if (aux->value!=parentID) {
        while (aux->value!= parentID) {
            aux = aux->right;
        }
    }
    if (aux->left == nullptr) {
        TreeNode* newNode = new TreeNode(parentID, key, value);
        aux->left = newNode;
        return;
    }
    else {
        aux = aux->left;
        while (true) {

            if (aux->right == nullptr && aux->left == nullptr) {
                break;
            }

            else if (aux->value == "$") {
                aux = aux->left;
            }
            else { aux = aux->right; }

        }

        TreeNode* newNode = new TreeNode(parentID, key, value);

        if (aux->value == "$") { aux->left = newNode; }

        else { aux->right = newNode; }
    }

}

void BinaryTree::print(TreeNode* treeRoot, int space) {

    if (treeRoot == nullptr) {
        return;
    }
    space += count;

    print(treeRoot->right, space); // searches through the right subtree until it finds
    // the right most leaf node and prints it
    cout << "\n";

    for (int i = count; i < space; i++) {
        cout << " ";
    }
    cout << treeRoot->key<<":"<<treeRoot->value;

    print(treeRoot->left, space);
}

void BinaryTree::preorderPrint(TreeNode* root, string sortParameter, bool flagAllJSON) {

    if (root == nullptr){ return;}

    stack<TreeNode*> nodeStack;
    nodeStack.push(root);

    while (nodeStack.empty() == false) {

        TreeNode* node = nodeStack.top();
        if(!flagAllJSON){
            if (node->key == "id") {
                cout<<"-----------------------------------"<< endl;
                cout << "  " << node->key << " : " << node->value << endl;
            }
            if (node->key == "firstname") {
                cout << "  " << node->key << " : " << node->value << endl;
            }
            if (node->key == "gender") {
                cout << "  " << node->key << " : " << node->value << endl;
            }
            if (node->key == sortParameter) {
                cout << "  " << node->key << " : " << node->value << endl;
            }
        }else {
            if (node->value == "$") {
                cout << node->key << " {" << endl;
            } else {
                cout << "  " << node->key << " : " << node->value << endl;
            }
        }
        nodeStack.pop();

        if (node->right) {
            nodeStack.push(node->right);
        }
        if ( node->left) {
            nodeStack.push(node->left);
        }
    }
}

TreeNode* BinaryTree::getLastSubRoot() {

    TreeNode* temp = root->left;

    while (temp != nullptr && temp->right != nullptr) {
        temp = temp->right;
    }
    return temp;
}

void BinaryTree::setRoot(TreeNode *root) {
    this->root = root;
}