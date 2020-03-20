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

	MyIterator next();//"идет вправо"
	MyIterator endNext();//"идет вправо до упора"
	MyIterator nextLevel();//"идет вниз"
	MyIterator endNextLevel();//"идет вниз до упора"

	void insNext(string data); //"добавляет новый Node в next"
	void insDown(string data); //"добавляет новый Node в down"

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