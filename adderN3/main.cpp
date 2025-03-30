#include <iostream>
#include<windows.h>
#include<stdlib.h>

using namespace std;
const int N=131072;
//使用递归函数方式 简单但是递归调用开销大
int a[N];
void func(int n){
    if(n==1)
        return;
    else{
        for(int i=0;i<N/2;i++)
            a[i]+=a[n-i-1];
        n/=2;
        func(n);
    }
}
int main()
{
    int sum3;
    for(int i=0;i<N;i++){
        a[i]=rand()%100;
    }
    long long freq1,head1,tail1;
    QueryPerformanceFrequency((LARGE_INTEGER*)&freq1);
    QueryPerformanceCounter((LARGE_INTEGER*)&head1);
    func(N);
    sum3=a[0];
    QueryPerformanceCounter((LARGE_INTEGER*)&tail1);
    cout<<"func3:"<<(tail1-head1)*1000.0/freq1<<"ms"<<endl;
    cout<<sum3<<endl;
}
