class WordDictionary {
public:
    struct node{
        node *child[26];
        bool isend;
        node(){
            isend=false;
            for(int i=0;i<26;i++){
                child[i]=NULL;
            }
        }
    };
    node *root=NULL;
    WordDictionary() {
        root=new node();
    }
    void addWord(string word) {
        node *t=root;
        for(char ch:word){
            if(t->child[ch-'a']==NULL)
                t->child[ch-'a']=new node();
            t=t->child[ch-'a'];
        }
        t->isend=1;
    }
    bool find(const string &word,int index,node* t_root){
        int size=word.size();
        for(;index<size;++index){
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
        return t_root->isend;
    }
    bool search(string word){
        return find(word,0,root);
    }
};
