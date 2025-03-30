#include <iostream>
#include<windows.h>
#include<stdlib.h>

using namespace std;
const int N=131072;
int a[N];
int main()
{
    int sum1=0;
    for(int i=0;i<N;i++){
        a[i]=rand()%100;
    }

    long long freq1,head1,tail1;
    QueryPerformanceFrequency((LARGE_INTEGER*)&freq1);
    QueryPerformanceCounter((LARGE_INTEGER*)&head1);
    for(int i=0;i<N;i++){
        sum1+=a[i];
    }
    QueryPerformanceCounter((LARGE_INTEGER*)&tail1);
    cout<<"func1:"<<(tail1-head1)*1000.0/freq1<<"ms"<<endl;

    cout<<sum1<<endl;
}
