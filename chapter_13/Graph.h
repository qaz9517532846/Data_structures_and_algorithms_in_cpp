#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <queue>
#include <set>
#include <limits>
#include <algorithm>
#include "Decorator.h"

// ============================================================
// Graph Implementation - Adjacency List Representation
// ============================================================

template<typename V, typename E>
class Graph {
public:
    // Vertex and Edge classes
    class Vertex : public Decorator {
    private:
        V data;
    public:
        Vertex(const V& d = V()) : data(d) {}
        V& operator*() { return data; }
        const V& operator*() const { return data; }
        bool operator==(const Vertex& v) const { return data == v.data; }
        bool operator<(const Vertex& v) const { return data < v.data; }
    };
    
    class Edge : public Decorator {
    private:
        Vertex source;
        Vertex dest;
        E weight;
    public:
        Edge(const Vertex& s, const Vertex& d, const E& w) 
            : source(s), dest(d), weight(w) {}
        
        Vertex getSource() const { return source; }
        Vertex getDest() const { return dest; }
        E getWeight() const { return weight; }
        
        Vertex opposite(const Vertex& v) const {
            if (v == source) return dest;
            return source;
        }
        
        bool isIncidentOn(const Vertex& v) const {
            return v == source || v == dest;
        }
        
        bool operator<(const Edge& other) const {
            return weight < other.weight;
        }
    };
    
    typedef std::list<Vertex> VertexList;
    typedef std::list<Edge> EdgeList;
    typedef typename VertexList::iterator VertexItor;
    typedef typename EdgeList::iterator EdgeItor;

private:
    std::map<V, std::list<std::pair<V, E>>> adjList;
    bool directed;
    int numVertices;
    int numEdges;

public:
    Graph(bool isDirected = false) 
        : directed(isDirected), numVertices(0), numEdges(0) {}
    
    // Add vertex
    void addVertex(const V& vertex) {
        if (adjList.find(vertex) == adjList.end()) {
            adjList[vertex] = std::list<std::pair<V, E>>();
            numVertices++;
        }
    }
    
    // Add edge
    void addEdge(const V& source, const V& dest, E weight = E()) {
        addVertex(source);
        addVertex(dest);
        
        adjList[source].push_back(std::make_pair(dest, weight));
        if (!directed) {
            adjList[dest].push_back(std::make_pair(source, weight));
        }
        numEdges++;
    }
    
    // Get all vertices
    VertexList vertices() const {
        VertexList verts;
        for (const auto& pair : adjList) {
            verts.push_back(Vertex(pair.first));
        }
        return verts;
    }
    
    // Get all edges
    EdgeList edges() const {
        EdgeList edgesList;
        std::set<std::pair<V, V>> addedEdges;
        
        for (const auto& vertexPair : adjList) {
            V source = vertexPair.first;
            for (const auto& neighbor : vertexPair.second) {
                V dest = neighbor.first;
                E weight = neighbor.second;
                
                if (directed || addedEdges.find(std::make_pair(dest, source)) == addedEdges.end()) {
                    edgesList.push_back(Edge(Vertex(source), Vertex(dest), weight));
                    addedEdges.insert(std::make_pair(source, dest));
                }
            }
        }
        return edgesList;
    }
    
    // Get incident edges for a vertex
    EdgeList incidentEdges(const Vertex& v) const {
        EdgeList edges;
        V vertex = *v;
        
        if (adjList.find(vertex) != adjList.end()) {
            for (const auto& neighbor : adjList.at(vertex)) {
                edges.push_back(Edge(v, Vertex(neighbor.first), neighbor.second));
            }
        }
        return edges;
    }
    
    // BFS traversal
    void BFS(const V& start) const {
        std::set<V> visited;
        std::queue<V> q;
        
        visited.insert(start);
        q.push(start);
        
        std::cout << "BFS: ";
        while (!q.empty()) {
            V vertex = q.front();
            q.pop();
            std::cout << vertex << " ";
            
            if (adjList.find(vertex) != adjList.end()) {
                for (const auto& neighbor : adjList.at(vertex)) {
                    if (visited.find(neighbor.first) == visited.end()) {
                        visited.insert(neighbor.first);
                        q.push(neighbor.first);
                    }
                }
            }
        }
        std::cout << std::endl;
    }
    
    // Dijkstra's shortest path
    std::map<V, E> dijkstra(const V& start) const {
        std::map<V, E> distance;
        std::priority_queue<std::pair<E, V>, std::vector<std::pair<E, V>>, 
                           std::greater<std::pair<E, V>>> pq;
        
        for (const auto& vertexPair : adjList) {
            distance[vertexPair.first] = std::numeric_limits<E>::max();
        }
        distance[start] = 0;
        pq.push(std::make_pair(0, start));
        
        while (!pq.empty()) {
            V u = pq.top().second;
            E dist = pq.top().first;
            pq.pop();
            
            if (dist > distance[u]) continue;
            
            if (adjList.find(u) != adjList.end()) {
                for (const auto& neighbor : adjList.at(u)) {
                    V v = neighbor.first;
                    E weight = neighbor.second;
                    E newDist = distance[u] + weight;
                    
                    if (newDist < distance[v]) {
                        distance[v] = newDist;
                        pq.push(std::make_pair(newDist, v));
                    }
                }
            }
        }
        
        return distance;
    }
    
    // Topological sort
    std::vector<V> topologicalSort() const {
        std::map<V, int> inDegree;
        std::vector<V> result;
        std::queue<V> q;
        
        for (const auto& vertexPair : adjList) {
            if (inDegree.find(vertexPair.first) == inDegree.end()) {
                inDegree[vertexPair.first] = 0;
            }
            for (const auto& neighbor : vertexPair.second) {
                inDegree[neighbor.first]++;
            }
        }
        
        for (const auto& pair : inDegree) {
            if (pair.second == 0) {
                q.push(pair.first);
            }
        }
        
        while (!q.empty()) {
            V u = q.front();
            q.pop();
            result.push_back(u);
            
            if (adjList.find(u) != adjList.end()) {
                for (const auto& neighbor : adjList.at(u)) {
                    inDegree[neighbor.first]--;
                    if (inDegree[neighbor.first] == 0) {
                        q.push(neighbor.first);
                    }
                }
            }
        }
        
        if (result.size() != (size_t)numVertices) {
            result.clear();
        }
        
        return result;
    }
    
    // Print graph
    void print() const {
        std::cout << "Graph structure:" << std::endl;
        for (const auto& vertexPair : adjList) {
            std::cout << vertexPair.first << " -> ";
            for (const auto& neighbor : vertexPair.second) {
                std::cout << "(" << neighbor.first << "," << neighbor.second << ") ";
            }
            std::cout << std::endl;
        }
    }
    
    int vertexCount() const { return numVertices; }
    int edgeCount() const { return numEdges; }
};