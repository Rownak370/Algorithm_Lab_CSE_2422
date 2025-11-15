#include<bits/stdc++.h>
using namespace std;
int main() {
    string text, pat;
    int d = 256;       
    int q = 101;       

    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter pattern: ";
    getline(cin, pat);

    int n = text.size();
    int m = pat.size();

    int p = 0; 
    int t = 0;
    int h = 1;

    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    for (int i = 0; i < m; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + text[i]) % q;}

    cout << "\nPattern found at positions: ";
    for (int i = 0; i <= n - m; i++) {

        if (p == t) {  
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pat[j]) {
                    match = false;
                    break;}
            }
            if (match)
                cout << i << " ";}
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + 1 + m - 1]) % q;

            if (t < 0)
                t += q;}
    }
     return 0;
}
