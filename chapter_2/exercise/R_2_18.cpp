#include <iostream>
#include <vector>

using namespace std;

template <typename T1, typename T2>
class Pair
{
    public:
        Pair(T1 a, T2 b);
        void print();

    private:
        T1 first;
        T2 second;
};

template <typename T1, typename T2>
Pair<T1, T2>::Pair(T1 a, T2 b) : first(a), second(b)
{

}

template <typename T1, typename T2>
void Pair<T1, T2>::print()
{
    cout << "( " << first << " , " << second << ")" << endl;
}

int main()
{
    Pair<int, std::string> p1(1, "One");
    Pair<float, long> p2(3.14f, 100000L);
    Pair<char, bool> p3('A', true);
    Pair<std::string, double> p4("Price", 99.99);
    Pair<int, int> p5(10, 20);

    std::cout << "Pair 1: "; p1.print();
    std::cout << "Pair 2: "; p2.print();
    std::cout << "Pair 3: "; p3.print();
    std::cout << "Pair 4: "; p4.print();
    std::cout << "Pair 5: "; p5.print();

    return EXIT_SUCCESS;
}