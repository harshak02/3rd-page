#include<iostream>
#include<vector>
using namespace std;

vector<int> check(vector<int> &dividend,vector<int> &divisor,int m,int n){

    for(int i =0;i<m-n+1;i++){
        if(dividend[i]==0){
            continue;
        }
        else{
            int k = 0;
            for(int j = i;j<i+n;j++){
                dividend[j] = dividend[j]^dividend[k];
                k++;
            }
        }
    }

    vector <int> remi;

    for(int i = m-n+1;i<m;i++){
        remi.push_back(dividend[i]);
    }

    return remi;
}

int main(){
    vector <int> dividend{1,0,0,1,0,0,0,0,0,1,1,1,0};
    vector <int> divisor{1,1,0,1};

    int m = dividend.size();
    int n = divisor.size();

    vector <int> remi = check(dividend,divisor,m,n);
    int remiSize = remi.size();

    //replace the remi with the divi
    for(int i = m-remiSize+1;i<m;i++){
        dividend[i] = remi[i];
    }

    vector <int> remi2 = check(dividend,divisor,m,n);

    for(int i = 0;i<remi2.size();i++){
        if(remi2[i]==1){
            cout<<"Incorrect data"<<endl;
            return 0;
        }
    }

    cout<<"Correct Data"<<endl;
    return 0;
}