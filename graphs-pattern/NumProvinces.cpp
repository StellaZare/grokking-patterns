#include <vector>
#include <iostream>

class UnionFind {
    public:
    UnionFind(int n){
        parent.resize(n);
        rank.resize(n, 1);
        for(int idx = 0; idx < parent.size(); idx++){
            parent.at(idx) = idx;
        }
        numComponents = n;
    }

    int getParent(int n){
        return parent.at(n);
    }

    int getRank(int n){
        return rank.at(n);
    }

    /**
     * merge n and m
     * if same parent do nothing
     * otherwise set parent of m as the parent of n
     */
    void merge(int n, int m){
        if (parent.at(n) != parent.at(m)){
            parent.at(m) = parent.at(n);
            rank.at(parent.at(n))++;
            numComponents--;

            std::cout << n << " " << m << ": ";

            for(int& p : parent){
                std::cout << p << " ";
            }
            std::cout << std::endl;
        }
    }

    int getNumComp(){
        return numComponents;
    }

    private:
    std::vector<int> parent;
    std::vector<int> rank;
    int numComponents;
};

class Solution {
public:
    /**
     * Problem 2: Number of Provinces (medium)
     * 
     * There are n cities. 
     * Some of them are connected in a network. 
     * If City A is directly connected to City B, and City B is directly connected to City C, 
     * city A is directly connected to City C.
     * 
     * If a group of cities are connected directly or indirectly, they form a province.
     * Given an n x n matrix isConnected where isConnected[i][j] = 1   
     * if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 
     * otherwise, determine the total number of provinces.
     */
    int findProvinces(std::vector<std::vector<int>>& isConnected) {
        // ToDo: Write Your Code Here.
        int numVert = isConnected.size();
        UnionFind uf {numVert};

        for(int v1 = 0; v1 < numVert; v1++){
            for(int v2 = 0; v2 < v1; v2++){
                if (isConnected.at(v1).at(v2) == 1) uf.merge(v2, v1);
            }
        }
        return uf.getNumComp();
    }
};

int main() {
    Solution solution;

    // Example 1
    std::vector<std::vector<int>> example1 = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    printf("%d\n", solution.findProvinces(example1)); // Expected Output: 2

    // // Example 2
    // std::vector<std::vector<int>> example2 = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    // printf("%d\n", solution.findProvinces(example2)); // Expected Output: 3

    // // Example 3
    // std::vector<std::vector<int>> example3 = {{1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 0}, {1, 0, 0, 1}};
    // printf("%d\n", solution.findProvinces(example3)); // Expected Output: 2

    return 0;
}