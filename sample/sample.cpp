#include "ls/Pool.h"
#include "iostream"

using namespace ls;
using namespace std;

int main()
{
	Pool<int> pool;
	pool.put(new int(1));
	pool.put(new int(2));
	auto it = pool.get();
	while(it)
	{
		cout << *it << endl;
		it = pool.get();
	}
	return 0;
}
