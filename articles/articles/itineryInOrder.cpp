//
//  itineryInOrder.cpp
//  articles
//
//  Created by Vijetha Malla on 2/26/17.
//  Copyright © 2017 vyas. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;


vector<string> findItinerary(vector<pair<string, string>> tickets) {
    vector<string> R;
    unordered_map<string, queue<pair<string, string>>> stops;
    for(auto t:tickets)
        stops[t.first].push(t);
	string start = "JFK";
    R.push_back(start);
    while(stops.size()) {
        if(stops.find(start) == stops.end()) {
            R.push_back(start);
            break;
        }
//        else {
        	auto tmp = stops[start].front().second;
//        }
        stops[start].pop();
        if(stops[start].size()==0){
            stops.erase(stops.find(start));
        }
        R.push_back(tmp);
        start = tmp;
    }
    return R;
}

int main() {
    vector<pair<string,string>> V;
//    tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]

    V.push_back(make_pair("JFK", "AAA"));
    V.push_back(make_pair("AAA", "JFK"));
    V.push_back(make_pair("JFK", "BBB"));
    V.push_back(make_pair("JFK", "CCC"));
	V.push_back(make_pair("CCC", "JFK"));
    
    auto R = findItinerary(V);
    cout << "[ ";
    for(auto r:R){
        cout << "\"" << r << "\" ";
    }
    cout << "]" << endl;
    return 0;
}
