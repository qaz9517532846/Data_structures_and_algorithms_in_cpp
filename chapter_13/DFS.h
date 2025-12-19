template<typename G>
class DFS { //genericDFS
    protected: // local types
        typedef typename G::Vertex Vertex; //vertex position
        typedef typename G::Edge Edge; //edge position
        typedef typename G::VertexList VertexList;
        typedef typename G::EdgeList EdgeList;
        typedef typename G::VertexItor VertexItor;
        typedef typename G::EdgeItor EdgeItor;
        // ...insert other typename shortcuts here
    protected: //member data
        const G& graph; //the graph
        Vertex start; //start vertex
        Object* yes, *no; //decorator values
    protected: //member functions
        DFS(const G& g); //constructor
        void initialize(); // initialize an new DFS
        void dfsTraversal(const Vertex& v); //recursive DFS utility
        //overridden functions
        virtual void startVisit(const Vertex& v){} //arrived at v
        //discovery edge e
        virtual void traverseDiscovery(const Edge& e, const Vertex& from){}
        //back edge e
        virtual void traverseBack(const Edge& e, const Vertex& from){}
        virtual void finishVisit(const Vertex& v){} //finished with v
        virtual bool isDone() const { return false; } //finished?
        // ...insert marking utilities here
        void visit(const Vertex& v) { v.set("visited", yes); }
        void visit(const Edge& e) { e.set("visited", yes); }
        void unvisit(const Vertex& v) { v.set("visited", no); }
        void unvisit(const Edge& e) { e.set("visited", no); }
        bool isVisited(const Vertex& v) { return v.get("visited") == yes; }
        bool isVisited(const Edge& e) { return e.get("visited") == yes; }
};