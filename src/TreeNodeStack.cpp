//#include "TreeNodeStack.h"
//
//TreeNodeStack::TreeNodeStack() { top = nullptr; }
//
//void TreeNodeStack::push(TreeNode* newNode) {
//
//    if (top == nullptr) {
//        top = newNode;
//    }
//    else {
//        newNode->right=top;
//        top = newNode;
//    }
//}
//
//void TreeNodeStack::pop() {
//
//    TreeNode* aux = top;
//    top = top->right;
//    delete aux;
//}
//
//TreeNode* TreeNodeStack::getTop() { return top; }
//
//bool TreeNodeStack::isEmpty() {
//
//    if (top == nullptr) { return true; }
//
//    else { return false; }
//}
//
///**void TreeNodeStack::print(TreeNode* stack) {
//    if (stack == nullptr) { cout << "Final del stack" << endl; return; }
//    cout << stack->get_Value() << endl;
//    print(stack->get_next());
//} */
