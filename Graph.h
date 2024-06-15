#pragma once
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class Graph {
private:
    unordered_map<string, unordered_set<string> > adjList;

public:
    void printGraph() {
        unordered_map<string, unordered_set<string>>::iterator kvPair = adjList.begin();
        while (kvPair != adjList.end()) {
            cout << kvPair->first << ": [";
            unordered_set<string>::iterator edge = kvPair->second.begin();
            bool first = true;
            while (edge != kvPair->second.end()) {
                if (!first) {
                    cout << ", ";
                }
                cout << *edge;
                edge++;
                first = false;
            }
            cout << "]" << endl;
            kvPair++;
        }
    }

    bool addVertex(string vertex) {
        if (adjList.count(vertex) == 0) {
            adjList[vertex];
            return true;
        }
        return false;
    }

    //   +=====================================================+
    //   |                WRITE YOUR CODE HERE                 |
    //   | Description:                                        |
    //   | - This method adds an edge between vertex1 and      |
    //   |   vertex2 in the graph.                             |
    //   | - Checks if both vertices exist in the graph.       |
    //   |                                                     |
    //   | Return type: bool                                   |
    //   | - Returns true if edge is successfully added.       |
    //   | - Returns false if either vertex does not exist.    |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - Uses 'adjList' to hold the graph's adjacency list.|
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+

    bool addEdge(string vertexFrom, string vertexTo)
    {
        if (adjList.count(vertexFrom) == 0 || adjList.count(vertexTo) == 0)
        {
            return false;
        }
        if (adjList[vertexFrom].count(vertexTo) == 0)
        {
            auto result = adjList[vertexFrom].insert(vertexTo);
            if (result.second != true)
            {
                return false;
            }
        }

        if (adjList[vertexTo].count(vertexFrom) == 0)
        {
            auto result = adjList[vertexTo].insert(vertexFrom);
            if (result.second != true)
            {
                return false;
            }
        }
        return true;
    }
    
};
    

