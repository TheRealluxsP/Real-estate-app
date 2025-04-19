#include <iostream>

using namespace std;

int main() {
    std::locale::global(std::locale(""));  // (*)
    std::wcout.imbue(std::locale());

    std::wcout << L"Hello, World!" << std::endl;

    return 0;
}