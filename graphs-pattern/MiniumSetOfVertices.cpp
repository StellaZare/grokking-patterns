#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<int> findSmallestSetOfVertices(int n, std::vector<std::vector<int>>& edges) {
        std::vector<int> result;

        std::unordered_map<int, bool> has_incoming_edge;
        for(auto& edge : edges){
            has_incoming_edge[edge.at(1)] = true;
        }

        for(int vert = 0; vert < n; vert++){
            if (has_incoming_edge.find(vert) == has_incoming_edge.end()){
                result.push_back(vert);
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    
    // Test cases
    std::vector<std::vector<int>> edges1 = {{0,1}, {0,2}, {2,5}, {3,4}, {4,2}};
    for (int vertex : solution.findSmallestSetOfVertices(6, edges1)) {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;  // Expected: 0 3

    std::vector<std::vector<int>> edges2 = {{0,1}, {3,1}, {1,2}};
    for (int vertex : solution.findSmallestSetOfVertices(4, edges2)) {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;  // Expected: 0 3
    
    std::vector<std::vector<int>> edges3 = {{2,0}, {3,2}};
    for (int vertex : solution.findSmallestSetOfVertices(4, edges3)) {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;  // Expected: 1 3
}