#include <bits/stdc++.h>

using namespace std;

class Trie {
private:
    struct Node {
        Node* child[26];
        int cnt;

        Node() : cnt(0) {
            for (int ch = 0; ch < 26; ++ch) 
                child[ch] = nullptr;
        }

        ~Node() {
            for (int ch = 0; ch < 26; ++ch)
                delete child[ch];
        }
    };
    Node* root;
public:
    Trie() : root(new Node()) {}

    ~Trie() {
        delete root;
    }

    void insert(const string& s) {
        Node* cur = root;
        for (auto c : s) {
            int nxt = c - 'a';
            if (cur->child[nxt] == nullptr) {
                cur->child[nxt] = new Node();
            }
            cur = cur->child[nxt];
        }
        cur->cnt++;
    }

    bool find(const string& s) {
        Node* cur = root;
        for (auto c : s) {
            int nxt = c - 'a';
            if (cur->child[nxt] == nullptr) return false;
            cur = cur->child[nxt];
        }
        return cur->cnt > 0;
    }

    void erase(const string& s) {
        if (!find(s)) return;

        Node* cur = root;
        for (auto c : s) {
            int nxt = c - 'a';
            cur = cur->child[nxt]; 
        }
        cur->cnt--;
    }

    void dfs(Node* current_node = nullptr, string current_string = "") {
        if (current_node == nullptr) {
            current_node = root;
        }
        
        if (current_node->cnt > 0) {
            cout << current_string << '\n';
        }
        for (int c = 0; c < 26; ++c) {
            if (current_node->child[c] != nullptr) {
                dfs(current_node->child[c], current_string + char(c + 'a'));
            }
        }
    }
};

Trie trie = Trie();

int main() {
    vector<string> words = {"abc", "a", "ab", "cba", "zzz", "aaa"};

    for (auto word : words) {
        trie.insert(word);
    }
    // cout << trie.find("abc");
    trie.dfs();
}