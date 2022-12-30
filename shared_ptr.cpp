#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Obj
{
private:
	string data;

public:
	Obj(string s)
	{
		data = s;
		cout << "Created : " << data << endl;
	}
	~Obj()
	{
		cout << "Deleted : " << data << endl;
	}
	void print()
	{
		cout << "Member function : " << data << endl;
	}
};

/*
 * SHARED_PTR
 * used for heap allocation
 * can be copied -- what a surprise right
 * automatically freed when all the copies of the pointer are out of scope
 *
 * ref count is increased every time it is copied, decreased when a copy goes out of scope
 * automatically freed when ref count is 0
 *
 * explicitly declared
 * syntax:
 * 		std::shared_ptr<className> ptr(new className()); #avoid, somehow consumes double memory
 * 		std::shared_ptr<className> ptr = std::make_shared<className>(); #use this
 */

int main()
{
	shared_ptr<Obj> ptr1_copy;

	if (true)
	{
		shared_ptr<Obj> ptr1 = make_shared<Obj>("first object");
		shared_ptr<Obj> ptr2 = make_shared<Obj>("second object");
		ptr1_copy = ptr1;
	}
	cout << "------- block over ------------\n";
	// ptr2 get deleted after the block ends, but not ptr1
	ptr1_copy->print();
	return 0;
}