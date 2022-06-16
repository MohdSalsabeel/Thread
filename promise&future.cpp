#include<mutex>
#include<thread>
#include<condition_variable>
#include<iostream>
#include<algorithm>
#include<future>
#include<chrono>

using namespace std;
using namespace std::chrono;
typedef long long int ull;

long long bankbalance = 0;


void findOdd(promise<ull>&& OddSumPromise, ull start, ull end)
{
	ull OddSum = 0;
	for (ull i = start; i <= end; i++)
	{
		if (i & 1)
		{
			OddSum += i;
		}
	}
	OddSumPromise.set_value(OddSum);
}



int main()
{
	ull start = 0, end = 19000000;
	promise<ull> OddSum;
	future<ull> OddFuture = OddSum.get_future();

	cout << "Thread created!\n";
	thread t1(findOdd, move(OddSum), start, end);

	cout << "Waiting for Result" << endl;
	cout << "OddSum: " << OddFuture.get() << endl;

	cout << "Completed" << endl;
	if (t1.joinable()) {
		t1.join();
	}
	

}
