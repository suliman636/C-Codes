#include <iostream>
using namespace std;
int* resizestack(int *stack, int oldsize){
	int newsize=+oldsize;
	int* temp=new int[newsize];
	for(int i=0;i<oldsize;i++){
		temp[i]=stack[i];
	}
	delete [] stack;
	return temp;
}

// stack function //
int Push(int* stack,int top,int value){
	
	stack[top]=value;
	            top++;
				return top;				
	

}

int Pop(int* stack,int top){
 if(top==0){
 
 cout<<"stack is emptey\n";
}
else{
	--top;
	cout<<stack[top]<<" pop from stack\n";
	stack[top]=0;
}
return top;
}

void Displaystack(int* stack,int top){
	if(top==0){
		cout<<"Stack is emptey\n";
	}
	else {
		for(int i=top-1;i>=0;i--){
			cout<<"stack array ["<<i<<"] :"<<stack[i]<<endl;
		}
	}
}

int* resizequeue(int *queue, int oldsize,int count){
	int newSize=oldsize+2;
	int* temp=new int[newSize];
	for(int i=0;i<count;i++){
		temp[i]=queue[i];
	}
	delete [] queue;
	return temp;
}

// Queue Fnction //

int Enqueue(int* queue,int rear, int value){
	queue[rear]=value;
	rear++;
	return rear;
}

int Dequeue(int* queue,int rear){
	if (rear==0){
		cout<<"queue is emptey\n";
	}
	else{
		cout<<"Dequeue :"<<queue[0]<<endl;
		for (int i=1;i<rear;i++){
		queue[i-1]=queue[i];
		}
		rear--;
		queue[rear]=0;
	}
	return rear;
}

void display(int *queue, int rear){
	if(rear==0){
		cout<<"Queue is emptey :\n";
	}
	else{
		for(int i=0; i<rear;i++){
			cout<<"que array ["<<i<<"]:"<<queue[i]<<endl;
		}
	}
}

int main(){
	int stacksize=2;
	int stacktop=0;
	int *stack=new int[stacksize];
	
	int qeuesize=2;
	int enqueuerear=0;
	int *queue=new int[qeuesize];
	int mainchoice=0;
	do{
		cout<<"1.Stack \n";
		cout<<"2.Queue \n";
		cout<<"3.Exit \n";
		cout<<"Enter choice ..\n";
		cin>>mainchoice;
		
		switch(mainchoice){
			case 1:{
			
			
				
				int choicestack=0;
				do{
					cout<<"---Stack Manue---\n";
					cout<<"1.Push\n";
					cout<<"2.Pop\n";
					cout<<"3.Display\n";
					cout<<"4.Return Manue\n";
					cin>>choicestack;
					switch(choicestack){
						case 1:{
						
							int value;
							cout<<"Enter value\n";
						cin>>value;
						if(stacktop==stacksize){
							stack=resizestack(stack,stacksize);
							stacksize +=2;
							cout<<"stack size increase to :"<<stacksize<<endl;
						}
							stacktop=Push(stack,stacktop,value);	
							break;
						}
							case 2:
								stacktop=Pop(stack,stacktop);
								break;
								
								case 3:
									Displaystack(stack,stacktop);
									break;
									
									case 4:
										cout<<"reurning Manue"<<endl;
										break;
										
										default:
											cout<<"Invalid choice \n";
								
					}
				}while(choicestack!=4);
				break;
			
			}
				case 2:
					{
					
					int queuechoice=0;
					do{
						cout<< "\n---Queue Manue---\n";
						cout<<"1.Enqueue\n";
						cout<<"2.Dequeue\n";
						cout<<"3.Display\n";
						cout<<"4.Returning Manue\n";
						cin>>queuechoice;
						switch(queuechoice){
							case 1:
								int value;
								cout<<"Enter value to enque \n";
								cin>>value;
								if (enqueuerear==qeuesize){
									queue=resizequeue(queue,qeuesize, enqueuerear);
								enqueuerear =+2;
								cout<<"queue size increas to "<<enqueuerear<<endl;	
								}
							enqueuerear=Enqueue(queue,enqueuerear,value);
							break;
							
							case 2:
							enqueuerear=Dequeue(queue,enqueuerear);
							break;	
							
							case 3:
							display(queue,enqueuerear);
							break;
							case 4:
								cout<<"Return  manue\n";
								break;
								default:
									cout<<"invalid choice !\n";
						}
					}while(queuechoice!=4);
					break;
				}
					case 3:
						cout<<"Exit"<<endl;
						break;
						
						default:
							cout<<"Invalid choice!\n";
							
					
		}
		
	} while(mainchoice!=3);
	delete [] stack;
	delete [] queue;
	return 0;
	}