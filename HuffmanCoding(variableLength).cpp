#include<bits/stdc++.h>
using namespace std;
struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};
void printCodes(Node* root, string str) {
    if (!root) return;
    if (!root->left && !root->right) {
        cout << root->ch << " : " << str << endl;
    }
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}
int main() {
    string text;
    cout << "Enter the string to encode: ";
    cin >> text;
    unordered_map<char, int> freq;
    for (char c : text) {
        freq[c]++;
    }
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* parent = new Node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }
    Node* root = pq.top();
    cout << "\nHuffman Codes:\n";
    printCodes(root, "");

    return 0;
}

