#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using std::string;
using std::vector;
using std::queue;
using std::stack;

namespace ariel{

    struct node{
        string data;
        vector<node> subs; // vector of sub workers
        node* boss; // pointer to boss
    };

    class OrgChart{
        private:
            node root;
            queue <node> levelorder;
            stack <node> reverseorder;

            int counter;

        public:
            // constructor
            OrgChart();
            // de-structor
            ~OrgChart();
            OrgChart &add_root(string boss); //& - for:  organization.add_root("CEO").add_sub("CEO", "CTO")      
            OrgChart &add_sub(string boss, string employ);

            // OrgChart& operator++(); // ++n
            // OrgChart operator++(int); // n++

            //input, output operators
            friend std::ostream & operator << (std::ostream &out, const OrgChart &organization); //friend func to access private & protected members
            
            vector<string>::iterator begin_level_order();
            vector<string>::iterator end_level_order();

            vector<string>::iterator begin_reverse_order();
            vector<string>::iterator reverse_order();

            vector<string>::iterator begin_preorder();
            vector<string>::iterator end_preorder();
            
            // default iterators
            vector<string>::iterator begin();
            vector<string>::iterator end();



            // help funcs
            node* findNode(node* wantedNode, string name, int count);
            node* findNode2(node* wantedNode, string name, int count);



    };
}