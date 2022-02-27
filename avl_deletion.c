#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct LINKED_TREE_NODE_s *LINKED_TREE_NODE;
typedef struct LINKED_TREE_NODE_s{
	LINKED_TREE_NODE right; /*Do not alter -- DSW--*/
	LINKED_TREE_NODE left;
	int key;
	void *data;
	int height;
} LINKED_TREE_NODE_t[1];


typedef struct LINKED_TREE_s *LINKED_TREE;
typedef struct LINKED_TREE_s{
	LINKED_TREE_NODE root;

}LINKED_TREE_t[1];



LINKED_TREE_NODE linked_tree_insert_recursive(LINKED_TREE_NODE node, int key,void *data) ;
 int getBalance(LINKED_TREE_NODE N) ;
 LINKED_TREE_NODE leftRotate(LINKED_TREE_NODE x) ;
 LINKED_TREE_NODE rightRotate(LINKED_TREE_NODE y) ;
 int max(int a, int b) ;
int height(LINKED_TREE_NODE N);


LINKED_TREE linked_tree_init(){
	LINKED_TREE tree=(LINKED_TREE)malloc(sizeof(LINKED_TREE_t));
	tree->root = NULL;
	return tree;
}
LINKED_TREE_NODE linked_tree_node_init(int key,void *data){
	LINKED_TREE_NODE node;
	node=(LINKED_TREE_NODE)malloc(sizeof(LINKED_TREE_NODE_t));
	node->key=key;
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	node->height=1;
	return node;

}
void linked_tree_insert(LINKED_TREE tree,int key,void *data){
	if(tree==NULL){
		printf("error:tree not initialized");
	}else{
		tree->root = linked_tree_insert_recursive(tree->root,key,data);
	}
}

void linked_tree_print_horizontal(LINKED_TREE_NODE node ,int l){
	int i;
	if(node != NULL){
		linked_tree_print_horizontal(node->right,l+1);
		for(i=0;i<l;i++){
			printf("     ");
		}
		printf("%d\n",node->key);
	    //printf("%d\n",node->data);
		linked_tree_print_horizontal(node->left,l+1);
	}
}






int height(LINKED_TREE_NODE N){
    if (N == NULL)
        return 0;
    return N->height;
}
int max(int a, int b){
    return (a > b)? a : b;
}

int getBalance(LINKED_TREE_NODE N){
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}


LINKED_TREE_NODE rightRotate(LINKED_TREE_NODE y){
    LINKED_TREE_NODE x = y->left;
    LINKED_TREE_NODE T2 = x->right;
    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    return x;
}

LINKED_TREE_NODE leftRotate(LINKED_TREE_NODE x){
    LINKED_TREE_NODE y = x->right;
    LINKED_TREE_NODE T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    return y;
}








LINKED_TREE_NODE linked_tree_insert_recursive(LINKED_TREE_NODE node, int key,void *data){
    if (node == NULL)
        return (linked_tree_node_init(key,data));

    if (key < node->key)
        node->left  = linked_tree_insert_recursive(node->left, key,data);
    else if (key > node->key)
        node->right = linked_tree_insert_recursive(node->right, key,data);
    else
        return node;


    node->height = 1 + max(height(node->left),
                           height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);


    if (balance < -1 && key > node->right->key)
        return leftRotate(node);


    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }


    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

LINKED_TREE_NODE delete_node(LINKED_TREE_NODE node,int key){

	if(node != NULL){
		if(key<node->key){
			node->left = delete_node(node->left,key);
		}else if(key>node->key){
			node->right=delete_node(node->right,key);
		}else{
			if(node->left == NULL && node->right == NULL){
				free(node);
				node=NULL;
			}else if(node->left == NULL && node->right != NULL){
				LINKED_TREE_NODE temp=node->right;
				free(node);
				node=temp;
			}else if(node->left != NULL && node->right == NULL){
				LINKED_TREE_NODE temp=node->left;
				free(node);
				node=temp;
			}else{
				LINKED_TREE_NODE min=node->right;
				while(min->left !=NULL){
					min=min->left;
				}
				node->key=min->key;
		
				//node->data=min->data;
				node->right = delete_node(node->right,min->key);

			}

		}

	}
 
	if(node==NULL){
		return node;
	}
	node->height = 1 + max(height(node->left),height(node->right));
	//int balance = getBalance(node);

	if ( getBalance(node) > 1 && getBalance(node->left)>=0)
		return rightRotate(node);


	if ( getBalance(node) > 1 && getBalance(node->left)< 0) {

		node->left =  leftRotate(node->left);
    	return rightRotate(node);

	}
	if ( getBalance(node) < -1 && getBalance(node->right)<= 0)
	{
	 		return leftRotate(node);
	}
	if ( getBalance(node) < -1 && getBalance(node->right)> 0)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
}


void delete_tree(LINKED_TREE tree ,int key){

	if(tree==NULL){
		printf("error");
	}else if(tree->root == NULL){
		printf("tree empty");
	}else{
		delete_node(tree->root,key);
	}
}

int main(){

	LINKED_TREE t1 =linked_tree_init();
    linked_tree_insert(t1,33,(int *)110);
	linked_tree_insert(t1,12,(int *)44);
    linked_tree_insert(t1,55,(int *)40);
    linked_tree_insert(t1,3,(int *)32);
	linked_tree_insert(t1,19,(int *)74);
	linked_tree_insert(t1,44,(int *)111);
	linked_tree_insert(t1,63,(int *)47);
	linked_tree_insert(t1,1,(int *)101);
	linked_tree_insert(t1,5,(int *)111);	
	linked_tree_insert(t1,15,(int *)111);
	linked_tree_insert(t1,25,(int *)111);
	linked_tree_insert(t1,37,(int *)111);
	linked_tree_insert(t1,45,(int *)111);

	linked_tree_print_horizontal(t1->root,0);
	printf("\n\n\n");
    delete_tree(t1,19);
        delete_tree(t1,12);
    delete_tree(t1,55);
  

    printf("\n\n\n");
	linked_tree_print_horizontal(t1->root,0);

	return 0;
}


