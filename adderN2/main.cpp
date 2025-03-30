#include <iostream>
#include<windows.h>
#include<stdlib.h>

using namespace std;
const int N=131072;
int a[N];
//分两部分计算
int main()
{

    int sum2=0;
    int sumx1=0;
    int sumx2=0;
    for(int i=0;i<N;i++){
        a[i]=rand()%100;
    }

    long long freq2,head2,tail2;
    QueryPerformanceFrequency((LARGE_INTEGER*)&freq2);
    QueryPerformanceCounter((LARGE_INTEGER*)&head2);
    for(int i=0;i<N;i+=2){
        sumx1+=a[i];
        sumx2+=a[i+1];
    }
    sum2=sumx1+sumx2;
    QueryPerformanceCounter((LARGE_INTEGER*)&tail2);

    cout<<"func2:"<<(tail2-head2)*1000.0/freq2<<"ms"<<endl;

    cout<<sum2<<endl;
}
