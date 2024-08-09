#include<bits/stdc++.h>
using namespace std;


/*
    int bs(int l, int h, int t, vector<int> &nums){
        if(l<=h){

            int m=(l+h)/2;
            if(nums[m]==t) return m;
            else if(nums[m]<t) return bs(m+1,h,t,nums);
            else return bs(l,m-1,t,nums);
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        // int l=0,h=nums.size()-1;
        // while(l<=h){
        //     int m=(l+h)/2;
        //     if(nums[m]==target) return m;
        //     else if(nums[m]<target) l=m+1;
        //     else h=m-1;
        // }
        // return -1;


        return bs(0,nums.size()-1,target,nums);
    }
*/


bool bs(vector<int> &a,int start,int end,int key){
    if(start<=end){
        int mid=(start+end)/2;
        if(mid==key){
            return true;
        }
        if(mid>key){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
        bs(a,start,end,key);
    }
    else{
        return false;
    }
}
int main()
{
    vector<int> a={1,2,3,4,5};
    int key=6;
    cout<<bs(a,0,a.size()-1,key);
 return 0;
}