class Trie {
public:
    struct TrieNode{
        TrieNode* child[26];
        bool isEnd;
        TrieNode(){
            isEnd=false;
            for(int i=0;i<26;i++){
                child[i]=NULL;
            }
        }
    };
    
    TrieNode *root;
    Trie() {
        root=new TrieNode();
    }
    //General insert function
    void insert(string word) {
        TrieNode *curr=root;
        int n=word.size();
        for(int i=0;i<n;i++){
            int idx=word[i]-'a';
            if(curr->child[idx]==NULL){
                curr->child[idx]=new TrieNode();
            }
            curr=curr->child[idx];
        }
        curr->isEnd=true;
    }
    
    //General serach function
    bool search(string word) {
        TrieNode *curr=root;
        int n=word.size();
        for(int i=0;i<n;i++){
            int idx=word[i]-'a';
            if(curr->child[idx]==NULL) return false;
            curr=curr->child[idx];
        }
        return curr->isEnd;
    }
    //Prefix search function
    bool startsWith(string prefix) {
        TrieNode *curr=root;
        for(int i=0;i<prefix.size();i++){
            int idx=prefix[i]-'a';
            if(curr->child[idx]==NULL) return false;
            curr=curr->child[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */