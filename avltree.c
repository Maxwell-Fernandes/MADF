#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *left;
struct node *right;
int height;
};

int max(int a,int b){
return a>b?a:b;
}

int height(struct node *root){
if(root==NULL)
        return 0;
return height(root->left)-height(root->right);
}


int getbalance(struct node *root){
if(root==NULL)
	return 0;
return height(root->left)-height(root->right);
}


struct node *newnode(int data){
struct node *temp=(struct node *)malloc(sizeof(struct node));
temp->data=data;
temp->right=NULL;
temp->left=NULL;
temp->height=1;
return temp;
}

struct node *rotateright(struct node *root){
struct node *x=root->left;
struct node *y=x->right;

x->right=root;
root->left=y;

y->height=max(height(y->left),height(y->right))+1;
x->height=max(height(x->right),height(x->left))+1;

return x;

}

struct node *rotateleft(struct node *root){
struct node *x=root->right;
struct node *y=x->left;

root->right=y;
x->left=root;

y->height=max(height(y->left),height(y->right))+1;
x->height=max(height(x->right),height(x->left))+1;

return x;
}

struct node *insert(struct node *root,int data){
if(root==NULL){
return newnode(data);
}

if(data<root->data){
root->left=insert(root->left,data);
}
else if(data>root->data)
	root->right=insert(root->right,data);
else
	return root;

root->height=max(height(root->right),height(root->left))+1;

int balance=getbalance(root);

if(balance>1&&data<root->left->data)
	return rotateright(root);
else if(balance<-1&&data>root->right->data)
	return rotateleft(root);
else if(balance>1&&data>root->left->data){
	root->left=rotateleft(root->left);
	return rotateright(root);
}else if(balance<-1&&data<root->right->data){
	root->right=rotateright(root->right);
	return rotateleft(root);
}

return root;
}

struct node *findmin(struct node *root){
if(root->left=NULL)
	return root;
return findmin(root->left);
}


struct node *delete(struct node *root,int target){

if(root==NULL){
printf("Tree is empty");
return root;
}
else if(target<root->data){
root->left=delete(root->left,target);
}else if(target>root->data){
root->right=delete(root->right,target);
}
else
{	struct node *temp;
	if(root->left==NULL){
	temp=root;
	root=root->right;
	free(temp);
	}else if(root->right=NULL){
	temp=root;
	root=root->left;
	free(temp);
	}else
	{
		temp=findmin(root->right);
		root->info=temp->info;
		root->right=delete(root->right,temp->info);
	}
}

if (root==NULL)
{
	return root;
}

int balance = getbalance(root);

root->height= max(height(root->right),height(root->left))+1;

if(balance>1&&getbalance(root->left)>0)
	return rotateright;
else if (balance>1&&getbalance(root->left)<0)
{
	root->left=leftrotate(root->left);
	return rotateright(root);
}else if (balance<1&&getbalance(root->right)<0)
{
	return rotateleft(root);
}
else if (balance<1&&getbalance(root->right)>0)
{
	root->right=rotateright(root->right);
	return rotateleft(root);
}
return root;
}


void inorder(struct node *root){
if(root==NULL)
	return ;
inorder(root->left);
printf("%d ",root->data);
inorder(root->right);
}


int search(struct node *root,int target){
if(root==NULL){
	printf("Tree is empty\n");
	return -1;
}
if(root->data==target)
	return 1;
if(target<root->data)
	return search(root->left);
else
	return search(root->right);
}







int main(){

struct node *root=NULL;
printf("Enter root");
int data ;
scanf("%d",&data);
insert(root,data);
insert(root,);
insert(root,data);
insert(root,data);
insert(root,data);
insert(root,data);
insert(root,data);
insert(root,data);
insert(root,data);
return 0;
}







