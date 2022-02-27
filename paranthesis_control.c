#include <stdio.h>

int MAXSIZE=100;
char stack[100];
int top = -1;

int isempty(){
	if(top== -1)
	return 1;
	else 
	return 0;
	
}

int isfull(){
	if(top == 100)
	return 1;
	else return 0;
	
}
char peek(){
	return stack[top];
}
char pop(){
	
	char data;
	if(! isempty()){
		data=stack[top];
		top--;
		return data;
	}
	else {
		printf("could not retrieve data ,stack is EMPTY \n");
		
	}
}

void push(char data){
	
	if(! isfull()){
		top++;
		stack[top]=data;
	}
	else {
		printf("Could not insert data,stack is FULL \n");
		
	}            
}	
 
	
	


int main(){
	char a[10]="{[)}";
	int i;

	
	for(i=0;i<10;i++){
		
		if(a[i]== '[' || a[i]=='(' || a[i]=='{'){
			
			push(a[i]);
			
		}
		
		else if(a[i]==']' || a[i]==')' || a[i]=='}'){
			if(a[i]==']'){
				if(stack[top]=='['){
					pop();
				}
				else {
					break;
				}
			}
			if(a[i]==')'){
				if(stack[top]=='('){
					pop();
				}
				else{
					break;
				}
			}
			if(a[i]=='}'){
				if(stack[top]=='{'){
					pop();
					
				}
				else{
					break;
				}
			}
			
			
		
			
			
		}
		
		
		
	}
	
	printf("Elemenet at the top is %c \n",peek());
	
	
	if(top== -1){
		printf("Perfectly balanced \n");

		}
	else 
	{
		printf("Unbalanced! \n");
	}
	
	
	return 0;	
}	
	
	




