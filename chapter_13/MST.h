#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <queue>
#include <set>
#include <limits>
#include <algorithm>
#include "UnionFind.h"

// ============================================================
// MST Algorithms
// ============================================================

template<typename V, typename E>
class MST {
public:
    struct Edge {
        V source, dest;
        E weight;
        Edge(V s, V d, E w) : source(s), dest(d), weight(w) {}
        bool operator<(const Edge& other) const {
            return weight < other.weight;
        }
    };
    
    // Kruskal's algorithm
    static std::vector<Edge> kruskal(Graph<V, E>& graph) {
        std::vector<Edge> result;
        std::vector<Edge> edges;
        
        // Get all edges
        typename Graph<V, E>::EdgeList edgeList = graph.edges();
        for (const auto& e : edgeList) {
            edges.push_back(Edge(*e.getSource(), *e.getDest(), e.getWeight()));
        }
        
        std::sort(edges.begin(), edges.end());
        
        UnionFind<V> uf;
        typename Graph<V, E>::VertexList vertices = graph.vertices();
        
        for (const auto& v : vertices) {
            uf.makeSet(*v);
        }
        
        for (const Edge& edge : edges) {
            if (!uf.connected(edge.source, edge.dest)) {
                uf.unite(edge.source, edge.dest);
                result.push_back(edge);
                
                if (result.size() == (size_t)(graph.vertexCount() - 1)) {
                    break;
                }
            }
        }
        
        return result;
    }
    
    // Print MST
    static void printMST(const std::vector<Edge>& mst) {
        std::cout << "\nMinimum Spanning Tree:" << std::endl;
        E total = E();
        for (const Edge& edge : mst) {
            std::cout << edge.source << " -- " << edge.dest 
                     << " (weight: " << edge.weight << ")" << std::endl;
            total += edge.weight;
        }
        std::cout << "Total weight: " << total << std::endl;
    }
};