//
//  graph.cpp
//  list
//
//  Created by Vijetha Malla on 2/22/17.
//  Copyright © 2017 vy. All rights reserved.
//

#include "graph.hpp"
#include <iostream>
#include <vector>

using namespace std;
using namespace graph;
graph::GraphNode *
graph::Graph::cloneNode(vector<int> adjacentNodes, int val) {
    if(G.find(val) != G.end()) {
        cout << "Graph Node with value :"<<val<<" already present." << endl;
        return NULL;
    }
    auto newnode = new GraphNode(val);
    for( auto x : adjacentNodes ){
        auto p = G.find(x);
        if(p != G.end()) {
            p->second->edges.push_back(newnode);
            newnode->edges.push_back(p->second);
        }
        
    }
    G[val] = newnode;
    if(!this->start)
        this->start = newnode;
    
    return this->start;
}
graph::GraphNode *
graph::Graph::addNode(vector<int> adjacentNodes, int val) {
//    auto start = this->start;
    if(G.find(val) != G.end()) {
        cout << "Graph Node with value :"<<val<<" already present." << endl;
        return NULL;
    }
    auto newnode = new GraphNode(val);
    for( auto x : adjacentNodes ){
        auto p = G.find(x);
        if(p != G.end()) {
//            cout << "Graph Node with value :" << x << " not present." << endl;
//            free(newnode);
//            return nullptr;
            p->second->edges.push_back(newnode);
            newnode->edges.push_back(p->second);
        }
        
    }
    G[val] = newnode;
    if(!this->start)
        this->start = newnode;
    
    return this->start;
}
GraphNode*
graph::Graph::findNode(int val) {
    auto node = G.find(val);
    if(node == G.end()) {
        cout << val << " Not found" << endl;
        return nullptr;
    }
    return node->second;
}
struct node_comp {
    inline bool operator()(const GraphNode * g, const int &val) {
        return (g->val == val)?true:false;
    }
};
void
graph::Graph::deleteNode(int val) {
    auto node = findNode(val);
    if(!node) {
        cout << val << ": delete failed." << endl;
        return;
    }
    //auto &v = node->edges;
    //if(start == ) TODO
    for(auto x = G.begin(); x!= G.end();x++) {
        auto xx = x->second->val;
        if(xx != val) {
            auto &n = x->second->edges;
            auto it = std::find(n.begin(), n.end(),node);
            if(it!=n.end()) {
//                cout << *it << endl;
                n.erase(it);
					
            }
        }
    }

    G.erase(G.find(val));
    cout << val << " deleted." << endl;
}
void graph::Graph::displayGraph() {
    if(!start) {
        cout << "Graph is empty." << endl;
        return;
    }
    cout << "Graph: {"<< endl;
    for(auto t = G.begin(); t!=G.end(); t++)
    	displayGraph(t->second);
    cout<<"}"<<endl;
    return;
}
void graph::Graph::displayGraph(vector<int> &V) {
    cout << "Graph: {"<< endl;
    for(auto node: V) {
        displayGraph(G.find(node)->second);
    }
    cout << "}" << endl;
}
void graph::Graph::displayGraph(GraphNode *start){
    cout << "\t{ " << start->val << ", {";
    for(auto e: start->edges)
        cout << e->val<<",";
    
    cout << "} }," << endl;
    
}
vector<int>
graph::Graph::edgesToValues(vector<GraphNode*> &edges){
    vector<int> values;
    for(auto ed: edges)
        values.push_back(ed->val);
    return values;
}
void
graph::Graph::cloneGraph(Graph &GC) {
    for(auto vertices = G.begin(); vertices!=G.end(); vertices++) {
        GC.addNode(edgesToValues(vertices->second->edges), vertices->second->val);
    }
}

int main() {
    graph::Graph g;
    vector<int> e;
    if(g.addNode(e, 1))
    	e.push_back(1);
    if(g.addNode(e, 2))
        e.push_back(2);
    if(g.addNode(e, 3))
        e.push_back(3);
    if(g.addNode(e, 4))
        e.push_back(4);
    g.displayGraph(e);
//    g.deleteNode(1);
//    g.displayGraph();
    Graph GC;
    
    g.cloneGraph(GC);
    GC.displayGraph();
    return 0;
    
}
