#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct tree{
	int value;
	struct tree * left;
	struct tree * right;
	int bal;
}tree;
int balance(tree *);
int max(int a,int b)
{
	if(a>=b) return a;
	else return b;
}
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
			//x->bal++;
			//printf(" value %d bal %d\n",x->value,x->bal);
			x=x->right;
		}
		else
		{
			//x->bal--;
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
{	printf(" \n 6 %d \n",root->value);
	printf("\nGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n");
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
	if(par!=NULL) printf(" parent value %d ",par->value);
	if(root->left!=NULL) printf(" node left %d",root->left->value);
	if(root->right!=NULL) printf(" node right %d",root->right->value);
	printf("\n");
	printf("\n");
	//	node=Tree_Pred(root,proot);
	//	if(node!=NULL) printf(" Pred value %d  bal %d\n",node->value,node->bal); */
	Inorder_Traversal(root->right,proot);

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

tree * left_rotate(tree * x)
{
	//	tree * par=(x->value,root);
	//	printf(" should be 12 %d\n",par->value);
	tree * y=x->right;
	x->right=y->left;
	y->left=x;
	x->bal=balance(x);
	y->bal=balance(y);
	//	if(y->value>par->value) par->right=y;
	//	else par->left=y;
	return y;
}

tree * right_rotate(tree * y)
{
	//	tree * par=parent(y->value,root);
	//	printf(" Should be 1 %d  and 9 %d\n",par->value,y->value);
	tree * x=y->left;
	y->left=x->right;
	x->right=y;
	y->bal=balance(y);
	x->bal=balance(x);
	printf( " y 6 %d \n ",y->value);
	printf( " x 3 %d \n ",x->value);
	printf( " x->right 6 %d \n",x->right->value);
	printf( " y->right 7 %d \n",y->right->value);
	//	if(x->value>par->value) par->right=x;
	//	else par->left=x;
	return x;
}

int height(tree * root)
{
	if(root==NULL) return 0;
	return max(height(root->left),height(root->right))+1;
}

int balance(tree * root)
{
	if(root==NULL) return 0;
	return (height(root->right)-height(root->left));
}

tree * insertAVL(tree * root,tree * node)
{
	//	printf(" hello\n");
	if(root==NULL) return node;
	//	printf(" hello\n");
	if(node->value < root->value) root->left=insertAVL(root->left,node);
	else if(node->value > root->value) root->right=insertAVL(root->right,node);
	else return root;
	root->bal=balance(root);
	//	printf("%d \n",root->value);
	//LEFT-LEFT CASE
	if(root->bal<-1 && node->value<root->left->value)
	{
		tree * temp=right_rotate(root);
		//	printf(" hh %d\n",temp->value);
		return temp;
	}

	//RIGHT-RIGHT CASE
	if(root->bal>1 && node->value>root->right->value)
	{
		tree * temp=left_rotate(root);
		//	printf(" HH %d \n",temp->value);
		return temp;
	}

	//LEFT-RIGHT CASE
	if(root->bal<-1 && node->value> root->left->value)
	{
		root->left=left_rotate(root->left);

		return right_rotate(root);
	}

	//RIGHT-LEFT CASE
	if(root->bal>1 && node->value < root->right->value)
	{
		root->right=right_rotate(root->right);
		return left_rotate(root);
	}
	//printf(" HELLO\n");
	return root;
}
tree * delAVL(tree * root,int key)
{
	if(root==NULL)
	return root;

	// If the key to be deleted is smaller than the
	// root's key, then it lies in left subtree
	if ( key < root->value )
	root->left = delAVL(root->left, key);

	// If the key to be deleted is greater than the
	// root's key, then it lies in right subtree
	else if( key > root->value )
	root->right = delAVL(root->right, key);

	// if key is same as root's key, then This is
	// the node to be deleted
	else
	{
		// node with only one child or no child
		if( (root->left == NULL) || (root->right == NULL) )
		{
			tree *temp = root->left ? root->left : root->right;

			// No child case
			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else // One child case
			*root = *temp; // Copy the contents of
			// the non-empty child
			free(temp);
		}
		else
		{
			// node with two children: Get the inorder
			// successor (smallest in the right subtree)
			//Inorder_Traversal(root,root);
			printf(" HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH ");
			tree* temp = Tree_Succ(root,root);
			printf(" succ value %d of root %d \n",temp->value,root->value);

			// Copy the inorder successor's data to this node
			root->value = temp->value;

			// Delete the inorder successor
			root->right = delAVL(root->right, temp->value);
		}
	}

	// If the tree had only one node then return
	if (root == NULL)
	return root;

	// STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
//	root->bal=balance(root);

	// STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
	// check whether this node became unbalanced)
	root->bal = balance(root);
	int b=root->bal;
	printf(" roots with balance %d %d\n",root->value,root->bal);

	// If this node becomes unbalanced, then there are 4 cases

	// Left Left Case
	if (b < -1 && balance(root->left) < 0)
	{	tree * temp=right_rotate(root);
		printf("\n %d root \n",root->value);
		printf("\n %d root right \n",root->right->value);
		printf("\n %d root left \n",root->left->value);
		return temp;
	}

	// Left Right Case
	if (b < -1 && balance(root->left) >= 0)
	{
		root->left =  left_rotate(root->left);
		return right_rotate(root);
	}

	// Right Right Case
	if (b >1 && balance(root->right) > 0)
	return left_rotate(root);

	// Right Left Case
	if (b > 1 && balance(root->right) <= 0)
	{
		root->right = right_rotate(root->right);
		return left_rotate(root);
	}

	return root;
}
int main()
{
	int arr[]={12,13,1,0,9,23,4,56,11,10};
	int arr2[]={2,3,4,5,6,7,1};
	tree * root=NULL;
	tree * root2=NULL;
	tree * node=NULL;
	tree * node2=NULL;
	for(int i=0;i<7;i++)
	{
		node2=(tree *)malloc(sizeof(tree));
		node2->value=arr2[i];
		node2->left=NULL;
		node2->right=NULL;
		node2->bal=0;
		root2=insertAVL(root2,node2);
		//		printf("%d\n",root->value);

		node=(tree *)malloc(sizeof(tree));
		node->value=arr2[i];
		node->left=NULL;
		node->right=NULL;
		node->bal=0;
		root=add(node,root);


	}
	//	tree * x=find(1,root);
	//	root=left_rotate(x,root);
	//	Inorder_Traversal(root,root);
	//	tree * par=parent(9,root);
	//	printf("\n parent of 9 is %d\n",par->value);
	//	tree * y=find(9,root);
	//	 par=parent(y->value,root);
	//	printf("\n parent of 9 is %d\n",par->value);
	//	root=right_rotate(y,root);
	//	if(find(57,root)!=NULL) printf(" Yes its there !\n");
	//	else printf("NO \n");
	//	if(find(45,root)!=NULL) printf(" Yes its not there !\n");
	//	else printf(" NO \n");
	//delAVL()
	Inorder_Traversal(root,root);
	printf(" \n ");
	Inorder_Traversal(root2,root2);
	root2=delAVL(root2,5);
	Inorder_Traversal(root2,root2);
	//	if(delete(11,root)) Inorder_Traversal(root,root);
	//	else printf(" sorry \n");


}
