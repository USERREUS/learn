//https://stepik.org/lesson/41234/step/1?unit=19818

#include <iostream>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {
    string inp;
    cin >> inp;
    
    unordered_map<char, char> brackets = { { '{', '}' }, { '[', ']' }, { '(' , ')' } };
    unordered_set<char> valid = { '{', '[', '(', ')', ']', '}' };
    stack<pair<char, int>> stk;

    for (int i = 0; i < inp.size(); i++) {
        if (valid.find(inp[i]) == valid.end()) {
            continue;
        }

        if (brackets.find(inp[i]) != brackets.end()) {
            stk.push({ inp[i], i });
        } 
        else {
            if (stk.empty()) {
                cout << to_string(i + 1);
                return 0;
            }
            
            pair<char, int> top = stk.top();
            stk.pop();

            if (brackets[top.first] != inp[i]) {
                cout << to_string(i + 1);
                return 0;
            }
        }
    }

    if (!stk.empty()) {
        cout << to_string(stk.top().second + 1);
        return 0;
    }

    cout << "Success";
    return 0;
}