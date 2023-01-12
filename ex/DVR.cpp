#include<iostream>
#include<vector>
using namespace std;

int main(){

    int nodes;
    cout<<"Enter the nodes"<<endl;
    cin>>nodes;

    int costmat[20][20] = {0};

    for(int i =0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            int temp;
            cin>>temp;
            if(i==j){
                continue;
            }
            if(temp==0){
                costmat[i][j] = 1e9;
            }
            else{
                costmat[i][j] = temp;
            }
        }
    }

    int mat[20][20] = {0};

    for(int k = 0;k<nodes;k++){
        for(int i = 0;i<nodes;i++){
            for(int j = 0;j<nodes;j++){
                if(costmat[i][j]>costmat[i][k]+costmat[k][j]){
                    costmat[i][j]=costmat[i][k]+costmat[k][j];
                    mat[i][j] = k;
                }
            }
        }
    }

    for(int i = 0;i<nodes;i++){
        cout<<"Routing table of node "<<i<<endl;
        cout<<"Des   | cost   | via"<<endl;
        for(int j = 0;j<nodes;j++){
            cout<<j<<" | "<<costmat[i][j]<<"  | "<<mat[i][j]<<endl;
        }
    }
    
    return 0;
}