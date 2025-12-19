#include <iostream>
#include <vector>
#include <string>

std::vector<int> computeFailFunction(const std::string& pattern) {
    std::vector<int> fail(pattern.size());
    fail[0] = 0;
    int m = pattern.size();
    int j = 0;
    int i = 1;
    while(i < m) {
        if(pattern[i] == pattern[j]) {
            fail[i] = j + 1;
            i++; j++;
        }
        else if(j > 0)
            j = fail[j - 1];
        else {
            fail[i] = 0;
            i++;
        }
    }
    return fail;
}

int KPMmatch(const std::string& text, const std::string& pattern) {
    int n = text.size();
    int m = pattern.size();
    std::vector<int> fail = computeFailFunction(pattern);
    int count = 0;
    int i = 0; // index for text
    int j = 0; // index for pattern
    while(i < n) {
        if(pattern[j] == text[i]) {
            if(j == m - 1)
                return i - m + 1; // Match found
            i++; j++;
        }
        else if(j > 0) {
            j = fail[j - 1];
        }
        else i++;
    }
    return -1; // Return -1 if no match found
}

int main()
{
    std::string text = "ababcababcabc";
    std::string pattern = "abc";

    int position = KPMmatch(text, pattern);
    if (position != -1) {
        std::cout << "Pattern found at index: " << position << std::endl;
    } else {
        std::cout << "Pattern not found." << std::endl;
    }

    return 0;
}