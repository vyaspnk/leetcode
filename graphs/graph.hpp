//
//  graph.hpp
//  list
//
//  Created by Vijetha Malla on 2/22/17.
//  Copyright © 2017 vy. All rights reserved.
//

#ifndef graph_hpp
#define graph_hpp

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;
namespace graph {
    struct GraphNode {
        int val;
        vector<GraphNode*> edges;
        GraphNode(int x): val(x) {}
    };
    class Graph{
    private:
        GraphNode *start;
        unordered_map<int,GraphNode*> G;
        vector<int> edgesToValues(vector<GraphNode*> &edges);
    public:
        Graph(){}
        Graph(Graph& GC) {
            cloneGraph(GC);
        }
        GraphNode * addNode(GraphNode*,int val);
        GraphNode * addNode(vector<int> adjacentNodes, int val);
        GraphNode * cloneNode(vector<int> adjacentNodes, int val);
        void deleteNode(int);
        GraphNode * findNode(int);
        void cloneGraph(Graph &);
        void displayGraph(GraphNode*);
        void displayGraph(vector<int>&);
        void displayGraph();
    };
}

#endif /* graph_hpp */
