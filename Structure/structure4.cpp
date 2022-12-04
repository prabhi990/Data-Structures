#include<iostream>
using namespace std;
struct height
{
    int feet;
    int inch;
};
int main()
{
    struct height h1={13,11};
    struct height h2={7,8};
    struct height h3;
    int i=h1.inch+h2.inch;
    h3.inch=i%12;
    int f=(h1.feet+h2.feet) + (i/12);
    h3.feet=f;
    cout<<h3.feet<<","<<h3.inch;
 return 0;
}