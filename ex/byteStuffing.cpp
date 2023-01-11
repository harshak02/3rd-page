#include<iostream>
#include<vector>
using namespace std;

int main(){
    
    cout<<"The stuffing Characters are : flag(f) && esc(e)"<<endl;

    string payLoad;
    cout<<"Enter the payLoad String"<<endl;
    cin>>payLoad;

    int num;
    cout<<"Enter 1 for byte Stuffing and 2 for byte Unstuffing"<<endl;
    cin>>num;

    if(num==1){
        string newPayLoad = "";
        int ind = 0;
        int cnt = 0;

        while(ind<payLoad.size()){
            if(payLoad[ind]=='f' || payLoad[ind]=='e'){
                newPayLoad+='e';
            }
            newPayLoad+=payLoad[ind];
            ind++;
        }
        cout<<newPayLoad<<endl;
    }

    else{
        string deStuffed = "";
        int ind = 0;

        while(ind<payLoad.size()){
            if(payLoad[ind]=='e'){
                ind++;
                deStuffed+=payLoad[ind];
                ind++;
            }
            else{
                deStuffed+=payLoad[ind];
                ind++;
            }
        }

        cout<<deStuffed<<endl;
    }

    return 0;
}
