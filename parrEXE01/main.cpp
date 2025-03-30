#include <iostream>
#include<stdlib.h>
#include <windows.h>

using namespace std;
const int N=10240;
double matrix[N][N],vect[N];

int main()
{
    //考虑是否多次实验取平均值，或者rebuild 自己手动运行多次

   long long head ,tail,freq,head2 ,tail2,freq2;
    for(int i=0;i<N;i++){
             for(int j=0;j<N;j++){
                matrix[i][j]=rand()%100;
             }
    }
    double result1[N];
    double result2[N];

    for(int i=0;i<N;i++){
        vect[i]=rand()%100;
        result1[i]=0;
        result2[i]=0;

    }

    //cache优化算法
    QueryPerformanceFrequency((LARGE_INTEGER*)&freq2);
    QueryPerformanceCounter((LARGE_INTEGER*)&head2);
    for(int j=0;j<N;j++){
        for(int i=0;i<N;i++){
            result2[i]+=matrix[j][i]*vect[j];
        }
    }


    QueryPerformanceCounter((LARGE_INTEGER*)&tail2);
    cout<<"Col2:"<<(tail2-head2)*1000.0/freq2<<"ms"<<endl;

//传统算法
    QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
    QueryPerformanceCounter((LARGE_INTEGER*)&head);

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
                result1[i]+=vect[j]*matrix[j][i];
        }
    }
    QueryPerformanceCounter((LARGE_INTEGER*)&tail);
    cout<<"Col:"<<(tail-head)*1000.0/freq<<"ms"<<endl;

}
