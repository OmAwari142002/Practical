#include<iostream>
#include<string.h>
using namespace std;
int const size=3;

struct student {
	int rollno;
	char stdname[20];
	float SGPA;
};
void accept(struct student list[size]);
void display(struct student list[80]);
void insertionSort(struct student list[80]);
void linearSearch(struct student list[80]);


int main() {
	int ch,i;
	struct student data[20];
	accept(data);
	cout<<"1)Insertion sort\n";
	cout<<"2)Linear search\n";
	cout<<"Enter your choice :";
	cin>>ch;
	switch(ch) {
		case 1:
		    insertionSort(data);
			display(data);
			break;
		case 2:
			linearSearch(data);
			break;
		default:
			cout<<"Invalid choice";
	}
}
void accept(struct student list[size]) {
	int i;
	for(i=0;i<size;i++) {
		cout<<"Enter rollno, name and SGPA :";
		cin>>list[i].rollno>>list[i].stdname>>list[i].SGPA;
	}
}
void display(struct student list[80]) {
	int i;
	cout<<"Rollno\nName\nSGPA";
	for(i=0;i<size;i++) {
		cout<<"\n"<<list[i].rollno<<"\t"<<list[i].stdname<<"\t"<<list[i].SGPA;
	}
}
void insertionSort(struct student list[80]) {
	int k,j;
	struct student temp;
	for(k=1;k<size;k++) {
		temp=list[k];
		j=k-1;
		while(strcmp(list[j].stdname,temp.stdname)>0&&j>=0) {
			list[j+1]=list[j];
			--j;
		}
		list[j+1]=temp;
	}
}
void linearSearch(struct student list[size]) {
	float SGPA;
	int i;
	cout<<"Enter SGPA :";
	cin>>SGPA;
	cout<<"\nRollno\nName\nSGPA\n";
	for(i=0;i<size;i++) {
		if(SGPA=list[i].SGPA)
		cout<<"\n"<<list[i].rollno<<"\t"<<list[i].stdname;
		else {
			cout<<"Element not in list!";
		}
	}
}

