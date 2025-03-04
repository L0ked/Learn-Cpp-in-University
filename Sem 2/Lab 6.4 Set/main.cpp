#include <iostream>
#include <set>

using namespace std;

struct Answer {
    int id, answer;
    bool operator<(const Answer& other) const {
        return id < other.id; // для сэта, так как он сортирует
    }
};

int main() {
    int id, answer;
    set<int> mass;
    set<Answer> pair;
    cout << "For Break enter 0\n";
    while (true) {
        cin >> id;
        if (id <= 0)
            break;
        cin >> answer;
        if (!mass.contains(id)) {
            mass.insert(id);
            pair.insert(Answer(id,answer));
        }
    }
    cout << "SAVED:\n";
    for (Answer i : pair) {
        cout << i.id << " " << i.answer << "\n";
    }
    return 0;
}