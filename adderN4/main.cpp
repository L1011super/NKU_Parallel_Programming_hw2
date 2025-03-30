#include <iostream>
#include<windows.h>
#include<stdlib.h>

using namespace std;
const int N=131072;
//¶şÖØÑ­»·  lgn
int a[N];

int main()
{

    int sum4;
    for(int i=0;i<N;i++){
        a[i]=rand()%100;
    }

    long long freq1,head1,tail1;
    QueryPerformanceFrequency((LARGE_INTEGER*)&freq1);
    QueryPerformanceCounter((LARGE_INTEGER*)&head1);
    for(int j=N;j>1;j/=2){
        for(int i=0;i<j/2;i++){
            a[i]=a[i*2]+a[i*2+1];
        }
    }
    sum4=a[0];
    QueryPerformanceCounter((LARGE_INTEGER*)&tail1);
    cout<<"func4:"<<(tail1-head1)*1000.0/freq1<<"ms"<<endl;

    cout<<sum4<<endl;
}
