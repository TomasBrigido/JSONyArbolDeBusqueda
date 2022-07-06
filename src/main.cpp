#include "JsonLect.h"
#include "Sort.h"
int main() {

    JsonLect json;

    json.testing();
    Sort sortTest;

    //Parametro de ordenamiento
    string sortParameter = "surname";

    //Impresion JSON completo
    //json.treeBinary.preorderPrint(json.treeBinary.root,sortParameter,true);

    //Metodos de ordenamiento
    sortTest.quickSort(json.treeBinary.root->left, json.treeBinary.getLastSubRoot(), sortParameter);
    //sortTest.bubbleSort(json.treeBinary.root->left,sortParameter);
    //sortTest.selectionSort(json.treeBinary.root->left,sortParameter);

    //Impresion
    json.treeBinary.preorderPrint(json.treeBinary.root,sortParameter,false);

    return 0;
}
