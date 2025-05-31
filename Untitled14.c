#include<stdio.h>
#include<string.h>
char stack[20];
int top=-1;
void push(char s)
{
	stack[++top]=s;
}
char pop()
{
	return(stack[top--]);
}
int precd(char s)
{
	switch(s)
	{
		case '^':return 4;
	    case '*':
	    	case '/':return 3;
	    	case'+':
	    		case'-':return 2;
	    		case'(':
	    			case')':
	    				case'#':return 1;
	}
	return -1;
}
void convertip(char infix[20],char postfix[20])
{
	int i,j=0;
	char symbol;
	push('#');
	for(i=0;i<strlen(infix);i++)
	{
		symbol=infix[i];
		switch(symbol)
		{
			case'(':push(symbol);
			break;
			case')':while(stack[top]!='(')
			postfix[j++]=pop();
			pop();
			break;
			case'^':
				case'*':
					case'/':
						case'+':
							case'-':while(precd(symbol)<=precd(stack[top]))
			                postfix[j++]=pop();
			                push(symbol);
			                break;
			default:postfix[j++]=symbol;
		}
    } 
		while(stack[top]!='#')
    	postfix[j++]=pop();
		postfix[j]='\0';
}
int main()
{
	char infix[20],postfix[20];
	printf("enter infix expression");
	gets(infix);
	convertip(infix,postfix);
	printf("postfix is %s",postfix);
	return 0;
}
