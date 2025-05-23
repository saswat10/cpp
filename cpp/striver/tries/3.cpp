#include<bits/stdc+++.h>
using namespace std;

struct Node{
  Node* links[26];
  bool flag = false;

  bool containsKey(char ch){
    return links[ch-'a'];
  }

  Node* get(char ch){
    return links[ch-'a'];
  }
  
  void put(char ch, Node* node){
    links[ch-'a'] = node;
  }

  void setEnd(){
    flag = true;
  }

  bool isEnd(){
    return flag;
  }
}

class Trie{
private: Node* root;
public: 
  Trie(){
    root = new Node(); 
  }

  void insert(string &word){
    Node* node = root;
    for(int i = 0; i < word.length(); i++){
      if(!node->containsKey(word[i])){
        node->put(ch, new Node());
      }
      // moves to the next reference trie
      node = node->get(word[i]);
    }

    node->setEnd();
  }

  bool checkIfPrefixExists(string &word){
    Node* node = root;
    bool flag = true;
    for(int i = 0; i < word.length(); i++){
      if(node->containsKey(word[i])){
        node = node->get(word[i]);
        flag = flag & node->isEnd();
      }else return false;
    }

    return flag;
  }
};

string completeString(int n, vector<string> &a){
  Trie trie;
  for(auto &it: a){
    trie.insert(it);
  }

  string longest = "";
  for(auto &it: a){
    if(trie.checkIfPrefixExists(it)){
      if(it.length() > longest.length()){
        longest = it;
      }
      // checking for lexicographically smallest
      else if(it.length() == longest.length() && it < longest){
        longest = it;
      }
    }
  }

  if(longest ==  "") return "None";
  return longest;
  
}
