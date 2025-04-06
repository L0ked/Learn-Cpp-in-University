#include <iostream>

using namespace std;

struct Human {
    string surname;
    string name;
    int age;

    static bool compareBySurname(const Human & a, const Human & b) {
        return a.surname < b.surname;
    }
    static bool compareByName(const Human & a, const Human & b) {
        return a.name < b.name;
    }
    static bool compareByAge(const Human & a, const Human & b) {
        return a.age < b.age;
    }
};

bool comparePair(const pair<string, int> & a, const pair<string, int> & b) {
    return a.second < b.second;
}

template<class T, class Compare>
int partquicksort(T * arr, int left, int right, Compare comp) {
    auto pilot = arr[(left + right) / 2];
    while (left <= right) {
        while (comp(arr[left], pilot)) ++left;
        while (comp(pilot, arr[right])) -- right;
        if (left <= right) {
            swap(arr[left], arr[right]);
            ++left;
            --right;
        }
    }
    return left;
}

template<class T, class Compare>
void quicksort(T * arr, int start, int end, Compare comp) {
    if (start >= end)
        return;
    int rightstart = partquicksort<T>(arr, start, end, comp);
    quicksort<T>(arr, start, rightstart - 1, comp);
    quicksort<T>(arr, rightstart, end, comp);
}


template<class T>
int partquicksort(T * arr, int left, int right) {
    T pilot = arr[(left + right) / 2];
    while (left <= right) {
        while (arr[left] < pilot) ++left;
        while (arr[right] > pilot) -- right;
        if (left <= right) {
            swap(arr[left], arr[right]);
            ++left;
            --right;
        }
    }
    return left;
}


template<class T>
void quicksort(T * arr, int start, int end) {
    if (start >= end)
        return;
    int rightstart = partquicksort<T>(arr, start, end);
    quicksort<T>(arr, start, rightstart - 1);
    quicksort<T>(arr, rightstart, end);
}




int main() {
    int nums[] = {5, 2, 9, 1, 5, 6};
    quicksort(nums, 0, size(nums) - 1);
    for (int i: nums)
        cout << i << ' ';
    cout << "\n\n";


    pair<string, int> people[] = {{"Ivanov", 25}, {"Petrov", 30}, {"Sidorov", 20}};
    quicksort(people, 0, size(people) - 1, comparePair);
    for (auto& i : people)
        cout << i.first << ' ' << i.second << '\n';


    Human human[] = {{"Ivanov", "Semen", 25},
        {"Petrov", "Ivan", 30}, {"Sidorov", "Petr", 20}};

    cout << "\nSort by Surname:\n";
    quicksort(human, 0,size(human) - 1, Human::compareBySurname);
    for (auto &i: human)
        cout << i.surname << ' ' << i.name << ' ' << i.age << '\n';

    cout << "\nSort by Name:\n";
    quicksort(human, 0,size(human) - 1, Human::compareByName);
    for (auto &i: human)
        cout << i.surname << ' ' << i.name << ' ' << i.age << '\n';

    cout << "\nSort by Age:\n";
    quicksort(human, 0,size(human) - 1, Human::compareByAge);
    for (auto &i: human)
        cout << i.surname << ' ' << i.name << ' ' << i.age << '\n';

    return 0;
}