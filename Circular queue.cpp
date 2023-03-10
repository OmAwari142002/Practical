#include<iostream>
#include<malloc.h>
using namespace std;
class test {
	public:
		int SIZE,Queue[3],front=-1,rear=-1,element;
		test() {
			SIZE=3;
		}
		void enqueue() {
			if((front==0 && rear==SIZE-1)||(front==rear+1))
			cout<<"\nCircular queue is full insertion is not possible\n";
			else {
				cout<<"\nEnter the element to be inserted :";
				cin>>element;
				if(rear==SIZE-1 && front!=0)
				rear==-1;
				Queue[++rear]=element;
				if(front==-1)
				front=0;
			}
		}
		void dequeue() {
			if(front==-1 && rear==-1)
			cout<<"\nCircular queue is empty, deletion is not possible\n";
			else {
				cout<<"\nDeleted element :"<<Queue[front++];
				if(front==SIZE)
				front=0;
				if(front-1==rear)
				front=rear=-1;
			}
		}
		void display() {
			if(front==-1)
			cout<<"\nCircular queue element is empty!\n";
			else {
				int i=front;
				cout<<"\nCircular queue elements are :\n";
				if(front<=rear) {
					while(i<=rear)
					cout<<"\t"<<Queue[i++];
				}
				else {
					while(i<=SIZE-1)
					cout<<"\t"<<Queue[i++];
					i=0;
					while(i<=rear)
					cout<<"\t"<<Queue[i++];
				}
			}
		}
};
int main() {
	int choice;
	test obj;
	while(1) {
		cout<<"\n1)Enqueue\n2)Dequeue\n3)Display\n4)Exit\n";
		cout<<"Enter your choice :";
		cin>>choice;
		switch(choice) {
			case 1:
				obj.enqueue();
				break;
			case 2:
				obj.dequeue();
				break;
			case 3:
				obj.display();
				break;
			case 4:
				exit(0);
			default:
				cout<<"\nInvalid choice!\n";
		}
	}
}
