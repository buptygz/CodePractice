//
//  leetcode321.cpp
//  test
//
//  Created by 於光中 on 2017/9/6.
//  Copyright © 2017年 於光中. All rights reserved.
//
#include "vector"
#include "iostream"
using namespace std;
int choose(vector<int>& num1, vector<int>& num2){
    int temp1=num1[0],temp2=num2[0],index1=0,index2=0;
    for(int i=0;i<num1.size();i++){
        if(num1[i]>temp1){
            temp1=num1[i];
            index1=i;
        }
    }
    for(int i=0;i<num2.size();i++){
        if(num2[i]>temp2){
            temp2=num2[i];
            index2=i;
        }
    }
    if (temp1 > temp2){
        num1.erase(num1.begin(),num1.begin()+index1-1);
        return 1;
    }
    else if(temp1 < temp2){
        num2.erase(num2.begin(),num2.begin()+index2-1);
        return 2;
    }
    else
    {
        num2.erase(num2.begin()+index2-1,num2.end());
        num1.erase(num1.begin()+index1-1,num1.end());
        return choose(num1,num2);
    }

    
}
vector<int> max(vector<int>& vec){
    int m=vec[0],in=0;
    vector<int> key;
    for(int i=0;i<vec.size();i++){
        if(vec[i]>m){
            m=vec[i];
            in=i;
        }
    }
    key.push_back(m);
    key.push_back(in);
    return key;
}
vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<int> sol,tep1,tep2;
    for(int j=0;j<k;j++){
    int flag=choose(nums1,nums2);
    if (flag==1){
        tep1=max(nums1);
        sol.push_back(tep1[0]);
        nums1.erase(nums1.begin(),nums1.begin()+tep1[1]);
    }
    else if(flag==2){
        tep2=max(nums2);
        sol.push_back(tep2[0]);
        nums2.erase(nums2.begin(),nums2.begin()+tep2[1]);
    }
        tep1.clear();
        tep2.clear();
    }
    return sol;
}

int main(){
    int a[4]={3,4,6,5};
    int b[6]={9,1,2,5,8,3};
    vector<int> nums1(&a[0],&a[3]);
    vector<int> nums2(&b[0],&b[5]);
    vector<int> ans=maxNumber(nums1, nums2, 5);
    for(int j=0;j<5;j++)
    {
        cout<< ans[j];
    }
    return 0;
}

