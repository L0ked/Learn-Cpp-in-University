#include <iostream>

using std::cin, std::cout;

void printArr(auto *arr, int l) {
    for(int i = 0; i < l; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void bubble(int *arr, int l) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int a = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = a;
            }
        }
    }
    printArr(arr, l);
}

void counting(char *arr, int l) {
    int num_el = 26, el0 = int('a');
    int count_el[num_el] = {0};
    for (int i = 0; i < l; i++) {
        count_el[int(arr[i])-el0]++;
    }
    int globindex = 0;
    for (int i = 0; i < num_el; i++) {
        int a = count_el[i];
        for (int j = 0; j < a; j++) {
            arr[globindex] = char(i + el0);
            globindex++;
        }
    }
    printArr(arr,l);
}

void merge_sort(int *arr, int s, int l) {
    int i = s;
    int mid = s + (l - s)/2;
    int j = mid + 1;
    int pos = 0;
    int barr[l - s + 1];
    while (i <= mid && j <= l) {
        if (arr[i] < arr[j]) {
            barr[pos++] = arr[i++];
        } else {
            barr[pos++] = arr[j++];
        }
    }
    while (i <= mid) {
        barr[pos++] = arr[i++];
    }
   while (j <= l) {
        barr[pos++] = arr[j++];
    }
    for (int k = s; k <= l; k++) {
        arr[k] = barr[k - s];
    }
}

void merge_drob(int *arr, int s, int l) {
    if (s >= l) return;
    int mid = s + (l - s) / 2;
    merge_drob(arr, s, mid);
    merge_drob(arr, mid + 1, l);
    merge_sort(arr, s, l);
}


void merge(int *arr, int l) {
    merge_drob(arr, 0, l - 1);
    printArr(arr, l);
}



int main() {
    int m = 0;
    while (m != 4) {
        cout << "Menu:\n1. Bubble sort\n2. Counting sort\n3. Merge sort\n4. Quit\n";
        cin >> m;
        switch (m) {
            case 1: {
                cout << "1. Bubble sort\nEnter len arr:\n";
                int l, n;
                cin >> l;
                cout << "Enter element:\n";
                int arr[l];
                for (int k = 0; k < l; k++) {
                    cin >> n;
                    arr[k] = n;
                }
                bubble(arr, l);
                break;
            }
            case 2: {
                cout << "2. Counting sort\nEnter len arr:\n";
                int l;
                char a;
                cin >> l;
                cout << "Enter element:\n";
                char arr[l];
                for (int k = 0; k < l; k++) {
                    cin >> a;
                    arr[k] = a;
                }
                counting(arr, l);
                break;
            }
            case 3: {
                cout << "3. Merge sort\nEnter len arr:\n";
                int l, n;
                cin >> l;
                cout << "Enter element:\n";
                int arr[l];
                for (int k = 0; k < l; k++) {
                    cin >> n;
                    arr[k] = n;
                }
                merge(arr, l);
                break;
            }
            default:
                break;
        }
    }
}
