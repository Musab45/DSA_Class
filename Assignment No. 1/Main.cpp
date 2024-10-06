#include<iostream>

class Stack
{
private:
	int top;
	int size;
	int min_num;
	int* data;
	int* next_greater;
public:
	Stack(int s) :size(s)
	{
		top = -1;
		data = new int[size];
		next_greater = new int[size];
	}
	bool isFull()
	{
		if (top == size)
		{
			return true;
		}
		return false;
	}
	bool isEmpty()
	{
		if (top == -1)
		{
			return true;
		}
		return false;
	}
	void push(int value)
	{
		if (!isFull())
		{
			if (isEmpty())
			{
				min_num = value;
			}
			top++;
			data[top] = value;
			if (value < min_num)
			{
				min_num = value;
			}
		}
		else
		{
			std::cout << "Stack Overflow!" << std::endl;
		}
	}
	int pop()
	{
		if (!isEmpty())
		{
			int returned_value = data[top];
			top--;
			return returned_value;
		}
		else
		{
			std::cout << "Stack Underflow!" << std::endl;
		}
	}
	int peek()
	{
		if (!isEmpty())
		{
			return data[top];
		}
	}
	int getMin()
	{
		if (isEmpty())
		{
			std::cout << "No Numbers Entered Yet!";
			return NULL;
			std::cout << std::endl;
		}
		else
		{
			return min_num;
		}
	}
	int getSize()
	{
		return top + 1;
	}
	void print_stack()
	{
		std::cout << "[ ";
		for (int i = 0; i <= top; i++)
		{
			std::cout << data[i] << " ";
		}
		std::cout << "]" << std::endl;
	}
};

int main()
{
	Stack test(10);
	test.push(12);
	test.push(21);
	test.push(4);
	test.push(5);
	test.push(18);
	test.push(9);
	test.pop();
	test.pop();
	test.print_stack();
	return 0;
}