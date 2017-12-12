//@author Kyle Curry

#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
	queue<float> transactions;
	float balance = 0.0;
	transactions.push(100.42);
	transactions.push(-5.58);
	transactions.push(50.78);
	transactions.push(-20.50);
	while (!transactions.empty())
	{
		cout << transactions.front() << " pushed to account" << endl;
		balance = balance + transactions.front();
		transactions.pop();
	}


	cout << "Final Balance: $" << balance << endl;

	return 0;
}