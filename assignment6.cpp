#include<iostream>
#include<cstdlib>
#define max 65536
using namespace std;
class node {
	public:
		int key;
		node *left,*right;
		bool leftthread,rightthread;
};
class tree {
	private:
		node *root;
	public:
		tree() {
			root=new node();
			root->right=root->left=root;
			root->leftthread=true;
			root->key=max;
		}
		void insert(int key) {
			node *p=root;
			for(;;) {
				if(p->key <key) {
					if(p->rightthread)
					break;
					p=p->right;
				}
				else if(p->key >key) {
					if(p->leftthread)
					break;
					p=p->left;
				}
				else {
					return;
				}
			}
			node *temp=new node();
			temp->key=key;
			temp->rightthread=temp->leftthread=true;
			if(p->key <key) {
				temp->right=p->right;
				temp->left=p;
				p->right=temp;
				p->rightthread=false;
			}
			else {
				temp->right=p;
				temp->left=p->left;
				p->left=temp;
				p->leftthread=false;
			}
		}
		void del(int key) {
			node *dest=root->left,*p=root;
			for(;;) {
				if(dest->key<key) {
					if(dest->rightthread)
					return ;
					p=dest;
					dest=dest->left; 
				}
				else {
					break;
				}
			}
			node *target=dest;
			if(!dest->rightthread && !dest->leftthread) {
				p=dest;
				target=dest->left;
				while(!target->rightthread) {
					p=target;
					target=target->right;
				}
				dest->key=target->key;
			}
			if(p->key>=target->key) {
				if(target->rightthread && target->leftthread) {
					p->left=target->left;
					p->leftthread=true;
				}
				else if(target->rightthread) {
					node *largest=target->left;
					while(!largest->rightthread) {
						largest=largest->right;
					}
					largest->right=p;
					p->left=target->left;
				}
				else {
					node *smallest=target->right;
					while(!smallest->leftthread) {
						smallest=smallest->left;
					}
					smallest->left=target->left;
					p->left=target->right;
				}
			}
			else {
				if(target->rightthread && target->leftthread) {
					p->right=target->right;
					p->rightthread=true;
				}
				else if(target->rightthread) {
					node *largest=target->left;
					while(!largest->rightthread) {
						largest=largest->right;
					}
					largest->right=target->right;
					p->right=target->left;
				}
				else {
					node *smallest=target->right;
					while(!smallest->leftthread) {
						smallest=smallest->left;
					}
					smallest->left=p;
					p->right=target->right;
				}
			}
		}
		void print() {
			node *temp=root, *p;
			for(;;) {
				p=temp;
				temp=temp->right;
				if(!p->rightthread) {
					while(!temp->leftthread) {
						temp=temp->left;
					}
				}
				if(temp==root)
				break;
				cout<<temp->key<<" ";
				}
				cout<<endl;
			}
		};
		void preorder(node *root) {
			node *curr=root;
			while(curr!=NULL) {
				cout<<curr->key;
				if(curr->left!=NULL) {
					curr=curr->left;
				}
				else if(curr->rightthread==1)
				curr=curr->right;
				else {
					while(curr->right!=NULL && curr->rightthread==0)
					curr=curr->right;
					if(curr->right==NULL)
					break;
				}
			}
		}
		int main() {
			tree t;
			int ch,val;
			node *r=NULL;
			do {
				cout<<"1)Insert\n2)Delete\n3)Preorder\n4)Inorder\n5)Exit\n";
				cout<<"Enter your choice :";
				cin>>ch;
				switch(ch) {
					case 1:
						cout<<"Enter element :";
						cin>>val;
						t.insert(val);
						break;
					case 2:
						cout<<"Enter element :";
						cin>>val;
						t.del(val);
						break;
					case 3:
						cout<<"\nPreorder=";
						preorder(r);
						t.print();
						break;
					case 4:
						cout<<"Inorder=";
						t.print();
						break;
					case 5:
						exit(0);
						break;
					default:
						cout<<"Invalid choice";
						break;
				}
			}
			while(ch<=4 && ch>=1);
			return 0;
		};
    

