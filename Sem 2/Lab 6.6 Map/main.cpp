#include <iostream>
#include <map>

using namespace std;

int main() {
    string input;
    getline(cin, input);
    input.append(" ");
    int start = 0;
    map<string, int> slov;
    for (int i = 0; i < input.length(); i++) {
        if (i == input.length() - 1 or input[i] == ' ') {
            string a = input.substr(start, i - start);
            if (slov.contains(a)) {
                ++slov[a];
            }else {
                slov[a] = 1;
            }
            start = ++i;
        }
    }
    for (pair<string,int> i: slov) {
        cout << i.first << ' ' << i.second << '\n';
    }

    return 0;
}