// Stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


using namespace std;

class Stack
{
private:
		int* arr;
		int capacity;
		int topIndex;
public:
	Stack(int cap = 2)
	{
		capacity = cap;
		arr = new int[capacity];
		topIndex = -1;
	}

	void push(int newElement)
	{
		if (topIndex == capacity - 1)
		{
			int newCapacity = capacity * 2; // resize the stack 
			int* newArr = new int[newCapacity]; 

			// copy the old elements to the new array
			for (int i = 0; i < capacity; i++)
			{
				newArr[i] = arr[i];
			}
			delete[] arr; // becomes a dangling pointer
			arr = newArr;
			capacity = newCapacity;
		}
		arr[++topIndex] = newElement;
	}
	int pop()
	{
		if (topIndex == -1)
		{
			cout << " no element to pop" << "Stack Underflow condition";
			return -1;
		}
		return arr[topIndex--];
	}
	int top()
	{
		if (topIndex == -1)
		{
			cout << "Stack is empty";
			return -1;
		}
		return arr[topIndex];
	}
	bool isEmpty()
	{
		return topIndex == -1;
	}
	int size()
	{
		return topIndex + 1;
	}

	~Stack()
	{
		delete[] arr;
		arr = nullptr;
	}
};

int main()
{
	Stack stackObj; 
	stackObj.push(0);
	stackObj.push(1);
	stackObj.push(2);
	stackObj.push(3);

	cout << "top element" << stackObj.top() << endl;


	stackObj.pop();
	stackObj.pop();
	cout << "top element" << stackObj.top() << endl;

	return 0;



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
