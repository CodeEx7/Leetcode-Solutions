class WordDictionary {
public:
    struct node{
        node *child[26];
        bool isEnd;
        node(){
            isEnd=false;
            for(int i=0;i<26;i++){
                child[i]=NULL;
            }
        }
    };
    //creating root Node
    node *root=NULL;
    
    WordDictionary() {
        root=new node();
    }
    
    void addWord(string word) {
        node *curr=root;
        for(int i=0;i<word.size();i++){
            int idx=word[i]-'a';
            if(curr->child[idx]==NULL){
                curr->child[idx]= new node();
            }
            curr=curr->child[idx];
        }
        curr->isEnd=true;
    }
    bool find(const string &word,int index,node* t_root){
        for(;index<word.size();++index){
            if(word[index]=='.'){
                for(int i=0;i<26;++i){
                    if(t_root->child[i] and find(word,index+1,t_root->child[i])){
                        return 1;
                    }
                }
                return 0;
            }else if(t_root->child[word[index]-'a']){
                t_root=t_root->child[word[index]-'a'];
            }else{
                return 0;
            }
        }
        return t_root->isEnd;
    }
    bool search(string word){
        return find(word,0,root);
    }
};
