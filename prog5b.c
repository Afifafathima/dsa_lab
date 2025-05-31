#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
float stack[20];
int top=-1;
void push(float ele)
{
	stack[++top]=ele;
}
float pop()
{
	return(stack[top--]);
}
void evaluate(char postfix[])
{
	char sym;
	int i;
	float op1,op2,result;
	for(i=0;i<strlen(postfix);i++)
	{
		sym=postfix[i];
		if(isdigit(sym))
		push(sym-'0');
		else
		{
			op2=pop();
			op1=pop();
			switch(sym)
			{
				case '+':push(op1+op2);
				break;
				case '-':push(op1-op2);
				break;
				case '*':push(op1*op2);
				break;
				case '/':push(op1/op2);
				break;
				case '^':push(pow(op1,op2));
				break;
				case '%':push((int)op1%(int)op2);
				break;
				default:printf("invalid");
			}
		}
	}
	result=pop();
	printf("result=%f",result);
}
int main()
{
	char postfix[20];
	printf("enter postfix exp:");
	gets(postfix);
	evaluate(postfix);
}

