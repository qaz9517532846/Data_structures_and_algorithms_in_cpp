#include <iostream>
#include <cctype>

using namespace std;

bool IsVowel(char ch)
{
    ch = tolower(ch);  // Make case-insensitive
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

// Recursive function to count vowels and consonants
void CountVowelsAndConsonants(const string& s, int index, int& vowelCount, int& consonantCount)
{
    if (index >= s.length())
        return;

    char ch = s[index];
    if (isalpha(ch)) {
        if (IsVowel(ch))
            ++vowelCount;
        else
            ++consonantCount;
    }

    CountVowelsAndConsonants(s, index + 1, vowelCount, consonantCount);
}

// Wrapper function to check if vowels are more than consonants
bool HasMoreVowels(const string& s)
{
    int vowels = 0, consonants = 0;
    CountVowelsAndConsonants(s, 0, vowels, consonants);
    return vowels > consonants;
}

int main()
{
    string input = "My name is zmtech.";

    if (HasMoreVowels(input))
        cout << "The string has more vowels than consonants.\n";
    else
        cout << "The string does not have more vowels than consonants.\n";

    return 0;

    return EXIT_SUCCESS;
}