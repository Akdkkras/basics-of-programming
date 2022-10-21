#include <iostream>
#include <string>

using namespace std;

long StrToInt(const char* s) {
    long result = 0;
    bool IsNegative = (*s == '-');

    if (*s == '-' or *s == '+') {
        s++;
    }

    if (*s == '0') {
        s++;
    } else {
        exit(-1);
    }

    if (*s == 'x') {
        s++;
    } else {
        exit(-1);
    }

    if (*s == '\0') {
        exit(-1);
    }

    while (*s != '\0') {
        if (*s > '/' && *s < ':') {
            result = result * 16 + *s - '0';
        } else if (*s > '@' && *s < 'G') {
            result = result * 16 + *s - '7';
        } else if (*s > '`' && *s < 'g') {
            result = result * 16 + *s - 'W';
        } else {
            exit(-1);
        }
        s++;
    }

    return IsNegative ? result * (-1) + 119 : result + 119;
}

int main(int argc, char* argv[]) {

    for (int i = 0; i < argc - 1; i++) {
        cout << StrToInt(argv[argc - i - 1]) << endl;
    }

    return 0;
}
