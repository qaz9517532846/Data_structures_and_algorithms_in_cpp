#include "../FindCycle.h"

/*FindCycleG ::*/ //find a cycle
template<typename G>
typename FindCycle<G>::EdgeList FindCycle<G>::operator()(const Vertex& s) {
    this->initialize(); // initialize DFS
    cycle = EdgeList(); done = false; // initialize members
    this->initialize(); // initialize DFS
    cycle = EdgeList(); done = false; // initialize members
    dfsTraversal(s); // do the search
    if (!cycle.empty() && s != cycleStart) { // found a cycle?
        EdgeItor pe = cycle.begin();
        while(pe != cycle.end()) { // search for prefix
            if ((pe++)->isIncidentOn(cycleStart)) break; // last edge of prefix?
        }

        cycle.erase(cycle.begin(), pe); // remove prefix
    }

    return cycle; // return the cycle
}

template<typename G>
void FindCycle<G>::traverseDiscovery(const Edge& e, const Vertex& from) { 
    if (!done) cycle.push_back(e);
} //add edge to list

template<typename G>
void FindCycle<G>::traverseBack(const Edge& e, const Vertex& from) {
    if (!done) { //no cycle yet?
        done = true; //cycle now detected
        cycle.push_back(e); // insert final edge
        cycleStart = e.opposite(from); //save starting vertex
    }
}

/*FindCycleG ::*/ //finishedwithvertex
template<typename G>
void FindCycle<G>::finishVisit(const Vertex& v) {
    if (!cycle.empty() && !done) //not building a cycle?
        cycle.pop_back(); //remove this edge
}

/*FindCycleG ::*/ //doneyet?
template<typename G>
bool FindCycle<G>::isDone() const {
    return done;
}
