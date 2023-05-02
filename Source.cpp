#include <iostream>
#include <string>

using namespace std;

struct Node
{
	Node* next = nullptr;
	Node* prev = nullptr;
	string a;
};
struct List
{
	Node* tail = nullptr;
	Node* head = nullptr;
	size_t size = 0;
};

void push(List* list);
void PushK(List* list);
void DelK(List* list);
void Menu();
void CoutList(List* list);
void DelList(List* list);
bool Chek(List* list);


int main()
{
	setlocale(0, "RUS");
	List* list = new List;;
	int i;
	bool F = 1;
	while (F)
	{
		Menu();
		cout << "" << endl;
		cin >> i;
		system("cls");
		switch (i)
		{
		case 1:
		{
			push(list);
			break;
		}
		case 2:
		{
			PushK(list);
			break;
		}
		case 3:
		{
			DelK(list);
			break;
		}
		case 4:
		{
			DelList(list);
			break;
		}
		case 5:
		{
			CoutList(list);
			break;
		}
		case 6:
		{
			F = 0;
			break;
		}
		default:
		{
			cout << "Enter the action number from the list\n\n\n\n";
		}
		}
	}
}

void Menu()
{
	cout << "\t Menu" << endl;
	cout << "1) Putting one element on the stack" << endl;
	cout << "2) Putting multiple items on the stack" << endl;
	cout << "3) Removing multiple elements from a given" << endl;
	cout << "4) Removing stack" << endl;
	cout << "5) Stack output" << endl;
	cout << "6) Shutting down the stack" << endl;
} 

bool Chek(List* list)
{
	if (list->head == nullptr)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void push(List* list)
{
	list->size++;
	Node* node = new Node;
	getline(cin >> ws, node->a);
	if (Chek(list))
	{
		node->next = list->head;
		list->head->prev = node;
		list->head = node;
	}
	else
	{
		list->tail = node;
		list->head = node;
	}
}

void PushK(List* list)
{
	int i;
	cout << "" << endl;
	cin >> i;
	list->size += i;
	while (i > 0)
	{
		Node* node = new Node;
		getline(cin >> ws, node->a);
		if (Chek(list))
		{
			node->next = list->head;
			list->head = node;
		}
		else
		{
			list->tail = node;
			list->head = node;
		}
		i--;
	}
}
void DelK(List* list)
{
	int n, i;
	int k = 1;
	cout << "Enter which item to start deleting from in the list" << endl;
	cin >> n;
	cout << "Enter how many items you need to delete" << endl;
	cin >> i;
	if (Chek(list))
	{
		if ((n <= list->size) && (n > 0))
		{
			Node* temp;
			while (n > k)
			{
				temp = list->head;
				list->head = list->head->next;
				temp->next = nullptr;
				list->tail->next = temp;
				temp->prev = list->tail;
				list->tail = temp;
			}
			while (i > 0)
			{
				temp = list->head;
				Node* temp1 = temp;
				temp = temp->next;
				temp->prev = nullptr;
				delete temp1;
			}
			while (n > 0)
			{
				temp = list->tail;
				list->tail = list->tail->prev;
				temp->prev = nullptr;
				list->tail->next = nullptr;
				temp->next = list->head;
				list->head->prev = temp;
				list->head = temp;
			}
			cout << "Elements removed" << endl;
		}
		else
		{
			cout << "Enter the number of the element that is in the stack" << endl;
		}
	}
	else
	{
		cout << "Stack is empty" << endl;
	}
}

void DelList(List* list)
{
	if (Chek(list))
	{
		Node* temp = list->head;
		while (temp != nullptr)
		{
			Node* temp1 = temp;
			temp = temp->next;
			delete temp1;
		}
		cout << "Stack removed" << endl;
	}
	else
	{
		cout << "Stack is empty" << endl;
	}
}
void CoutList(List* list)
{
	if (Chek(list))
	{
		int i = 1;
		Node* temp = list->head;
		while (temp != nullptr)
		{
			cout << i << ") " << temp->a << endl;
			i++;
			temp = temp->next;
		}
	}
	else
	{
		cout << "Stack is empty" << endl;
	}
}