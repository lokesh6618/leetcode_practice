#include <bits/stdc++.h>

using namespace std;


bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> map_1;
    unordered_set<int> list_1;

    for(auto i : arr){
        map_1[i]++;
        // auto current_element = map_1.find(i);

        // if(current_element != map_1.end()){
        //     current_element->second++;
        // }else{
        //     map_1[i] = 1;
        // }

    }

    for(auto i : map_1){
        if(list_1.find(i.second) != list_1.end()){
            return false;
        }else{
            list_1.insert(i.second);
        }
    }

    return true;
}

int main()
{   
    vector<int> nums1 = {1,2,2,1,1,3};

    auto result = uniqueOccurrences(nums1);
    cout << "done testing" << endl;
    return 0;
}