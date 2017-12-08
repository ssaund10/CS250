#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main()
{
	bool done = false;

	cout << "Enter the next word of the sentence, or UNDO to undo, or DONE to stop." << endl;

	stack<string> sentence;




	while (!done)
	{
		string word;
		cout << ">> ";
		cin >> word;

		if (word == "UNDO")
		{
			cout << "Removing last entered word " << endl;
			sentence.pop();

		}
		else if (word == "DONE")
		{
			done = true;
		}
		else
		{
			sentence.push(word);
		}

	}

	while (!sentence.empty())
	{
		cout << "Top item: " << sentence.top() << endl;
		sentence.pop();

	}

	cout << endl << endl << "Finished sentence: ";


	return 0;
}
