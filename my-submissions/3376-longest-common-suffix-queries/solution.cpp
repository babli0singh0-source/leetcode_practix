// //now we wont need node we will do array based optimization instead of using a node
// //we will use a vector 
// struct Trienode{
//     int links[26];
//     int ind;
//     Trienode(){
//         ind=1e8;
//         fill(begin(links),end(links),-1);
//     } 
    
// };
// class Trie{
// private:
//     vector<Trienode>nodes;
// public:
//     Trie(){//constructor called whenever this class is used 
//         nodes.push_back(Trienode());
//     }
//     void insert(string &word,int i,vector<string>& wordsContainer){
//         int currind=0;
//         for(int j=word.size()-1;j>=0;j--){
//             if(nodes[currind].links[word[j]-'a']==-1){
//                 nodes[currind].links[word[j]-'a']=nodes.size();//next room
//                 nodes.push_back(Trienode());
//             }
//             currind=nodes[currind].links[word[j]-'a'];//going to child room 
//             int prev=nodes[currind].ind;
//             if(prev==1e8)nodes[currind].ind=i;
//             else if(word.size()<wordsContainer[prev].size())nodes[currind].ind=i;
//             else if(word.size()==wordsContainer[prev].size()&&i<prev)nodes[currind].ind=i;
//         }
//     }
//     int check(string &word,int &smallind){
//         int currind=0;
//         for(int j=word.size()-1;j>=0;j--){
//             if(nodes[currind].links[word[j]-'a']==-1){
//                 if(j==word.size()-1)return smallind;
//                 return nodes[currind].ind;
//             }
//             currind=nodes[currind].links[word[j]-'a'];
//         }
//         return nodes[currind].ind;
//     }
// };

// class Solution {
// public:

//     vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
//         Trie trie;
//         int n=wordsContainer.size();
//         int small=INT_MAX;
//         int smallind=-1;
//         vector<int>ans;
//         for(int k=0;k<n;k++){
//             trie.insert(wordsContainer[k],k,wordsContainer);
//             if(wordsContainer[k].size()<small){
//                 smallind=k;
//                 small=wordsContainer[k].size();
//             }
//         }
//         for(auto &it:wordsQuery){
//             ans.push_back(trie.check(it,smallind));
//         }
//         return ans;
//     }
// };

//gives mle on 2 test cases 
struct node{
    node* links[26];
    node(){
        for(int i=0;i<26;i++) links[i]=NULL;
    }
    int ind=1e8;//index of word from which it came ;
    void setind(int i){
        ind=i;
    }
    int getind(){
        return ind;
    }
    bool containskey(char ch){//checks if the character is present 
        return links[ch-'a']!=NULL;//is that index in the root filed or not 
    }
    void put(char ch,node* node){
        links[ch-'a']=node;
    }
    node* get(char ch){
        return links[ch-'a'];
    }

};
class Trie{
private: 
    node* root;
    void delnode(node* root){
        if(!root)return ;
        for(int i=0;i<26;i++){
            delnode(root->links[i]);
        }
        delete root;
    }

public:
    Trie(){
        root=new node();
    }
    void insert(string &word,int i,vector<string>& wordsContainer){
        node* temp =root;
        for(int j=(int)word.size()-1;j>=0;j--){
            if(!temp->containskey(word[j])){
                temp->put(word[j],new node());
            }
            temp=temp->get(word[j]);// go to the reference node
            int prev=temp->getind();
            if(prev==1e8)temp->setind(i);
            else if(word.size()<wordsContainer[prev].size())temp->setind(i);
            else if(word.size()==wordsContainer[prev].size()&&i<prev)temp->setind(i);
        }
    }
    int check(string &word,int &smallind){
        node* temp =root;
        for(int j=(int)word.size()-1;j>=0;j--){
            if(!temp->containskey(word[j])){
                if(j==word.size()-1)return smallind;
                return temp->getind();
            }
            temp=temp->get(word[j]);//go to ref node;
        }
        return temp->getind();
    }
    ~Trie(){
        delnode(root);
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie trie;
        int n=wordsContainer.size();
        int small=INT_MAX;
        int smallind=-1;
        vector<int>ans;
        for(int k=0;k<n;k++){
            trie.insert(wordsContainer[k],k,wordsContainer);
            if(wordsContainer[k].size()<small){
                smallind=k;
                small=wordsContainer[k].size();
            }
        }
        for(auto &it:wordsQuery){
            ans.push_back(trie.check(it,smallind));
        }
        return ans;
    }
};
