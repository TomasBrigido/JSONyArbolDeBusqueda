#include "JsonLect.h"

JsonLect::JsonLect() {
}

void JsonLect::testing() {
    ifstream i("C:\\Users\\Tomas\\Documents\\facultad\\ayed\\untitled4\\laureate.json");

    ordered_json test;
    ordered_json j;
    i >> j;

    ordered_json::iterator it;
    bool flag = true;

    for (auto el = j.begin(); el != j.end(); el++)
    {
        if(flag){
            string key = el.key();
            createRoot(key, key, "$");
            phaterModifie(key);
            flag = false;
        }

        if(el.value().type() == json::value_t::array == true) {
            it = el;
            for(auto &el : it->items()){

                //Parte que acomoda al padre con la key
                ordered_json kyoto;
                kyoto = el.value();
                for(auto &ela : kyoto.items()){
                    string phather = kyoto.begin().value();
                    phaterModifie(phather);
                }
                testingIteration(el.value());
            }
        } else {
            cout <<" is array: " << (el.value().type()==json::value_t::array ? "true" : "false") << endl;
        }
    }
}

void JsonLect::testingIteration(ordered_json j) {
    ordered_json::iterator it;
    ordered_json test;
    ordered_json kyoto;

    for (auto& el : j.items())
    {
        if(el.value().type() == json::value_t::array == true) {
            if(el.value().size() != 1){
                string key_array = el.key();
                treeBinary.insert(treeBinary.root->left,phater,key_array,"$");
                kyoto = el.value();

                for(auto &ela : kyoto.items()){
                    testingIteration(ela.value());
                }
            }else{
                string key_array = el.key();
                treeBinary.insert(treeBinary.root->left,phater,key_array,"$");
                it = el.value().begin();
                test = *it;
                testingIteration(test);
            }
        }else{
            string key_array = el.key();
            string value_array = el.value();
            if(stringCounter != "$"){
                treeBinary.insert(treeBinary.root->left,phater,key_array,value_array);
            }else{
                treeBinary.insert(treeBinary.root->left,phater,key_array,"$");
                stringCounter = "";
            }
        }
    }
}

void JsonLect::createRoot(string parent, string root, string $) {
    TreeNode* rootCreation = new TreeNode(parent,root,$);
    treeBinary.setRoot(rootCreation);
}

void JsonLect::phaterModifie(string phater) {
    this->phater = phater;
}