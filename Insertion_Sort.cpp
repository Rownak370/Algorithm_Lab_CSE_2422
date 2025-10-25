
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i < n; i++) {
        int num = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > num) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = num;
    }
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
