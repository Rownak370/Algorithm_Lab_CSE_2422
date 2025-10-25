#include <iostream>
using namespace std;
int main() {
    int n, num;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the element to search: ";
    cin >> num;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == num) {
            cout << "Element found at position " << i + 1 << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Element not found in the array." << endl;
    }
    return 0;
}
