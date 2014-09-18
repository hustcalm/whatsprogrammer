#include <iostream>
#include <string>
using std::string;

string g_value;

void callback() {
    g_value = "blue";
}

void ProcessStringByRef(const string &s) {
    string& str = const_cast<string&>(s);
    str = "hello";
    std::cout << s << "\n";
    callback();
    std::cout << s << "\n";
}

void ProcessStringByValue(const string s) {
    callback();
    std::cout << s << "\n";
}

int main() {
    g_value = "red";
    ProcessStringByValue(g_value);
    g_value = "red";
    ProcessStringByRef(g_value);
}
