#include <iostream>
#include <vector>

using namespace std;

class Object
{
    public:
        virtual void printMe() = 0;
};

class Place : public Object
{
    public:
        virtual void printMe() { cout << "Buy it.\n"; };
};

class Region : public Place
{
    public:
        virtual void printMe() { cout << "Box it.\n"; };
};

class State : public Region
{
    public:
        virtual void printMe() { cout << "Ship it.\n"; };
};

class Marylnd : public State
{
    public:
        virtual void printMe() { cout << "Read it.\n"; };
};

int main()
{
    Region* mid = new State;
    State* md = new Marylnd;
    Object* obj = new Place;
    Place* usa = new Region;

    md->printMe();
    mid->printMe();

    (dynamic_cast<Place*>(obj))->printMe();
    obj = md;
    
    (dynamic_cast<Marylnd*>(obj))->printMe();
    obj = usa;
    (dynamic_cast<Place*>(obj))->printMe();
    usa = md;
    (dynamic_cast<Place*>(obj))->printMe();

    return EXIT_SUCCESS;
}