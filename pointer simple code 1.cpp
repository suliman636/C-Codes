#include <iostream>
using namespace std;
int main(){
	int v1;
	int* ptr1=&v1;
	*ptr1=47;
	cout<<"Address of v1 :"<<ptr1<<endl;
	cout<<"value of v1 :"<<*ptr1<<  v1<<endl;
	
}