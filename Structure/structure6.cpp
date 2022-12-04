#include<iostream>
using namespace std;
struct time
{
    int hr;
    int min;
    int sec;
};
int main()
{
    struct time t1={7,31,54};
    struct time t2={2,55,36};
    struct time t3;
    int s=(t1.sec+t2.sec);
    t3.sec=s%60;
    int m=(t1.min+t2.min)+(s/60);
    t3.min=m%60;
    int h=(t1.hr+t2.hr)+(m/60);
    t3.hr=h%24;
    cout<<t3.hr<<":"<<t3.min<<":"<<t3.sec;
 return 0;
}