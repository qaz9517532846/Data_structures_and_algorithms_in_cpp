template<typename G>
class FindPath : public DFS<G> { //find a path by DFS
    private: // local data
        typedef typename DFS<G>::Vertex Vertex;
        typedef typename DFS<G>::VertexList VertexList;
        VertexList path; //the path
        Vertex target; //the target vertex
        bool done; // is target found?
    protected: //overridden functions
        void startVisit(const Vertex& v); //visit vertex
        void finishVisit(const Vertex& v); //finished with vertex
        bool isDone() const; //done yet?
    public:
        FindPath(const G& g) : DFS<G>(g) {} //constructor
        //find path from s to t
        VertexList operator()(const Vertex& s, const Vertex& t);
};