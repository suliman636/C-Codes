#include <iostream>
using namespace std;
void sotnumber(int* ,int*);
int main (){
	int n1,n2;
	cout<<"enter firt number :";
	cin>>n1;
	cout<<endl;
		cout<<"enter second number :";
	cin>>n2;
	cout<<endl;
	cout<<"number befor sorting :"<<n1<<"  :"<<n2<<endl;
	
	sotnumber(&n1, &n2);
		cout<<"number after sorting :"<<n1<<"  :"<<n2<<endl;
}
void sotnumber(int* n1 ,int* n2){

int temp;
if(n1>n2){
	temp=*n1;
	*n1=*n2;
	*n2=temp;
}
}