#include <iostream>

using namespace std;

int hashCode(const char *p, int len) {
    unsigned int h = 0;
    for (int i = 0; i < len; ++i) {
        h = (h << 5) | (h >> 27); // rotate left 5 bits
        h += (unsigned char)(p[i]);
    }
    return (int)h;
}

int hasCode(const float& x) {
    int len = sizeof(x);
    const char *p = reinterpret_cast<const char *>(&x);
    return hashCode(p, len);
}

int main() {
    const char *str = "Hello, World!";
    int len = 13; // Length of the string

    int hash = hashCode(str, len);
    cout << "Hash code: " << hash << std::endl;

    float num = 3.14f;
    int floatHash = hasCode(num);
    cout << "Hash code for float: " << floatHash << std::endl;

    return EXIT_SUCCESS;
}