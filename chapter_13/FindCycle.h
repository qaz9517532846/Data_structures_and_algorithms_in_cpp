template<typename G>
class FindCycle : public DFS<G> { //find a cycle
    private: // local data
        typedef typename DFS<G>::Vertex Vertex;
        typedef typename DFS<G>::Edge Edge;
        typedef typename DFS<G>::EdgeList EdgeList;
        typedef typename DFS<G>::EdgeItor EdgeItor;
        EdgeList cycle; //cycle storage
        Vertex cycleStart; //start of cycle
        bool done; //cycle detected?
    protected: //overridden functions
        void traverseDiscovery(const Edge& e, const Vertex& from);
        void traverseBack(const Edge& e, const Vertex& from);
        void finishVisit(const Vertex& v); //finished with vertex
        bool isDone() const; //done  yet?
    public:
        FindCycle(const G& g) : DFS<G>(g) {} //constructor
        EdgeList operator()(const Vertex& s); //find a cycle
};