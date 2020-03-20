#include <string>
using namespace std;

struct Node
{
	string data;
	Node *next;
	Node *down;
	int level;
};

struct MyIterator
{
	Node* it;
	Node& operator*();
	Node& operator->();

	MyIterator next();//"���� ������"
	MyIterator endNext();//"���� ������ �� �����"
	MyIterator nextLevel();//"���� ����"
	MyIterator endNextLevel();//"���� ���� �� �����"

	void insNext(string data); //"��������� ����� Node � next"
	void insDown(string data); //"��������� ����� Node � down"

	bool operator==(const MyIterator& iterator);
	bool operator!=(const MyIterator& iterator);
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