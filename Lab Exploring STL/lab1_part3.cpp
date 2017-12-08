#include <iostream>
#include <string>
#include <queue>
using namespace std;


int main()
{
	float balance = 0.0;

	

	queue<float> transactions;

	transactions.push(9.9);
	transactions.push(-8.9);
	transactions.push(10.0);
	transactions.push(-372.0);
	transactions.push(2198.0);

	while (!transactions.empty())
	{
		cout << transactions.front() << " pushed to account" << endl;
		balance = transactions.front() + balance;
		transactions.pop();

	}

	cout << "Final balance: $" << balance << endl;




	return 0;
}