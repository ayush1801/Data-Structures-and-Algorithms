#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct tree{
int value;
struct tree * left;
struct tree * right;
int bal;
}tree;

tree * parent(int val,tree * root);
tree * add(tree * node,tree * root)
{
//	printf("value  %d bal  %d \n",node->value,node->bal);	
	if(root==NULL)
	{	
		return node;
	}
	tree * x=root;
	tree * y=root;
	while(x!=NULL)
	{
		y=x;
		if(node->value>=x->value)
		{	
			x->bal++;
			//printf(" value %d bal %d\n",x->value,x->bal);
			x=x->right;
		}
		else
		{
			x->bal--;
			//printf(" value %d bal %d\n",x->value,x->bal);
			x=x->left;
		}
	//	printf(" value %d bal %d\n",node->value,node->bal);
	}
	if(node->value>=y->value) y->right=node;
	else y->left=node;
	return root;
}

tree * find(int val,tree * root)
{

	tree * x=root;
	while(x!=NULL)
	{
		if(val==x->value) return x;
		else if(val>x->value) x=x->right;
		else x=x->left;
	}
	return NULL;
}

tree * tree_min(tree * root)
{
	while(root->left !=NULL)
	{
		root=root->left;
	}
	return root;
}

tree * tree_max(tree * root)
{
	while(root->right !=NULL)
	{
		root=root->right;
	}
	return root;
}

tree * Tree_Succ(tree * node,tree * root)
{
	if(node->right!=NULL) return tree_min(node->right);
	tree * succ=NULL;
	tree * x=root;
	while(x!=node)
	{
		if(node->value<x->value) 
		{
			succ=x;
			x=x->left;
		}
		else x=x->right;
	}
	return succ;
}

tree * Tree_Pred(tree * node,tree * root)
{
	if(node->left!=NULL) return tree_max(node->left);
	tree * pred=NULL;
	tree * x=root;
	while(x!=node)
	{
		if(node->value>x->value)
		{
			pred=x;
			x=x->right;
		}
		else x=x->left;
	}
	return pred;
}
		
			
void Inorder_Traversal(tree * root,tree * proot )
{
	if(root==NULL) return;
	Inorder_Traversal(root->left,proot);
	printf("value %d ",root->value);
	tree * par=parent(root->value,proot);
	if(par!=NULL) printf(" parent value %d \n",par->value);
//	node=Tree_Pred(root,proot);
//	if(node!=NULL) printf(" Pred value %d  bal %d\n",node->value,node->bal); */
	Inorder_Traversal(root->right,proot);
	
}
void  Inorder_TraversalK1(tree * root,int K,int* i)
{	
	if(root==NULL) return;
	else
	{
	Inorder_TraversalK1(root->left,K,i);
	if((*i)++==K) printf( " %d smallest value is : %d ",K,root->value); 
	if((*i)<=K) Inorder_TraversalK1(root->right,K,i);
	}
}

tree * Inorder_TraversalK2(tree * root,int K,int *i)
{
	if(root==NULL) return NULL; //base condition
	tree * left=Inorder_TraversalK2(root->left,K,i); //find in the left subtree
	if(left!=NULL) return left; //if found return bro
	if((*i)++==K) return root; //see whether this root is the target
	return Inorder_TraversalK2(root->right,K,i);//otherwise check in the right sub tree
}
	
void  RangeQuery(tree * root,int k1,int k2)
{
	if(root==NULL) return;
	if(root->value>k2) RangeQuery(root->left,k1,k2);
	else if(root->value<k1) RangeQuery(root->right,k1,k2);
	else 
	{
		RangeQuery(root->left,k1,root->value);
		printf(" root k1..k2 %d\n",root->value);
		RangeQuery(root->right,root->value,k2);
	}
}	
	
tree * parent(int val,tree * root)
{
	if(val==root->value) return NULL;
	if(find(val,root)==NULL) return NULL;
	tree * x=root;
	while(x!=NULL)
	{
		
		if(val>x->value) 
		{
			if((x->right!=NULL)&&(x->right)->value==val) return x;
			else x=x->right;
		}
		else
		{
			if((x->left!=NULL)&&(x->left)->value==val) return x;
			else x=x->left;
		}
	}
	return NULL;
}

bool delete(int val,tree * root)
{
	tree * node=find(val,root);
	if(node==NULL) return false;
//	printf(" HHHHH\n");
	tree * par=NULL;
		if(node->right==NULL && node->left==NULL) 
		{
			par=parent(val,root);
			if(val==(par->right)->value) 
			{
			//	printf(" ggggggggggggggg \n");
			//	printf(" PLEFT %d \n",par->left->value);
			//	printf(" PRight %d \n",par->right->value);
				par->right=NULL;
			}
			else 
			{
			//	printf(" PRIGHT %d \n",par->right->value);
				par->left=NULL;
			}
			free(node);
		//	printf(" HELLO \n");
			return true;
		}
		else
		{
			//node->value=(Tree_Succ(node,root))->value;
		//	if(node->right!=NULL) delete(node->value,node->right);
		//	else delete(node->value,root);
			int rep = Tree_Succ(node,root)->value;
		//	printf(" value %d\n",rep);
			//printf(" Succ %d\n ",rep);
			delete(Tree_Succ(node,root)->value,root);
		//	printf(" value %d\n",rep);
			node->value=rep;
		}
}

int main()
{
	int arr[]={12,13,1,0,9,23,4,56,11,10};
	tree * root=NULL;
	tree * node=NULL;
	for(int i=0;i<10;i++)
	{
		//node=(tree *)malloc(sizeof(tree));
		tree nodep;
		node=&nodep;
		node->value=arr[i];
		node->left=NULL;
		node->right=NULL;
		node->bal=0;
		root=add(node,root);
	}
//	if(find(57,root)!=NULL) printf(" Yes its there !\n");
//	else printf("NO \n");
//	if(find(45,root)!=NULL) printf(" Yes its not there !\n");  
//	else printf(" NO \n");
	Inorder_Traversal(root,root);
/*	int a=1;
	int *i=&a;
//	if(delete(11,root)) Inorder_Traversal(root,root);
	int karr[10];
	for(int n=1;n<=10;n++)
	{
	int a=1;
        int *i=&a;
	karr[n-1]=Inorder_TraversalK(root,n,i);
	printf(" element %d %d\n",n,karr[n-1]);
	}

	
*/	
	RangeQuery(root,9,65);	
	
}	
		
	 
