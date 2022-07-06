#include <iostream>
#include <fstream>
#include <string>
#include "json.hpp"
#include "TreeNode.h"
#include "BinaryTree.h"

using json = nlohmann::json;
using ordered_json = nlohmann::ordered_json;

using namespace std;

class JsonLect {
private:
    string line;
    string phater;
    string stringCounter = "";

public:
    BinaryTree treeBinary;

    JsonLect();
    void testing();
    void createRoot(string,string,string);

    void testingIteration(ordered_json);
    void phaterModifie(string);
};

