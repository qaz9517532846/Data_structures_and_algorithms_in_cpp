#include "../DFS.h"

template<typename G>
DFS<G>::DFS(const G& g): graph(g), yes(new Object()), no(new Object())
{
}

template<typename G>
void DFS<G>::initialize()
{
    //initialize all vertices and edges as unvisited
    VertexList verts = graph.vertices();
    for (VertexItor pv = verts.begin(); pv != verts.end(); ++pv)
        unvisit(*pv); //mark vertices unvisited
    EdgeList edges = graph.edges();
    for (EdgeItor pe = edges.begin(); pe != edges.end(); ++pe)
        unvisit(*pe); //mark edges unvisited
}

template<typename G>
void DFS<G>::dfsTraversal(const Vertex& v)
{
    this->startVisit(v); this->visit(v); //visit v and mark visited
    EdgeList incident = this->graph.incidentEdges(v);
    EdgeItor pe= incident.begin();
    while(!this->isDone() && pe !=incident.end()) { //visit v's incident edges
        Edge e = *pe++;
        if (!this->isVisited(e)) { //discovery edge?
            this->visit(e); //mark it visited
            Vertex w = e.opposite(v); //get opposing vertex
            if (!this->isVisited(w)) { //unexplored?
                this->traverseDiscovery(e, v); // let's discover it
                if (!this->isDone()) this->dfsTraversal(w); //continue traversal
            }
            else this->traverseBack(e, v); //process back edge
        }
    }
    if (!this->isDone()) this->finishVisit(v);
}