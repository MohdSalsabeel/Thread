// Example 1

#include<mutex>
#include<thread>
#include<iostream>

using namespace std;

mutex m1;
int buffer = 0;

void task(const char* threadNumber, int loopfor)
{
	unique_lock<mutex> lock(m1);
	for (int i = 0; i < loopfor; ++i)
	{
		buffer++;
		cout << threadNumber<<" : " << buffer << endl;
	}
}


int main()
{
	thread t1(task, "T1", 10);
	thread t2(task, "T2", 10);

	t1.join();
	t2.join();

}

// Example 2

#include<mutex>
#include<thread>
#include<iostream>

using namespace std;

mutex m1;
int buffer = 0;

void task(const char* threadNumber, int loopfor)
{
	unique_lock<mutex> lock(m1, defer_lock);  // Does not lock mutex m1
	lock.lock();  // But we have  explicitly tell to lock the mutex
	for (int i = 0; i < loopfor; ++i)
	{
		buffer++;
		cout << threadNumber<<" : " << buffer << endl;
	}
	// lock.unlock() does not need because of destructor of unique_lock
}


int main()
{
	thread t1(task, "T1", 10);
	thread t2(task, "T2", 10);

	t1.join();
	t2.join();

}
