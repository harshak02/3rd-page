#include<iostream>
#include<vector>
using namespace std;

int main(){
    
    int bucketSize;
    cout<<"Enter the bucket Size"<<endl;
    cin>>bucketSize;

    int packetSize;
    cout<<"Enter the packet Size"<<endl;
    cin>>packetSize;

    int packetNum;
    cout<<"Enter the packet Number"<<endl;
    cin>>packetNum;

    int InputFlow;
    cout<<"Enter the Input Flow"<<endl;
    cin>>InputFlow;

    int OutputFlow;
    cout<<"Enter the Output Flow"<<endl;
    cin>>OutputFlow;

    int currFlow = 0;
    int currPacket = 0;
    int freeSpace = bucketSize;
    int seconds = 1;

    while(currPacket<=packetNum){

        currFlow = InputFlow*packetSize;
        if(currFlow<=freeSpace){
            freeSpace-=currFlow;
            currPacket+=InputFlow;
            cout<<"Added packets at Input Flow at "<<seconds<<" time filled space "<<bucketSize-freeSpace<<" freeSpace is "<<freeSpace<<endl;
        }
        else{
            int flag = 1;
            if(packetSize>freeSpace){
                cout<<"Packets are discarding current time is "<<seconds<<endl;
            }
            else{
                for(int i =0;i<InputFlow;i++){
                    if(freeSpace<packetSize*i+currFlow){
                        currPacket+=i;
                        freeSpace-=(i*packetSize);
                        cout<<"Added packets at "<<i<<" Input Flow at "<<seconds<<" time filled space "<<bucketSize-freeSpace<<" freeSpace is "<<freeSpace<<endl;
                        break;
                    }
                }             
            }
        }
        freeSpace+=(OutputFlow*packetSize);
        cout<<"Outflowing packets at Output Flow at "<<seconds<<" time filled space "<<bucketSize-freeSpace<<" freeSpace is "<<freeSpace<<endl;
        seconds++;
    }

    return 0;
}