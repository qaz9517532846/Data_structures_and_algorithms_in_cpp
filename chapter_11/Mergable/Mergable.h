#include <iostream>
#include <vector>
#include <list>

template <typename E>
class Merge {
    public:
        typedef std::list<E> List;
        void merge(List& A, List &B, List&C);
    protected:
        typedef typename List::iterator Itor;

        virtual void fromA(const E& a, List& C) = 0;
        virtual void fromBoth(const E& a, const E& b, List& C) = 0;
        virtual void fromB(const E& b, List& C) = 0;
};

template <typename E>
class UnionMerge : public Merge<E> {
    protected:
        typedef typename Merge<E>::List List;
        void fromA(const E& a, List& C)
        { C.push_back(a); }
        void fromBoth(const E& a, const E& b, List& C)
        { C.push_back(a); }
        void fromB(const E& b, List& C)
        { C.push_back(b); }
};

template <typename E>
class IntersectionMerge : public Merge<E> {
    protected:
        typedef typename Merge<E>::List List;
        void fromA(const E& a, List& C)
        { }
        void fromBoth(const E& a, const E& b, List& C)
        { C.push_back(a); }
        void fromB(const E& b, List& C)
        { }
};

template <typename E>
class SubtractionMerge : public Merge<E> {
    protected:
        typedef typename Merge<E>::List List;
        void fromA(const E& a, List& C)
        { C.push_back(a); }
        void fromBoth(const E& a, const E& b, List& C)
        { }
        void fromB(const E& b, List& C)
        { }
};