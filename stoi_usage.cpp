#include <iostream>
#include <string>

using namespace std;

int main() {
    string str1 = "123";
    int x = stoi(str1);
    cout << "stoi(\"" << str1 << "\") is " << x << '\n';
}
