#include <iostream>
using namespace std;

int main(){
    int a[4],score=0;
    for(int i=0;i<4;i++){
        cin>>a[i];
        if(a[i]>=10)
            score++;
    }

    cout<<score;


}

