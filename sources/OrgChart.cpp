#include "OrgChart.hpp"
// need to add generic code? For what?


namespace ariel{
    
    OrgChart::OrgChart(){
        this->counter = 0;
    }
    OrgChart::~OrgChart(){
        std::cout << "de-structor";
    }


    // appending on BFS...or not? what happen in case if we won't find?
    node* OrgChart::findNode(node* wantedNode, string name, int count){
        if (count == this->counter){ // stop condition
            return nullptr;
        }
        if (wantedNode->data == name){ // stop condition
            return wantedNode;
        }
        if (wantedNode->subs.size() > 0){
            node temp = wantedNode->subs.back();
            wantedNode->subs.pop_back(); // delete
            ++count;
            return findNode(&temp, name, count); // wanna go through all nodes in tree
        }
        return nullptr;
    }
    node* OrgChart::findNode2(node* wantedNode, string name, int count){
        if (this->root.data == name){
            return &(this->root);
        }

        for (std::size_t i = 0; i < this->root.subs.size(); ++i){
            if (this->root.subs.at(i).data == name){
                return &(this->root.subs.at(i));
            }
        }
        return nullptr;

    }
    // Also need to add to queue and stack (What happens if we want to change the root? Need to clear all queue...)
    OrgChart &OrgChart::add_root(string boss){
        //strcpy(this->root.data, boss);
        ++this->counter;
        this->root.data = boss;
        return *this;

    }
    // MAIN ADD FUNC
    OrgChart &OrgChart::add_sub(string boss, string employ){
        

    // find node with: data == boss (BFS) and add employ to sons(vector) of the boss
        node* wantedNode = &(this->root);
        wantedNode = findNode2(wantedNode, boss, 0);
        // check if boss was not found 
        if (wantedNode == nullptr){
            throw std::runtime_error("can't find the boss!");
        }
        // create new employ node 
        node newNode;
        newNode.data = employ;
        newNode.boss = wantedNode;
        // add (employ) to subs of the boss
        wantedNode->subs.push_back(newNode);


    // add to queue
        this->levelorder.push(newNode);

    // add to stack
        this->reverseorder.push(newNode);
    // add another way for preorder


        ++this->counter; // count nodes

        return *this;
    }

    // LEVEL ORDER
    vector<string>::iterator OrgChart::begin_level_order(){
        vector<string>::iterator it;
        return it;
        //return this->levelorder.back().data;
    }
    vector<string>::iterator OrgChart::end_level_order(){
        vector<string>::iterator it;
        return it;
        //return this->reverseorder.top().data;
    }

    // REVEERSE ORDER
    vector<string>::iterator OrgChart::begin_reverse_order(){
        vector<string>::iterator it;
        return it;
        //return this->reverseorder.top().data;
    }
    vector<string>::iterator OrgChart::reverse_order(){
        vector<string>::iterator it;
        return it;
        //return this->levelorder.back().data;
    }

    // PRE-ORDER
    vector<string>::iterator OrgChart::begin_preorder(){
        vector<string>::iterator it;
        return it;
    }
    vector<string>::iterator OrgChart::end_preorder(){
        vector<string>::iterator it;
        return it;
    }

    // SHOULD WORK LIKE LEVEL-ORDER
    vector<string>::iterator OrgChart::begin(){
        return begin_level_order();
    }
    vector<string>::iterator OrgChart::end(){
        return end_level_order();
    }


    std::ostream & operator << (std::ostream &out, const OrgChart &organization){
        return out;
    }
}

