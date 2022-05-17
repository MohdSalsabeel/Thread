#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

void work(int n) {
	cout << "Hello" << endl;
	int result = 0;
	for (int i = 0; i < n; i++) {
		result += i;
	}
	cout << "add of value" << result << endl;
}

void fun(int n) {
	cout << "fun" << endl;
	int result = 0;
	for (int i = 0; i < n; i++) {
		result += i;
	}
	cout << "multiply of value" << result << endl;
}



void fun() {
	cout << "This is good" << '\n';
}

int main() {
	//thread worker(work,5);
	//thread worker1(fun,5);

	thread t(fun);
	//t.join();
	
	//worker1.join();
	//worker.join();

	return 0;
}
