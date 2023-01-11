#include<iostream>
#include<vector>
using namespace std;

int main(){

    cout<<"The flag bits we are working are : 01111110\n"<<endl;
    string payLoadData;
    cout<<"Enter the payLoadData"<<endl;
    cin>>payLoadData;

    int num;
    cout<<"Enter 1 for bit Stuffing and 2 for bit Unstuffing"<<endl;
    cin>>num;

    if(num==1){
        string newPayLoad = "";
        int ind = 0;
        int cnt = 0;

        while(ind<payLoadData.size()){
            if(payLoadData[ind]=='0'){
                cnt = 0;
                newPayLoad+=payLoadData[ind];
                ind++;
            }
            else{
                cnt++;
                if(cnt==6){
                    newPayLoad+='0';
                    cnt = 0;
                }
                newPayLoad+=payLoadData[ind];
                ind++;               
            }
        }

        cout<<newPayLoad<<endl;
    }

    else{
        string deStuffed = "";
        int cnt = 0;

        for(int i = 0;i<payLoadData.size();i++){
            if(payLoadData[i]=='0'){
                deStuffed+=payLoadData[i];
                cnt = 0;
            }
            else{
                cnt++;
                deStuffed+=payLoadData[i];
                if(cnt==5){
                    cnt = 0;
                    i++;
                }
            }
        }

        cout<<deStuffed<<endl;
    }

    return 0;
}