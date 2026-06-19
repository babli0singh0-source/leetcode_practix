class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();
        queue<pair<string,int>>q;
        unordered_set<string>st(wordList.begin(),wordList.end());
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            string curr=q.front().first;
            int len=q.front().second;
            if(curr==endWord)return len;
            q.pop();
            for(int i=0;i<curr.size();i++){
                string temp=curr;
                for(char ch='a';ch<='z';ch++){
                    temp[i]=ch;
                    if(st.count(temp)){
                        q.push({temp,len+1});
                        st.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};

// The key idea is: instead of asking

// "Which words in the dictionary differ by one character from my current word?"

// we ask

// "What words can I create by changing one character of my current word?"

// This avoids scanning the entire dictionary.
