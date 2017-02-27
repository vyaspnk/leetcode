//
//  clonegraph.cpp
//  articles
//
//  Created by Vyas on 2/26/17.
//  Copyright © 2017 vyas. All rights reserved.
//


#include <iostream>
#include <vector>
#include "unordered_map"
using namespace std;

struct UndirectedGraphNode {
         int label;
         vector<UndirectedGraphNode *> neighbors;
         UndirectedGraphNode(int x) : label(x) {};
     };

UndirectedGraphNode *
cloneNode(UndirectedGraphNode *node,
                        unordered_map<int, pair<UndirectedGraphNode*, vector<UndirectedGraphNode*>>> &G ) {
    if(!node)
        return nullptr;
    UndirectedGraphNode *curr = nullptr;
    if(G.find(node->label) == G.end()) { // new node
        curr = new UndirectedGraphNode(node->label);
        G.emplace(curr->label,make_pair(curr,vector<UndirectedGraphNode*>()));
        G[curr->label].first = curr;
        G[curr->label].second = node->neighbors;
        for(auto n : node->neighbors)
            cloneNode(n, G);
    }
    return curr;
}

UndirectedGraphNode *
cloneGraph(UndirectedGraphNode *node ) {
    unordered_map<int, pair<UndirectedGraphNode*, vector<UndirectedGraphNode*>>> G;
    auto root = cloneNode(node,G);
    cout << "Graph Size = " << G.size() << endl;
    for( auto e : G ){ //process each new node
        cout << e.first << " - ";
        for(auto t = e.second.second.begin(); t!=e.second.second.end();t++) { //clone each neighbor in the node
            cout << (*t)->label << " ";
            *t = G[(*t)->label].first;
        }
        cout << endl;
    }
	return root;
}

int main()
    {
    auto n1 = new UndirectedGraphNode(1);
    auto n2 = new UndirectedGraphNode(2);
    auto n3 = new UndirectedGraphNode(3);
    auto n4 = new UndirectedGraphNode(4);
    n1->neighbors.push_back(n2);
    n1->neighbors.push_back(n4);
    n2->neighbors.push_back(n1);
    n2->neighbors.push_back(n3);
    n3->neighbors.push_back(n2);
    n3->neighbors.push_back(n4);
    n4->neighbors.push_back(n1);
    n4->neighbors.push_back(n3);
    cloneGraph(n1);
    return 0;
}
