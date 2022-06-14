#include<mutex>
#include<thread>
#include<iostream>

using namespace std;

int myAmount = 0;
timed_mutex m;

void increment(int i)
{
	if (m.try_lock_for(chrono::seconds(1)))
	{
		++myAmount;
		this_thread::sleep_for(chrono::seconds(2));
		cout << "Thread " << i << " Entered" << endl;
		m.unlock();
	}
	else
	{
		cout << "Thread " << i << " could not Entered" << endl;
	}
}

int main()
{
	thread t1(increment, 1);
	thread t2(increment, 2);

	t1.join();
	t2.join();

	cout << myAmount << endl;
}
