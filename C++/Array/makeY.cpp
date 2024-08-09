#include<bits/stdc++.h>
using namespace std;
int makeY(vector<vector<int>> mat,int num){
    
    int count=0;
    int n=mat.size();
    int centerRow=n/2;
    for(int i=0;i<centerRow;i++){
        int k=i;
        if(mat[i][i]!=num){
            count++;
            mat[i][i]=num;
        }
        if(mat[i][n-1-i]!=num){
            count++;
            mat[i][n-1-i]=num;
        }
    }
    for (int i = 0; i <= centerRow; i++)
    {
        if(mat[centerRow+i][centerRow]!=num){
            count++;
            mat[centerRow+i][centerRow]=num;
        }
    }
    return count;
}
int main()
{
    vector<vector<int>> a={{0,1,2,1,0},{0,0,1,2,1},{0,0,1,2,1},{1,2,0,1,2},{0,1,2,0,1}};
    int ans=a.size()*a.size();
    for (int i = 0; i < 3; i++)
    {
        ans=min(ans,makeY(a,i));
    }
    
cout<<ans;


 return 0;
}