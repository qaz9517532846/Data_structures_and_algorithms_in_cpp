#include <iostream>
#include <vector>
#include <stdexcept>

int main()
{
    std::vector<int> numbers = {10, 20, 30, 40, 50};

    int index;
    std::cout << "Enter an index: ";
    std::cin >> index;

    try
    {
        int value = numbers.at(index);  // Safe access with bounds checking
        std::cout << "Value at index " << index << " is " << value << std::endl;
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << "Error: Index " << index << " is out of bounds." << std::endl;
    }

    return EXIT_SUCCESS;
}