#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
struct treenode {
	int data;
	treenode *left;
	treenode *right;
};
treenode *insert(treenode *node,int data) {
	if(node==NULL) {
		treenode *temp;
		temp=new treenode;
		temp->data=data;
		temp->left=temp->right=NULL;
		return temp;
	}
	if(data>(node->data)) {
		node->right=insert(node->right,data);
	}
	else if(data<(node->data)) {
		node->left=insert(node->left,data);
	}
	return node;
}
treenode *min(treenode *node) {
	if(node==NULL) {
		return NULL;
	}
	if(node->left)
	return min(node->left);
	else
	return node;
}
treenode *max(treenode *node) {
	if(node==NULL) {
		return NULL;
	}
	if(node->right)
	return max(node->right);
	else
	return node;
}
treenode *del(treenode *node,int data) {
	treenode *temp;
	if(node==NULL) {
		cout<<"Element not found";
	}
	else if(data<(node->data)) {
		node->left=del(node->left,data);
	}
	else if(data>(node->data)) {
		node->right=del(node->right,data);	
	}
	else {
		if(node->right && node->left) {
			temp=min(node->right);
			node->data=temp->data;
			node->right=del(node->right,temp->data);
		}
	}
	return node;
}
treenode *find(treenode *node,int data) {
	if(node==NULL) {
		return NULL;
	}
	if(data>(node->data)) {
		return find(node->right,data);
	}
	else if(data<(node->data)) {
		return find(node->left,data);
	}
	else {
		return node;
	}
}
void inorder(treenode *node) {
	if(node==NULL) {
		return;
	}
	inorder(node->left);
	cout<<node->data<<" ";
	inorder(node->right);
}
void leaf(treenode *node) {
	if(node==NULL) {
		return;
	}
	inorder(node->left);
	if(node->right==NULL && node->left==NULL) {
		cout<<node->data<<" ";
	}
	inorder(node->right);
}
void preorder(treenode *node) {
	if(node==NULL) {
		return;
	}
	cout<<node->data<<" ";
	preorder(node->left);
	preorder(node->right);
}
void postorder(treenode *node) {
	if(node==NULL) {
		return;
	}
	postorder(node->left);
	postorder(node->right);
	cout<<root->data;
}
int main() {
	treenode *root=NULL,*temp;
	int ch;
	while(true) {
		cout<<"\n1)Insert :";
		cout<<"\n2)Delete :";
		cout<<"\n3)Inorder :";
		cout<<"\n4)Preorder :";
		cout<<"\n5)Postorder :";
		cout<<"\n6)Search :";
		cout<<"\n7)Display leaf node :";
		cout<<"\n8)Exit\n";
		cout<<"Enter your choice :";
		cin>>ch;
		switch(ch) {
			case 1:
				cout<<"\nEnter element to be inserted :";
				cin>>ch;
				root=insert(root,ch);
				cout<<ch<<" "<<"Inserted :";
				break;
			case 2:
				cout<<"\nEnter element to be deleted :";
				cin>>ch;
				root=del(root,ch);
				cout<<ch<<" "<<"deleted";
				break;
			case 3:
				cout<<"\nInorder traversal :";
				inorder(root);
				break;
			case 4:
				cout<<"\nPreorder traversal :";
				preorder(root);
				break;
			case 5:
				cout<<"\nPostorder traversal :";
				postorder(root);
				break;
			case 6:
				cout<<"\nEnter element to be searched :";
				cin>>ch;
				temp=find(root,ch);
				if(temp==NULL) {
					cout<<"Element not found";
				}
				else {
					cout<<"Element found";
				}
				break;
			case 7:
				leaf(root);
				break;
			case 8:
				exit(0);
				break;
			default:
				cout<<"Invalid choice";
				break;
		}
	}
	return 0;
}
