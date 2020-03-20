#include <iostream>
#include <stack>
#include "text.h"
using namespace std;


MyList::MyList(string text)
{
	Node* tmp = new Node();
	tmp->data = text;
	tmp->next = nullptr;
	tmp->down = nullptr;
	tmp->level = -1;
	first = end = tmp;
}

MyList::~MyList()
{
	Node* tmp = first;
	stack<Node*> St;

	St.push(tmp);
	tmp = tmp->down;

	while (tmp->next != nullptr)
	{
		St.push(tmp);
		tmp = tmp->next;
	}
	while (tmp->level != end->level)
	{
		St.push(tmp);
		tmp = tmp->down;

		while (tmp->next != nullptr)
		{
			St.push(tmp);
			tmp = tmp->next;
		}
	}

	while (!St.empty())
	{
		tmp = St.top();
		delete tmp;
		St.pop();
	}
	first = nullptr;
	end = nullptr;
}

void MyList::push_back_current_level(string data)
{
	if (end->level == -1)
	{
		push_back_next_level(data);
	}
	else
	{
		Node* tmp = new Node();
		tmp->data = data;
		tmp->next = nullptr;
		tmp->down = nullptr;
		tmp->level = end->level;
		end->next = tmp;
		end = tmp;
	}
}

void MyList::push_back_next_level(string data)
{
	Node* tmp = new Node();
	tmp->data = data;
	tmp->next = nullptr;
	tmp->down = nullptr;
	tmp->level = end->level + 1;
	end->down = tmp;
	end = tmp;
}

void MyList::pop()
{
	Node* tmp = first;
	stack<Node*> St;

	tmp = tmp->down;
	
	while (tmp->next != nullptr)
	{
		St.push(tmp);
		tmp = tmp->next;
	}
	while (tmp->level != end->level)
	{
		St.push(tmp);
		tmp = tmp->down;

		while (tmp->next != nullptr)
		{
			St.push(tmp);
			tmp = tmp->next;
		}
	}

	tmp = St.top();
	delete end;
	end = tmp;
	tmp->next = nullptr;
	tmp->down = nullptr;
}

void MyList::print()
{
	stack<Node*> St;
	Node* tmp = first;
	while (tmp != end)
	{
		while (tmp->down != nullptr)
		{
			for (int i = 0; i < tmp->level * 2; i++)
				cout << " ";
			cout << tmp->level << ". " << tmp->data << "\n";
			St.push(tmp);
			tmp = tmp->down;
		}
		if (tmp->down == nullptr)
		{
			for (int i = 0; i < tmp->level * 2; i++)
				cout << " ";
			cout << tmp->level << ". " << tmp->data << "\n";
		}
		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
			for (int i = 0; i < tmp->level * 2; i++)
				cout << " ";
			cout << tmp->level << ". " << tmp->data << "\n";
		}
		while (tmp->next == nullptr && !St.empty() && tmp->level != 0)
		{
			tmp = St.top();
			St.pop();
		}
		if (tmp->next != nullptr)
			tmp = tmp->next;
		else
			break;
	}
}