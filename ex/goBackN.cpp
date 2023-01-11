#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main(){
    
    int totalFrames;
    cout<<"Enter the total Number of frames"<<endl;
    cin>>totalFrames;

    int seqBitSize;
    cout<<"Enter the sequence bit size of frames"<<endl;
    cin>>seqBitSize;

    int NumberOfMaxFrames;
    NumberOfMaxFrames = pow(2,seqBitSize);

    int currFrame = 0;

    while(currFrame<=totalFrames){

        int end = min(currFrame+NumberOfMaxFrames,totalFrames);
        for(int i = currFrame;i<=end;i++){
            cout<<"Sending Frame number "<<i<<" from server"<<endl;
        }

        int err = 0;
        cout<<"If all frames recived by receiver then enter 0 else Enter 1"<<endl;
        cin>>err;

        if(err){
            int frNo;
            cout<<"Enter the frame number to be sent again"<<endl;
            cin>>frNo;
            int crctSent = frNo-currFrame;
            currFrame = frNo;
            cout<<"We are currently in frame number "<<currFrame<<" number of frames sent with acknowledgement are "<<crctSent<<endl;
        }

        else{
            currFrame+=NumberOfMaxFrames;
            currFrame = min(totalFrames,NumberOfMaxFrames+currFrame);
            cout<<"We are currently in frame number "<<currFrame<<" number of frames sent with acknowledgement are "<<NumberOfMaxFrames<<endl;
        }
    }

    return 0;
}
