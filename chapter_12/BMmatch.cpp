#include <iostream>
#include <vector>
#include <string>

std::vector<int> buildLastFunction(const std::string& pattern) {
    const int N_ASCII = 128; // Assuming extended ASCII
    int i;

    std::vector<int> last(N_ASCII);
    for (i = 0; i < N_ASCII; i++) {
        last[i] = -1;
    }
    for (i = 0; i < pattern.size(); i++) {
        last[pattern[i]] = i;
    }
    return last;
}

int BMmatch(const std::string& text, const std::string& pattern) {
    std::vector<int> last = buildLastFunction(pattern);
    int n = text.size();
    int m = pattern.size();
    int i = m - 1; // index for text
    if(i > n - 1)
        return -1; // Pattern longer than text
    int j = m - 1; // index for pattern
    do{
        if (pattern[j] == text[i])
            if (j == 0) return i; // Match found
            else {
                i--; j--;
            }
        else {
            i = i + m - std::min(j, 1 + last[text[i]]);
            j = m - 1;
        }
    }while(i < n) ;
    return -1; // No match found
}

int main() {
    std::string text = "ababcababcabc";
    std::string pattern = "abc";

    int position = BMmatch(text, pattern);
    if (position != -1) {
        std::cout << "Pattern found at index: " << position << std::endl;
    } else {
        std::cout << "Pattern not found." << std::endl;
    }

    return 0;
}