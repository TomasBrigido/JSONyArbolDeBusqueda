#include "Sort.h"

Sort::Sort(){ }

void Sort::swap(TreeNode*& p1, TreeNode*& p2) {
    TreeNode* aux = p1;
    p1 = p2;
    p2 = aux;
}

TreeNode* Sort::partition(TreeNode* first, TreeNode* last,string sortParameter) {

    TreeNode* pivot = first;
    TreeNode* front = first;
    string temp = " ";
    while (front != nullptr && front != last){

        if ( compareString(last->getValue(last,sortParameter), front->getValue(front,sortParameter) ) ) {

            pivot = first;
            //Swap valor de los nodos
            temp = first->value;
            first->value = front->value;
            front->value = temp;
            // Swap punteros
            swap(first->left, front->left);

            first = first->right;
        }

        front = front->right;
    }
    //Cambiar ultimo valor del nodo al valor del nodo actual
    temp = first->value;
    first->value = last->value;
    last->value = temp;

    swap(first->left, last->left);

    return pivot;
}

void Sort::quickSort(TreeNode* first, TreeNode* last,string sortParameter) {

    if (first == last) {
        return;
    }
    //Encontrar pivot
    TreeNode* pivot = this->partition(first, last, sortParameter);
    if (pivot != nullptr && pivot->right != nullptr) {
        this->quickSort(pivot->right, last, sortParameter);
    }
    if (pivot != nullptr && first != pivot) {
        this->quickSort(first, pivot, sortParameter);
    }
}

bool Sort::compareString(string first, string second) {

    if (first == second ) {
        return true;
    }
    int largo;
    //Utiliza el largo mas grande
    if (first.length() > second.length()) {
        largo = first.length();
    }
    else {
        largo = second.length();
    }
    if (first == "" || second == "") {
        return false;
    }

    for (int i = 0; i <= largo; i++) {

        try {
            if (first.at(i) );
        }
        catch (exception e) {
            return false;
        }
        try {
            if (second.at(i));
        }
        catch (exception e) {
            return true;
        }

        if (first.at(i) < second.at(i) ) {
            //Retorna false si "first" es mas chico que "second" en ASCII
            //por lo que iria primero en orden alfabetico
            return false;
        }
        else if (first.at(i) > second.at(i)) {
            //Retorna true si "first" es mas grande que "secondo" en ASCII
            //por lo que iria segundo en orden alfabetico
            return true;
        }
    }
    return NULL;

}

void Sort::bubbleSort(TreeNode* firstNode, string sortParameter) {

    int swapped;

    TreeNode* lPtr;  //Principio; //Este puntero izquierdo siempre apunta al principio de la lista
    TreeNode* end = nullptr; //Final; //Este puntero izquierdo siempre apunta al final de la lista
    do
    {
        swapped = 0;
        lPtr = firstNode;
        while (lPtr->right != end)
        {
            if (compareString(lPtr->getValue(lPtr, sortParameter), lPtr->right->getValue(lPtr->right, sortParameter) ) ){                   //lPtr->value > lPtr->next->data

                //Swap valor de los nodos
                string aux = lPtr->value;
                lPtr->value = lPtr->right->value;
                lPtr->right->value = aux;

                //Swap de los punteros
                swap(lPtr->left, lPtr->right->left);
                swapped = 1;
            }
            lPtr = lPtr->right;
        }
        //Como el ultimo elemento esta al final de la lista se lo asigna a end, porque la lista ya esta ordenada
        end = lPtr;

    } while (swapped);
}

void Sort::selectionSort(TreeNode* firstNode,string sortParameter) {

    TreeNode* aux = firstNode;

    // Recorrer la lista
    while (aux !=nullptr) {

        TreeNode* min = aux;
        TreeNode* r = aux->right;

        // Recorrer la sublista desordenada
        while (r) {
            if (compareString(min->getValue(min, sortParameter), r->getValue(r, sortParameter))){
                min = r;
            }
            r = r->right;
        }

        string x = aux->value;
        aux->value = min->value;
        min->value = x;

        swap(aux->left, min->left);
        aux = aux->right;
    }
}