#include<bits/stdc++.h>
using namespace std;
struct Act {
    int s, f;
};

bool cmp(Act a, Act b) {
    return a.f < b.f;
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    vector<Act> a(n);

    cout << "Enter start and finish times:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i].s >> a[i].f;
    }

    sort(a.begin(), a.end(), cmp);

    cout << "\nSelected activities:\n";

    cout << "(" << a[0].s << ", " << a[0].f << ")\n";
    int last = a[0].f;

    for (int i = 1; i < n; i++) {
        if (a[i].s >= last) {
            cout << "(" << a[i].s << ", " << a[i].f << ")\n";
            last = a[i].f;
        }
    }

    return 0;
}

