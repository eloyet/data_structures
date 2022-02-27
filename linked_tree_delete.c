#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct LINKED_TREE_NODE_s *LINKED_TREE_NODE;
typedef struct LINKED_TREE_NODE_s{
	LINKED_TREE_NODE right; /*Do not alter -- DSW--*/
	LINKED_TREE_NODE left;
	int key;
	void *data;
} LINKED_TREE_NODE_t[1];

typedef struct LINKED_TREE_s *LINKED_TREE;
typedef struct LINKED_TREE_s{
	LINKED_TREE_NODE root;
 } LINKED_TREE_t[1];
LINKED_TREE linked_tree_init(){
	LINKED_TREE tree=(LINKED_TREE)malloc(sizeof(LINKED_TREE_t));
	tree->root = NULL;
	return tree;
}
LINKED_TREE_NODE linked_tree_node_init(int key,void *data)
{
	LINKED_TREE_NODE node;
	node=(LINKED_TREE_NODE)malloc(sizeof(LINKED_TREE_NODE_t));
	node->key=key;
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;

}
LINKED_TREE_NODE linked_tree_insert_recursive(LINKED_TREE_NODE node,int key,void *data)
{
	if(node == NULL)
	{
		node=linked_tree_node_init(key,data);
	}else{
		if(key < node->key){
			node->left = linked_tree_insert_recursive(node->left,key,data);
		}else if(key > node->key){
			node->right = linked_tree_insert_recursive(node->right,key,data);
		}
	}
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
void delete_node(LINKED_TREE tree,int key){
	LINKED_TREE_NODE parent = (LINKED_TREE_NODE)tree;
	LINKED_TREE_NODE node = tree->root;
	int choice = 1;
	while(node != NULL){
		if(key<node->key){
			parent=node;
			node=node->left;
			choice=0;
		}else if(key>node->key){
			parent=node;
			node=node->right;
		    choice=1;
		}else{
			break;
		}
	}
	if(node == NULL){
		printf("key not found");
	}else{
		if(node->left == NULL && node->right== NULL){
			if(choice == 0){
				parent->left = NULL;

			}else{
				parent->right = NULL;
			}
		}else if(node->left != NULL && node->right == NULL){
			if(choice == 0){
				parent->left =node->left;
			}else{
				parent->right=node->left;
			}
		}else if(node->left == NULL && node->right != NULL){
			if(choice == 0){
				parent->right=node->left;
			}else{
				parent->right=node->right;
			}

		}else{
			LINKED_TREE_NODE min =node->right;
			while(min->left != NULL ){
				min=min->left;
			}
			min->left=node->left;
			if(choice==0){
				parent->left=node->right;

			}else{
				parent->right=node->right;
			}
		}
	}
	free(node);

}
void delete_tree(LINKED_TREE tree ,int key){
	if(tree==NULL){
		printf("error");
	}else if(tree->root == NULL){
		printf("tree empty");
	}else{
		delete_node(tree,key);
	}
}
int main(){
	LINKED_TREE t1 =linked_tree_init();
	linked_tree_insert(t1,2,(int*)2);
	linked_tree_insert(t1,4,(int *)4);
	linked_tree_insert(t1,9,(int *)9);
	linked_tree_insert(t1,-3,(int *)-3);
	linked_tree_insert(t1,0,(int *)0);
	linked_tree_insert(t1,8,(int *)8);
	linked_tree_insert(t1,11,(int *)11);
	linked_tree_insert(t1,12,(int *)12);
	linked_tree_insert(t1,7,(int *)7);

	linked_tree_print_horizontal(t1->root,0);
	printf("helloo\n\n\n\n\n");
	delete_tree(t1,11);
	linked_tree_print_horizontal(t1->root,0);


}

