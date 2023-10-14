//https://stepik.org/lesson/13239/step/6?unit=3425

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std; 

int main() {
    int cnt, size;
    unordered_map<string, char> dict;

    cin >> cnt >> size;
    for (int i = 0; i < cnt; i++) {
        char sym, sep;
        string code;
        cin >> sym >> sep >> code;
        dict[code] = sym;
    }

    string inp, res;
    cin >> inp;

    string code;
    for (int i = 0; i < size; i++) {
        code.push_back(inp[i]);
        
        if (dict.find(code) != dict.end()) {
            res.push_back(dict[code]);
            code = "";
        }
    }

    cout << res;
    return 0;
}