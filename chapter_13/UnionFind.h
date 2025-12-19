#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <queue>
#include <set>
#include <limits>
#include <algorithm>

// ============================================================
// Union-Find for Kruskal's Algorithm
// ============================================================

template<typename V>
class UnionFind {
private:
    std::map<V, V> parent;
    std::map<V, int> rank;
    
public:
    void makeSet(const V& vertex) {
        parent[vertex] = vertex;
        rank[vertex] = 0;
    }
    
    V find(const V& vertex) {
        if (parent[vertex] != vertex) {
            parent[vertex] = find(parent[vertex]);
        }
        return parent[vertex];
    }
    
    void unite(const V& x, const V& y) {
        V rootX = find(x);
        V rootY = find(y);
        
        if (rootX == rootY) return;
        
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
    
    bool connected(const V& x, const V& y) {
        return find(x) == find(y);
    }
};
