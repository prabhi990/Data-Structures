#include<iostream>
using namespace std;
struct student
{
    int rollno;
    char section;
    float percentage;
    int mobile;
};
int main()
{
    struct student S={96,'B',85.63,785586};
    cout<<S.rollno<<endl<<S.section<<endl<<S.percentage<<"%"<<endl<<S.mobile;    
 return 0;
}