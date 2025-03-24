#include <iostream>
#include "MyList.h"

using namespace std;

int main()
{
    MyList<string> group_names;
    MyList<MyList<string>> result;
    string group, name;
    while (true) {
        cin >> group;
        if (group == "0")
            break;
        cin >> name;
        int n = group_names.find(group);
        if (n < 0) {
            group_names.push_back(group);
            result.push_back(MyList<string>());
            result.at(result.get_size() - 1).push_back(group);
            result.at(result.get_size() - 1).push_back(name);
        } else
            result.at(n).push_back(name);
    }

    for (int i = 0; i < result.get_size(); i++) {
        result.at(i).print();
    }
    // MyList<char> a;
    // for (int i = 5; i > 0; i--) {
    //     a.push_back(char(i+105));
    // }
    // cout << "\n";
    // a.print();
    // a.sort();
    // cout << '\n';
    // a.print();
    return 0;
}