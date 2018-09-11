#include<iostream>
using namespace std;
struct node{
	int data;
	struct node *left,*right;
};
struct node *root=NULL;
void insert(int data){
	node *p=new node;
	p->data=data;
	p->left=NULL;
	p->right=NULL;
	node *ptr=root;
	if(root==NULL){
		root=p;
	}
	while(ptr!=NULL){
		if(ptr->data<data) ptr=ptr->left;
		else if(ptr->data>data) ptr=ptr->right;
		else{
			cout<<"Value already exit\n";
			return;
		}
	}
	ptr=p;
}
void deletion(int data){
	
}
void search(int data){
	node *ptr=root;
	while(true){
		if(ptr==NULL){
			cout<<"Not found\n";
			break;
		}
		if(ptr->data==data){
			cout<<"Found\n";
			break;
		}
		else if(ptr->data<data) ptr=ptr->left;
		else if(ptr->data>data) ptr=ptr->right;
	}
}
int main(){
	cout<<"The program for insertion,deletion and search"<<endl;
	int choice=0;
	while(choice!=4){
		cout<<"Enter the choices\n1.Insertion\n2.Deletion\n3.Search\n4.Exit\n";
		cin>>choice;
		if(choice==1){
			cout<<"Insert the no to be inserted into the tree\n";
			int data;
			cin>>data;
			insert(data);
		}
		else if(choice==2){
			cout<<"Enter the value of node to be deleted\n";
			int data;
			cin>>data;
			deletion(data);
		}
		else if(choice==3){
			cout<<"Enter the data to be searched in the tree\n";
			int data;
			cin>>data;
			search(data);
		}
		else if(choice!=4){
			cout<<"Insert the correct choice\n";
		}
	}
}
