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


ull findOdd( ull start, ull end)
{
	ull OddSum = 0;
	for (ull i = start; i <= end; i++)
	{
		if (i & 1)
		{
			OddSum += i;
		}
	}
	return OddSum;
}



int main()
{
	ull start = 0, end = 19000000;
	
	cout << "Thread created!\n";
	future<ull> OddSum = async(launch::async, findOdd, start, end);

	
	

	cout << "Waiting for Result" << endl;
	cout << "OddSum: " << OddSum.get() << endl;

	cout << "Completed" << endl;
	
	

}
