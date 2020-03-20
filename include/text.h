#include <string>
using namespace std;

struct Node
{
	string data;
	Node *next;
	Node *down;
	int level;
};

class MyList{
	Node *first;
	Node *end;
public:
	MyList(string text);
	void push_back_current_level(string data);
	void push_back_next_level(string data);
	void pop();
	void print();
	~MyList();
};