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
 * WEAK_PTR
 *
 * used to refer to a shared_ptr.
 *
 * similar to a shared_ptr, but doesnt increase the ref count
 * ie even if a weak pointer is pointing to a shared_ptr,
 * the shared_ptr gets deleted after its scope is over
 *
 * syntax:
 * 		std::weak_ptr<className> ptr2 = ptr; #Here, ptr is a pointer of shared_ptr type
 */

int main()
{
	weak_ptr<Obj> ptr1_copy;

	if (true)
	{
		shared_ptr<Obj> ptr1 = make_shared<Obj>("first object");
		shared_ptr<Obj> ptr2 = make_shared<Obj>("second object");
		ptr1_copy = ptr1;
	}
	cout << "------- block over ------------";
	// notice both ptrs are deleted when their scope is over,
	// even if ptr1_copy is referencing to ptr1
	return 0;
}