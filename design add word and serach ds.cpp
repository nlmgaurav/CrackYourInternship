class WordDictionary {
public:
    
    typedef struct TrieNode {
        TrieNode *children[26];
        bool endHere = false;
    } TrieNode;
    
    TrieNode *root;
    
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *ptr = root;
        for(int i = 0; i < word.length(); i++) {
            char ch = word[i];
            if(!ptr -> children[ch - 'a']) {
                TrieNode *temp = new TrieNode();
                ptr -> children[ch - 'a'] = temp;
            }
            ptr = ptr -> children[ch - 'a'];
        }
        ptr -> endHere = true;
    }
    
    bool search(string word) {
        return searchWord(0, word, root);
    }
    
    bool searchWord(int i, string &word, TrieNode *root) {
        if(i == word.length())
            return root -> endHere;
        char ch = word[i];
        if(ch != '.') {
            if(root -> children[ch - 'a'])
                return searchWord(i + 1, word, root -> children[ch - 'a']);
            else
                return false;
        }
        for(int j = 0; j < 26; j++) {
            if(root -> children[j] && searchWord(i + 1, word, root -> children[j])) 
                return true;
        }
        return false;
    }
};

