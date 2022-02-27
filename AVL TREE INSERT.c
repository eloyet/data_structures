#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct LINKED_TREE_NODE_s *LINKED_TREE_NODE;
typedef struct LINKED_TREE_NODE_s{
	LINKED_TREE_NODE right;
	LINKED_TREE_NODE left;
    int key;
    int height; 
    void *data;
}LINKED_TREE_NODE_t[1];

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


int height(LINKED_TREE_NODE node) 
{ 
    if (node == NULL) 
        return 0; 
    return node->height; 
} 

int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 

LINKED_TREE_NODE newNode(int key,void *data) 
{ 
    LINKED_TREE_NODE node=(LINKED_TREE_NODE) malloc(sizeof(LINKED_TREE_NODE_t));

    node->key   = key; 
    node->left   = NULL; 
    node->right  = NULL; 
    node->data=  data;
    node->height = 1;  // new node is initially added at leaf 
    return node; 
} 
  LINKED_TREE_NODE rightRotate(LINKED_TREE_NODE y) 
{ 
    LINKED_TREE_NODE x= y->left; 
    LINKED_TREE_NODE T2 = x->right; 
  
    x->right = y; 
    y->left = T2; 
  
    y->height = max(height(y->left), height(y->right))+1; 
    x->height = max(height(x->left), height(x->right))+1; 
  
    return x; 
} 
LINKED_TREE_NODE leftRotate(LINKED_TREE_NODE x) 
{ 
    LINKED_TREE_NODE y = x->right; 
    LINKED_TREE_NODE T2 = y->left; 
  
    y->left = x; 
    x->right = T2; 
  
    x->height = max(height(x->left), height(x->right))+1; 
    y->height = max(height(y->left), height(y->right))+1; 
  
    return y; 
} 
int getBalance(LINKED_TREE_NODE  N) 
{ 
    if (N == NULL) 
        return 0; 
    return height(N->left) - height(N->right); 
}
 LINKED_TREE_NODE insert(LINKED_TREE_NODE  node, int key,void *data){
 

    if (node == NULL) 
        return(newNode(key,data)); 
  
    if (key < node->key){
	    node->left  = insert(node->left, key,data); 
    }
	else if (key > node->key){

        node->right = insert(node->right, key,data); 
    }  else 
        return node; 
  
    node->height = 1 + max(height(node->left), 
                           height(node->right)); 
  

    int balance = getBalance(node); 
  
     
  
    // Left Left Case 
    if (balance > 1 && key < node->left->key) 
        return rightRotate(node); 
  
    // Right Right Case 
    if (balance < -1 && key > node->right->key) 
        return leftRotate(node); 
  
    // Left Right Case 
    if (balance > 1 && key > node->left->key) 
    { 
        node->left =  leftRotate(node->left); 
        return rightRotate(node); 
    } 
  
    // Right Left Case 
    if (balance < -1 && key < node->right->key) 
    { 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    } 
  
    return node; 
}  
void linked_tree_print_horizontal(LINKED_TREE_NODE node,int l){
	int i;
	if(node!=NULL){
		linked_tree_print_horizontal(node->right,l+1);
		for(i=0;i<l;i++){
			printf("       ");

		}
		printf("%d \n",node->key);
		linked_tree_print_horizontal(node->left,l+1);
		}
} 
LINKED_TREE linked_tree_init(){
	LINKED_TREE tree=(LINKED_TREE) malloc(sizeof(LINKED_TREE_t));
	tree->root=NULL;
	return tree;
}

void linked_tree_insert(LINKED_TREE tree,int key,void *data){
	if(tree == NULL){
		printf("error: tree is not initialized");
	}else{
		tree->root = insert(tree->root,key,data);
	}
}

/*
void find(LINKED_TREE_NODE node, int level, int *maxLevel, int *res) 
{ 
    if (node != NULL) 
    { 
        find(node->left,level+1, maxLevel, res); 
  
        // Update level and resue 
        if (level > *maxLevel) 
        { 
            *res = node->key; 
            *maxLevel = level; 
        } 
  
        find(node->right,level+1, maxLevel, res); 
    } 
} 
  
// Returns value of deepest node 
int deepestNode(LINKED_TREE_NODE node) 
{ 
    // Initialze result and max level 
    int res = -1; 
    int maxLevel = -1; 
  
  
    find(node, 0, &maxLevel, &res); 
    return res; 
} */
LINKED_TREE_NODE delete_node(LINKED_TREE_NODE node,int key){
	
		if (node == NULL) 
		    return node; 
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
			//	node->data=min->data;
				node->right=delete_node(node->right,min->key);
		
			}
		
	   return node;

		}
		


   	if(node==NULL){
		return node;
	}
			node->height = 1 + max(height(node->left), 
						height(node->right));  
                          
	    int balance = getBalance(node); 
 
        if(balance> 1 && getBalance(node->left) >= 0 ){
        	return rightRotate(node);
		}
        else if(balance > 1 && getBalance(node->left) < 0 ){
            node->left =  leftRotate(node->left); 
        	return rightRotate(node);
        	
		}
		else if(balance < -1 && getBalance(node->right) <= 0 ){
			return leftRotate(node);
		}
		else if(balance < -1 && getBalance(node->right) > 0){
			node->right= rightRotate(node->right);
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
int main() 
{ 
   
 LINKED_TREE t1=  linked_tree_init();

	
   
  linked_tree_insert(t1,40,(int *)110);
  linked_tree_insert(t1, 4,(int *)111); 
  linked_tree_insert(t1, 81,(int *)112); 
  linked_tree_insert(t1, 1,(int *)113); 
  linked_tree_insert(t1, 12,(int *)114); 
  linked_tree_insert(t1, 74,(int *)115); 
  linked_tree_insert(t1, 84,(int *)116); 
    linked_tree_insert(t1, 76,(int *)116); 
  linked_tree_insert(t1, 100,(int *)116); 

  printf("inserted tree \n");
  linked_tree_print_horizontal(t1->root,0);
   
   delete_tree(t1,40);
   printf("deleted \n");
   linked_tree_print_horizontal(t1->root,0);
	
  return 0; 
} 
