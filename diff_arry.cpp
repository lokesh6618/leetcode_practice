#include <bits/stdc++.h>

using namespace std;



vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>> result;
    unordered_set<int> diff_arr;
    unordered_set<int> diff_arr_2;
    vector<int> arr_1;
    vector<int> res_1, res_2;

    for(auto i : nums1){
        diff_arr.insert(i);
    }

    for(auto i : nums2){

        if(diff_arr.find(i) != diff_arr.end()){
            arr_1.push_back(i);
        }else{
            diff_arr_2.insert(i);
        }

    }

    for(auto i: arr_1){
        if(diff_arr.find(i) != diff_arr.end()){
            diff_arr.erase(i);
        }
    }

    cout << "arr 1: ...................." << endl;

    for(auto i: diff_arr){
        cout << i << ",";
        res_1.push_back(i);
    }

    cout << endl;

    cout << "arr 2: ...................." << endl;

    for(auto i: diff_arr_2){
        cout << i << ",";
        res_2.push_back(i);
    }

    cout << endl;

    for(auto i: arr_1){
        cout << i << ",";
    }

    cout << endl;

    result.push_back(res_1);
    result.push_back(res_2);

    return result;
}

int main()
{   
    vector<int> nums1 = {1,2,3,3};
    vector<int> nums2 = {1,1,2,2};

    auto result = findDifference(nums1, nums2);
    cout << "done testing" << endl;
    return 0;
}