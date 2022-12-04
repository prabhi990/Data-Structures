#include<iostream>
using namespace std;
struct complex
{
    int real;
    int img;
};
int main()
{
    struct complex c1={21,2};
    struct complex c2={2,21};
    struct complex c3;
    c3.real=c1.real+c2.real;
    c3.img=c1.img+c2.img;
    cout<<c3.real<<","<<c3.img;

 return 0;
}