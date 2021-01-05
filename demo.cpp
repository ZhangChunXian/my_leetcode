#include
int main() {
    char s1[] = "GeeksforGeeks";
    char s2[] = "for";
    char* p;

    p = strstr(s1, s2);

    if (p) {
        std::cout << p;
    }
    return 0;
}