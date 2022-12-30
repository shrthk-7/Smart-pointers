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
		cout << "Member function called: " << data << endl;
	}
};

/*
 * UNIQUE_PTR
 * used for heap allocation
 * then automatically frees memory to prevent leaks
 * can't be copied -- gets freed on copying
 * explicitly declared
 * syntax:
 * 		std::unique_ptr<className> ptr(new className());
 * 		std::unique_ptr<className> ptr = std::make_unique<className>(); #preferred
 *
 * implicit declaration ie `ptr = new T();` not possible
 */

int main()
{
	if (true)
	{
		unique_ptr<Obj> ptr1(new Obj("first object"));
		Obj *ptr2 = new Obj("second object");
		ptr1->print();
		ptr2->print();
	}
	cout << "------- block over ------------";
	// notice that ptr2 doesnt get automatically freed afer block is over
	return 0;
}