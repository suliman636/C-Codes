#include <iostream>
using namespace std;
int main()
{
int v1 = 20;
int* ptr1;
ptr1= &v1;
v1 = v1 + 10;
cout<< &ptr1 << endl;
cout<< ptr1 << endl;
cout<< &v1 << endl;
cout<< v1 << endl;
return 0;
}