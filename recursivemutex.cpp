#include<mutex>
#include<thread>
#include<iostream>

using namespace std;


recursive_mutex m1;
int buffer = 0;

void recursion(char c, int loopfor)
{
	if (loopfor <= 0)
	{
		return;
	}

	m1.lock();
	cout << c <<" "<< buffer++ << endl;
	recursion(c, --loopfor);
	m1.unlock();
}


int main()
{
	thread t1(recursion, '0', 10);
	thread t2(recursion, '1', 10);

	t1.join();
	t2.join();

	//cout << myAmount << endl;
}
