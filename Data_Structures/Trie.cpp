#include <iostream>
#include <unordered_map>
using namespace std;

// Trie Node structure
class TrieNode {
public:
    bool isEndOfWord;  // Indicates if the node represents the end of a word
    unordered_map<char, TrieNode*> children;  // Children of this node

    TrieNode() : isEndOfWord(false) {}
};

// Trie class
class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(const string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isEndOfWord = true;
    }

    // Search for a word in the Trie
    bool search(const string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }
            current = current->children[ch];
        }
        return current->isEndOfWord;
    }

    // Check if any word in the Trie starts with a given prefix
    bool startsWith(const string& prefix) {
        TrieNode* current = root;
        for (char ch : prefix) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }
            current = current->children[ch];
        }
        return true;
    }
};

int main() {
    Trie trie;

    // Insert words into the Trie
    trie.insert("hello");
    trie.insert("world");
    trie.insert("help");
    trie.insert("hell");
    trie.insert("hero");

    // Search for words
    cout << "Search for 'hello': " << (trie.search("hello") ? "Found" : "Not Found") << endl;
    cout << "Search for 'world': " << (trie.search("world") ? "Found" : "Not Found") << endl;
    cout << "Search for 'hero': " << (trie.search("hero") ? "Found" : "Not Found") << endl;
    cout << "Search for 'help': " << (trie.search("help") ? "Found" : "Not Found") << endl;
    cout << "Search for 'her': " << (trie.search("her") ? "Found" : "Not Found") << endl;

    // Check if any word starts with a given prefix
    cout << "Starts with 'he': " << (trie.startsWith("he") ? "Yes" : "No") << endl;
    cout << "Starts with 'wo': " << (trie.startsWith("wo") ? "Yes" : "No") << endl;
    cout << "Starts with 'ha': " << (trie.startsWith("ha") ? "Yes" : "No") << endl;

    return 0;
}
