#include <iostream>
using namespace std;


//defining max value for top of stack
#define MAX 6

int top = 0; //initializing top 


int menu()//interactive menu for stack implementation 
{
	int decision;

	cout << "Welcome to the Push and Pop function.";
	cout << "Enter a number for the function you would like to use.";
	cout << "1. Push\n";
	cout << "2. Pop\n";
	cout << "3. Reprint Menu\n";
	cout << "4. Quit";

	cin >> decision;

	return decision; 

}

//Push is void because it doesnt return a value. Its manipulating data in the back end
// it also doesnt take any values because it asks for user input, however this seems unimportant

void push()
{

	int data;
	if (top == MAX)//fail condition
	{
		cout << "Stack overflow.";

		return; 
	}
	else
	{
		cout << "Enter data: \n";
		cin >> data;

		stack[top] = data;
		top = top + 1;//increase top by 1

	}
}

void pop()
{
	if (top == 0)// fail condition
	{
		cout << "Stack is empty.";

		return;
	}
	else
	{
		stack[--top];//removal of data from stack
		top = top - 1;

		cout << "Element removed.";
		
	}
}

int main()
{
	int ch;

	do
	{
		ch = menu();

		switch ch
		{
		case 1:  
			push();
			break;
		case 2:
			pop();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0;)
		}

	} while (1);

}