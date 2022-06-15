#include<mutex>
#include<thread>
#include<condition_variable>
#include<iostream>

using namespace std;

mutex m;
condition_variable cv;
long balance = 0;


void addMoney(int money)
{
	lock_guard<mutex> lg(m);
	balance += money;
	cout << "Amount added current balance: " << balance << endl;
	cv.notify_one();
}

void withdrawMoney(int money)
{
	unique_lock<mutex> ul(m);
	cv.wait(ul, [] {return (balance != 0) ? true : false;  });
	if (balance >= money)
	{
		balance -= money;
		cout << "Amount Deducted: " << money << endl;

	}
	else {
		cout << "Amount cannot be deducted because money is less" << endl;
	}
	cout << "Balance is: " << balance << endl;

}

int main()
{
	thread t1(withdrawMoney,500);
	thread t2(addMoney,500);

	t1.join();
	t2.join();

}
