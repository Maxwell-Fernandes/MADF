#include<stdio.h>
#include<stdlib.h>
typedef enum {True,False} boolean;

struct node{
	int info;
	boolean rthread;
	struct node* right;
	boolean lthread;
	struct node* left;
};

struct node *in_succ(struct node *ptr){

	if(ptr->rthread==True){
	return ptr->right;
	}
	else{
	ptr=ptr->right;
	while(ptr->lthread==False){
		ptr=ptr->left;
	}
	return ptr;
	}
}

struct node *in_pre(struct node *ptr){
if(ptr->lthread==True){
return ptr->left;
}
else{
ptr=ptr->left;
while(ptr->rthread==False)
	ptr=ptr->right;
return ptr;
}
}

void inorder(struct node *root){
if (root==NULL){
printf("tree is empty\n");
return;
}
struct node *ptr;
ptr=root;
while(ptr->lthread==False){
ptr=ptr->left;
}
while(ptr!=NULL){
printf("%d ",ptr->info);
ptr=in_succ(ptr);
}
printf("\n");
}

void preorder(struct node *root){
if(root==NULL){
printf("Tree is empty\n");
return ;
}
struct node *ptr;
ptr=root;
while(ptr!=NULL){
printf("%d ",ptr->info);
if(ptr->lthread==False)
	ptr=ptr->left;
else if(ptr->rthread==False)
	ptr=ptr->right;
else{
while(ptr!=NULL&&ptr->rthread==True)
ptr=ptr->right;
if(ptr!=NULL)
	ptr=ptr->right;
}
}
printf("\n");
}

struct node *insert(struct node *root,int data){
struct node *temp,*par,*ptr;
temp=(struct node *)malloc(sizeof(struct node));
temp->info=data;
temp->rthread=True;
temp->lthread=True;
boolean found=False;

if(root==NULL){
temp->left=NULL;
temp->right=NULL;
root=temp;
return root;
}
ptr=root;
par=NULL;
while(ptr!=NULL){
par=ptr;
if(data==ptr->info){
printf("Duplicate key found\n");
return root;
}
if(data<ptr->info){
if(ptr->lthread==False)
	ptr=ptr->left;
else
	break;
}
else if (data>ptr->info){
if(ptr->rthread==False)
	ptr=ptr->right;
else
	break;
}
}

if(data<par->info){
temp->left=par->left;
temp->right=par;
par->lthread=False;
par->left=temp;
}
else{
temp->left=par;
temp->right=par->right;
par->rthread=False;
par->right=temp;
}
return root;
}

struct node *delete(struct node *root,int data){
boolean found = False;
struct node *ptr,*par;
if(root==NULL){
printf("Tree is empty\n");
return root ;
}
 ptr=root;
 par=NULL;
 
 while(ptr!=NULL){
 if(data==ptr->info){
 found=True;
 break;
 }
 par=ptr;
 if(data<ptr->info){
 if(ptr->lthread==False)
 	ptr=ptr->left;
 else
 	break;
 }else{
 if(ptr->rthread==False)
 	ptr=ptr->right;
 }
 }
 
if(!found){
printf("Key not found\n");
return root;
}

if(ptr->lthread==True && ptr->rthread==True){
	if(par==NULL){
	free(ptr);
	root=NULL;
	}else if(ptr==par->left){
	par->lthread=True;
	par->left=ptr->left;
	free(ptr);
	}
	else{
	par->rthread=True;
	par->right=ptr->right;
	free(ptr);
	
	}
}
else if(ptr->lthread==False || ptr->rthread==False){
if(ptr->lthread==False){
	struct node *pred=in_pre(ptr);
	int temp=ptr->info;
	ptr->info =pred->info;
	pred->info=temp;
	root=delete(root,pred->info);
}
else{
struct node *succ=in_succ(ptr);
int temp=ptr->info;
ptr->info=succ->info;
root=delete(root,succ->info);
}
}

return root;

}



int main(){
struct node *root=NULL;
int data,n;
printf("Enter root node\n");
scanf("%d",&data);
root=insert(root,data);
printf("Enter the number of nodes you want to enter\n");
scanf("%d",&n);
for(int i=0;i<n;i++){
printf("Enter data:\n");
scanf("%d",&data);
root=insert(root,data);
}
inorder(root);
preorder(root);
printf("Enter element you want to delete\n");
scanf("%d",&data);
root=delete(root,data);
inorder(root);
preorder(root);

return 0;
}

