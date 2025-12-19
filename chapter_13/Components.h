template<typename G>
class Components : public DFS<G> { //count components
    private:
        int nComponents; //num of components
    public:
        Components(const G& g) : DFS<G>(g) {} //constructor
        int operator()(); //count components
};

template<typename G>
int Components<G>::operator()()
{
    this->initialize(); //initialize DFS
    nComponents = 0; //no components found yet
    typename DFS<G>::VertexList verts = this->graph.vertices();
    for (typename DFS<G>::VertexItor pv = verts.begin(); pv != verts.end(); ++pv) {
        if (!this->isVisited(*pv)) { //new component found
            this->dfsTraversal(*pv); //traverse component
            nComponents++; //increment count
        }
    }
    return nComponents; //return total count
}