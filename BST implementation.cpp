//PROGRAM TO PERFORM BASIC OPERATIONS ON A BINARY SEARCH TREE (BST)
#include<bits/stdc++.h>
using namespace std;
struct tree{
    int info;
	struct tree *right,*left;
};
void insert(struct tree **ptr,int item){
    if(*ptr==NULL){
        *ptr=(struct tree *)malloc(sizeof(struct tree));
        (*ptr)->left=(*ptr)->right=NULL;
        (*ptr)->info=item;
        return;
    }
    else {
        if(item<(*ptr)->info){
            insert(&((*ptr)->left),item);
            }
        else{
            insert(&((*ptr)->right),item);
            }
            return;
        }
}
void delete_tree(struct tree **ptr,int item){
    struct tree *move,*back,*temp;
    if(*ptr==NULL){
        cout<<"\nEmpty tree..............\n";
        return;
        }
    else{ 
        move=*ptr;
        back=move;
        while(move->info!=item){
            back=move;
            if(item<move->info){ 
                move=move->left;
            }
        else{
            move=move->right;
            }
        }
        if(move->left!=NULL && move->right!=NULL){
            temp=move->right;
            while(temp->left!=NULL){
                back=temp;
                temp=temp->left;
                }
            move->info=temp->info;
            move=temp;
        }
        if(move->left==NULL && move->right==NULL){
            if(back->right==move){ 
                back->right=NULL;
            }
            else{
                back->left=NULL;
                }
            free(move);
            return;
        }
        if(move->left==NULL && move->right!=NULL){
            if(back->left==move){
                back->left=move->right;
            }
            else{
                back->right=move->right;
            }
            free(move);
            return;
        }
        if(move->left!=NULL && move->right==NULL){
            if(back->left==move){
                back->left=move->left;
            }
        else{
            back->right=move->left;
            }
        free(move);
        return;
        }
    }
}
void inorder(struct tree *ptr){
    struct tree *move;
    move=ptr;
    if(move!=NULL){ 
        inorder(move->left);
        cout<<move->info<<" ";
        inorder(move->right);
    }
    else
        return;
}
 
int main(){
    struct tree *root=NULL;
    int item,ch,order;
	char choice,ch1;
	do{
		cout<<"\n____________Tree MENU_______________\n\n";
        cout<<"1.Insert.\n";
        cout<<"2.Delete.\n";
        cout<<"3.Traversal.\n";
        cout<<"4.Exit.\n"; 
        cout<<"\nEnter your choice   :         ";
        cin>>ch;
        switch(ch){
            case 1: cout<<"\nEnter the element to be inserted   :         ";
                    cin>>item;
                    insert(&root,item);
                    break;
            case 2: cout<<"\nEnter the element to be deleted    :         ";
                    cin>>item;
                    delete_tree(&root,item);
                    break;
        	case 3: inorder(root);
        			break;
                default: exit(0);
        }
        fflush(stdin); 
    }while(ch!=4);
}
