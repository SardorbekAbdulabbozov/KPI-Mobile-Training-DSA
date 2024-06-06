#include <iostream>
using namespace std;

// author: Sardorbek Abdulabbozov - 06.06.2024

class DynamicArray
{
private:
	int *arr;
	int length;
	int capacity;

public:
	// constructor
	DynamicArray(int initialCapacity)
	{
		arr = new int[initialCapacity];
		capacity = initialCapacity;
		length = 0;
		cout << "\nArray object was initialized with a capacity = " << capacity << "\n\n";
	}

	// destructor
	~DynamicArray()
	{
		delete[] arr;
	}

	// insert element from end
	void append(int newItem)
	{
		if (capacity == length)
		{
			grow();
		}

		arr[length] = newItem;
		cout << "Element: " << newItem << " was appended successfully" << endl;

		length++;
	}

	void insertAt(int newItem, int index)
	{
		if (index <= length && index >= 0)
		{
			if (capacity == length)
			{
				grow();
			}

			for (int i = length - 1; i >= index; i--)
			{
				arr[i + 1] = arr[i];
			}

			arr[index] = newItem;
			cout << "Element: " << newItem << " was inserted successfully at index: " << index << endl;
			length++;
		}
		else
		{
			cout << "Elements must be contagious. Requirement:  0 <= index <= " << length << endl;
		}
	}

	// delete last element
	void removeLast()
	{
		arr[--length] = -1; // -1 is used to indicate empty slot in array as sentinel value
		if (capacity * 0.25 >= length)
		{
			shrink();
		}
	}

	void removeAt(int index)
	{
		if (index < length && index >= 0)
		{
			for (int i = index + 1; i < length; i++)
			{
				arr[i - 1] = arr[i];
				arr[i] = -1; // -1 is used to indicate empty slot in array as sentinel value
			}
			if (index + 1 == length)
			{
				arr[index] = -1; // -1 is used to indicate empty slot in array as sentinel value
			}
			length--;
			if (capacity * 0.25 >= length)
			{
				shrink();
			}
		}
		else
		{
			cout << "Removing element failed. " << "No element at index = " << index << ". Requirement: 0 <= index < " << length << endl;
		}
	}

	void grow()
	{
		int *newArr = new int[2 * capacity];
		for (int i = 0; i < capacity; i++)
		{
			newArr[i] = arr[i];
		}

		delete[] arr;
		arr = newArr;

		capacity *= 2;
	}

	void shrink()
	{
		int *newArr = new int[capacity / 2];
		for (int i = 0; i < length; i++)
		{
			newArr[i] = arr[i];
		}

		delete[] arr;
		arr = newArr;

		capacity /= 2;
	}

	void traverse()
	{
		cout << "\nlength: " << length << " capacity: " << capacity << endl;
		for (int i = 0; i < length; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n\n";
	}
};

int main()
{
	DynamicArray arr = DynamicArray(1);

	arr.append(120);
	arr.append(23);
	arr.insertAt(99, 3); // case when user wants to add element at index, where elements will not be contagious
	arr.append(10);
	arr.append(25);
	arr.append(3);
	arr.insertAt(99, 7); // case when user wants to add element at index, where elements will not be contagious
	arr.insertAt(99, 5);
	arr.traverse();

	arr.removeAt(0);
	arr.removeAt(1);
	arr.removeAt(2);
	arr.removeAt(3); // case when user wants to delete element that does not exists
	arr.removeLast();

	arr.traverse();

	return 0;
}
