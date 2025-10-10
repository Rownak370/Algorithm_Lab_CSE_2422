#include <bits/stdc++.h>
using namespace std;
int main() {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;
    int n = s1.length();
    int m = s2.length();
    int LCS[100][100];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0)
                LCS[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                LCS[i][j] = 1 + LCS[i - 1][j - 1];
            else
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);}
    }
    int i = n, j = m;
    string lcs = "";
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs = s1[i - 1] + lcs; 
            i--;
            j--;
        } else if (LCS[i - 1][j] > LCS[i][j - 1])
            i--;
        else
            j--;}
    cout << "Length of LCS: " << LCS[n][m] << endl;
    cout << "LCS string: " << lcs << endl;
    return 0;}

