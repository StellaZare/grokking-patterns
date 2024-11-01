#include <vector>
#include <stack>
#include <iostream>

class Solution {
    public:
    /**
     * Find if Path Exists in Graph(easy)
     * 
     * Given an undirected graph, represented as a list of edges. 
     * Each edge is illustrated as a pair of integers [u, v], 
     * signifying that there's a mutual connection between node u and node v.
     * 
     * You are also given starting node start, and a destination node end, 
     * return true if a path exists between the starting node and the destination node. 
     * Otherwise, return false.
     * 
     * Thinking:
     *      use an array of size n to track which vertices you have seen already
     *      use a stack to traverse the graph
     * 
     *      add the start node to the stack and mark as seen
     *      while stack is not empty:
     *          v = pop from stack
     *          for edge (x, y) in edges:
     *              if v == x and y not seen: add y to stack and mark seen
     *              else if v == y and x not seen: add x to stack and mark seen
     *          
     *          if end is seen: return true (a path found from start to end)
     * 
     *      after while loop return false
     */
    bool validPath(int n, std::vector<std::vector<int>>& edges, int start, int end) {
        
        std::vector<bool> seenVert {};
        seenVert.resize(n);

        std::vector<int> processing {};
        processing.push_back(start);

        while(!processing.empty()){
            int v = processing.back();
            processing.pop_back();

            for (auto& edge : edges){
                int x = edge.at(0);
                int y = edge.at(1);
                if (v == x && !seenVert.at(y)){
                    seenVert.at(y) = true;
                    processing.push_back(y);
                } else if (v == y && !seenVert.at(x)){
                    seenVert.at(x) = true;
                    processing.push_back(x);
                }

                if (seenVert.at(end)) return true;
            }
            
        }

        return false;
    }
};