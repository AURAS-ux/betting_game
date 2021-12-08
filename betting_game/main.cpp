#include<iostream>
#include<cstdlib>
#include<time.h>
#include<string>
using std::cin; using std::cout;using std::string;
int getRandom()
{
	srand(time(NULL));
	return rand() % 101;
}

int main()
{
	string playerName;
	int totalBalance=800;
	int bettedAmount;
	int randomNumber = getRandom();
	int playerNumber;
	bool shouldEnd = false;
	cout << "Introduce your name:";
	std::getline(cin, playerName);
	while (!shouldEnd && totalBalance>100 && totalBalance>0)
	{
		string choice;
		cout << "How much would you like to bet(a number greater then 100):"; cin >> bettedAmount;
		if (bettedAmount < 100 || bettedAmount>totalBalance)
		{
			cout << "Error proccesing money!";
			exit(0);
		}
		totalBalance -= bettedAmount;
		cout << "A number has been chosen,try your luck:"; cin >> playerNumber;
		if (playerNumber == randomNumber)
		{
			totalBalance *= 2;
			randomNumber = getRandom();
			cout << "Congrats,you won!!!!Your new sum of money is:" << totalBalance;
		}
		if (playerNumber < randomNumber)
		{
			cout << "Try a little higher,your sum of money is:"<<totalBalance;
		}
		if (playerNumber > randomNumber)
		{
			cout << "Try a little lower,your sum of money is:"<<totalBalance;
		}
		cout << "\nDo you wish to continue(yes/no):"; cin >> choice;
		if (choice == "yes") 
		{
			shouldEnd = false;
		}
		else if (choice == "no")
		{
			shouldEnd == true;
		}
		else
		{
			cout << "Enter a valid option";
		}
	}
	return 0;
}