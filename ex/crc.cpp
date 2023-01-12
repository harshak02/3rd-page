#include<vector>
#include<iostream>
using namespace std;
                  

                    
    void check(vector<int>&dividend,vector<int>&divisor){
             int m=dividend.size();
              int n=divisor.size();

              for(int i=0;i<m-n+1;i++){
                if(dividend[i]==0){
                    continue;
                }
                else{
                    int k=0;
                    for(int j=i;j<i+n;j++){
                        dividend[j]=dividend[j]^divisor[k];
                        k++;
                    }
                }
              }

    }   

int main()
{
    
    vector<int> dividend = {1,0,0,1,0,0,0,0,0};
    vector<int> divisor = {1,1,0,1};
    int m=dividend.size();
    int n=divisor.size();

    check(dividend,divisor);
    for(auto iter : dividend){
        cout<<iter<<" ";
    }
    cout<<endl;

    cout<<"crc code:";

    for(int i=m-n+1;i<m;i++){
        cout<<dividend[i];
    }
    cout<<endl;
    vector<int> D{1,0,0,1,0,0,0,0,1};
    check(D,divisor);
    int t=0;
    for(int i=m-n+1;i<m;i++){
        if(D[i]==1){
            cout<<"incorrect data";
            t=-1;
            break;
        }
    }
    if(m!=-1){
        cout<<"data perfect"<<endl;
    }

     return 0;
}