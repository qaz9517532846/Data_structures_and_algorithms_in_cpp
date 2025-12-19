#include "../FindPath.h"

template<typename G>
typename FindPath<G>::VertexList FindPath<G>::operator()(const Vertex& s, const Vertex& t)
{
    this->initialize(); // initialize DFS
    path.clear(); // clear the path
    target = t; // save the target
    done = false;
    this->dfsTraversal(s); // traverse starting at s
    return path; // return the path
}

template<typename G>
void FindPath<G>::startVisit(const Vertex& v){
    path.push_back(v); // insert into path
    if (v == target) done = true; // reached target vertex
}

template<typename G>
void FindPath<G>::finishVisit(const Vertex& v){
    if (!done) path.pop_back();
} // remove last vertex

template<typename G>
bool FindPath<G>::isDone() const{ 
    return done; 
}