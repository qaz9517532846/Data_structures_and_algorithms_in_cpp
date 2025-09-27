#include <iostream>
#include <string>

using namespace std;

class Flower
{
    public:
        Flower(string name = "", int petals = 0, float price = 0);
        ~Flower();

        void SetName(string name);
        void SetPetals(int petals);
        void SetPrice(float price);

        string GetName();
        int GetPetals();
        float GetPrice();

    private:
        string name;
        int petals;
        float price;
};

Flower::Flower(string name, int petals, float price)
{
    this->name = name;
    this->petals = petals;
    this->price = price;
}

Flower::~Flower()
{

}

void Flower::SetName(string name)
{
    this->name = name;
}

void Flower::SetPetals(int petals)
{
    this->petals = petals;
}

void Flower::SetPrice(float price)
{
    this->price = price;
}

string Flower::GetName()
{
    return name;
}

int Flower::GetPetals()
{
    return petals;
}

float Flower::GetPrice()
{
    return price;
}

int main()
{
    Flower rose("Rose", 32, 2.99f);

    // Print initial values
    cout << "Name: " << rose.GetName() << endl;
    cout << "Petals: " << rose.GetPetals() << endl;
    cout << "Price: $" << rose.GetPrice() << endl;

    // Modify the flower
    rose.SetName("Tulip");
    rose.SetPetals(25);
    rose.SetPrice(1.49f);

    // Print updated values
    cout << "\nUpdated Flower:" << endl;
    cout << "Name: " << rose.GetName() << endl;
    cout << "Petals: " << rose.GetPetals() << endl;
    cout << "Price: $" << rose.GetPrice() << endl;

    return EXIT_SUCCESS;
}