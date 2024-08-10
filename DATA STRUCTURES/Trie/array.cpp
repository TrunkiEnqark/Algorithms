#include <bits/stdc++.h>

using namespace std;

class Trie {
private:
    struct Node {
        int child[26];
        int cnt;

        Node() : cnt(0) {
            memset(child, -1, sizeof child);
        }
    };

    vector<Node> trie;
    int cnt;
public:
    Trie() : trie(1), cnt(0) {};

    void insert(const string& s) {
        int root = 0;
        for (auto c : s) {
            int nxt = c - 'a';
            if (trie[root].child[nxt] == -1) {
                trie[root].child[nxt] = ++cnt;
                if (cnt >= trie.size()) {
                    trie.push_back(Node());
                }
            }
            root = trie[root].child[nxt];
        }
        trie[root].cnt++;
    }

    bool find(const string& s) {
        int root = 0;
        for (auto c : s) {
            int nxt = c - 'a';
            if (trie[root].child[nxt] == -1) return false;
            root = trie[root].child[nxt];
        }
        return trie[root].cnt > 0;
    }

    void erase(const string& s) {
        if (!find(s)) return;
        int root = 0;
        for (auto c : s) {
            int nxt = c - 'a';
            root = trie[root].child[nxt];
        }
        trie[root].cnt--;
    }

    void dfs(int u, string cur = "") {
        if (trie[u].cnt > 0) {
            cout << cur << '\n';
        }
        for (int c = 0; c < 26; ++c) {
            if (trie[u].child[c] != -1) {
                dfs(trie[u].child[c], cur + char(c + 'a'));
            }
        }
    }
};

Trie tree = Trie();

int main() {
    vector<string> words = {"abc", "a", "ab", "cba", "zzz", "aaa"};

    for (auto word : words) {
        tree.insert(word);
    }
    // cout << tree.find("abc");
    tree.dfs(0);
}