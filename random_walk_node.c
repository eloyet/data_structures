#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct NODE_s *NODE;

typedef struct NODE_s{
    char name;
    NODE link[10];
}NODE_t[1];


#define nodeA 0
#define nodeB 1
#define nodeC 2
#define nodeD 3
#define nodeE 4
#define nodeF 5

int main() {
    srand(time(NULL));
    //printf("%d\n", random());

    NODE_t node[6];
    node[0]->name = 'A';
    node[1]->name = 'B';
    node[2]->name = 'C';
    node[3]->name = 'D';
    node[4]->name = 'E';
    node[5]->name = 'F';

    int i, j;
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 10; j++) {
            node[i]->link[j] =NULL;
        }
    }

    //a -> c,d,e,f.
    node[nodeA]->link[0] = node[nodeC];
    node[nodeA]->link[1] = node[nodeD];
    node[nodeA]->link[2] = node[nodeE];
    node[nodeA]->link[3] = node[nodeF];

    //b -> c,f.
    node[nodeB]->link[0] = node[nodeC];
    node[nodeB]->link[1] = node[nodeF];

    //c -> a,b,e.
    node[nodeC]->link[0] = node[nodeA];
    node[nodeC]->link[1] = node[nodeB];
    node[nodeC]->link[2] = node[nodeE];

    //d -> a,e,f.
    node[nodeD]->link[0] = node[nodeA];
    node[nodeD]->link[1] = node[nodeE];
    node[nodeD]->link[2] = node[nodeF];

    //e -> a,c,d.
    node[nodeE]->link[0] = node[nodeA];
    node[nodeE]->link[1] = node[nodeC];
    node[nodeE]->link[2] = node[nodeD];

    //f -> a,b,d.
    node[nodeF]->link[0] = node[nodeA];
    node[nodeF]->link[1] = node[nodeB];
    node[nodeF]->link[2] = node[nodeD];

    //Random walk.
        
                
		


    int choice = rand() % 6;

    	
    printf("The first node is %c \n",node[choice]->name);

	//random walk 
	int time=rand()%5+1;  
	int count=0; //length
	printf(" time :%d \n",time); //random walk time
	 if(node[choice]->name=='A'){
       	count=count+0;
	   }
	    if(node[choice]->name=='B'){
       	count=count+1;
	   }
	   if(node[choice]->name=='C'){
       	count=count+2;
	   }
	    if(node[choice]->name=='D'){
       	count=count+3;
	   }
	   if(node[choice]->name=='E'){
       	count=count+4;
	   }
	    if(node[choice]->name=='F'){
       	count=count+5;
	   }
	   
	   
	   
	   int linknew;
	   
        for(i=0;i<time;i++){  //WALK
        
		linknew=rand()%3; //creates new link for each time 


	   while(node[choice]->link[linknew]==node[choice]){
	   	linknew=rand()%3;
	   }
    
	   while(node[choice]->link[linknew]==NULL){  //if node->link points NULL it creates new link 
	   
	        linknew=rand()%3;
       }
        if(node[choice]->link[linknew]->name=='A'){
       	count=count+0;
	   }
	     if(node[choice]->link[linknew]->name=='B'){
       	count=count+1;
	   }
	   if(node[choice]->link[linknew]->name=='C'){
       	count=count+2;
	   }
	    if(node[choice]->link[linknew]->name=='D'){
       	count=count+3;
	   }
	   if(node[choice]->link[linknew]->name=='E'){
       	count=count+4;
	   }
	    if(node[choice]->link[linknew]->name=='F'){
       	count=count+5;
	   }
       
        printf(" %d. node : %c \n",i+1, node[choice]->link[linknew]->name);
        
        
        node[choice]->link[linknew]==node[choice]; 
             
      
      
       
  
}
     printf("\n the length is %d \n",count);

	
    return 0;
}


