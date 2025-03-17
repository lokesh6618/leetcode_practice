#include <bits/stdc++.h>

using namespace std;

bool closeStrings(string word1, string word2) {
    unordered_map<char, int> map_1;
    unordered_map<char, int> map_2;
    unordered_set<int> set_1;
    unordered_set<int> set_2;
    vector<int> list_1, list_2;

    if(word1.length() != word2.length()){
        return false;
    }

    for(auto i : word1){
        map_1[i]++;
    }

    for(auto i : word2){
        map_2[i]++;
    }

    if(map_1.size() != map_2.size()){
        return false;
    }

    for(auto i : map_1){
        list_1.push_back(i.second);
    }

    for(auto i : map_2){
        list_2.push_back(i.second);
    }

    // for(auto i : set_1){
    //     cout << i << ", ";
    // }

    // cout << endl;

    // for(auto i : set_2){
    //     cout << i << ", ";
    // }

    // cout << endl;

    if(list_1.size() != list_2.size()){
        return false;
    }

    sort(list_1.begin(), list_1.end());
    sort(list_2.begin(), list_2.end());

    for(int i = 0; i < list_1.size(); i++){
        if(list_1[i] != list_2[i]){
            return false;
        }
    }

    // for(auto i : set_2){
    //     if(set_1.find(i) == set_1.end()){
    //         return false;
    //     }
    // }
    
    return true;
}

int main()
{   
    string word_1 = "aaabbbbccddeeeeefffff";
    string word_2 = "aaaaabbcccdddeeeeffff";

    auto result = closeStrings(word_1, word_2);

    cout << result << endl;
    cout << "done testing" << endl;
    
    return 0;
}