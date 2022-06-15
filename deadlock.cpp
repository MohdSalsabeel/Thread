#include<mutex>
#include<thread>
#include<condition_variable>
#include<iostream>

using namespace std;

mutex m1;
mutex m2;

void thread1()
{
	m1.lock();
	this_thread::sleep_for(chrono::seconds(1));
	m2.lock();
	cout << "It is thread one" << endl;
	m1.unlock();
	m2.unlock();
}

void thread2()
{
	m2.lock();
	this_thread::sleep_for(chrono::seconds(1));
	m1.lock();
	cout << "It is thread two" << endl;
	m2.lock();
	m1.lock();
}


int main()
{
	thread t1(thread1);
	thread t2(thread2);

	t1.join();
	t2.join();

}
