#include <iostream>
#include <Windows.h>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <conio.h>
using namespace std;


int getWaitingTime(clock_t start)
{
	clock_t end;
	end = clock();
	return (end-start) / CLOCKS_PER_SEC * 10000;
}
char randomLetter()
{
	return rand() % 26 + 97;
}

int main()
{	
	srand(time(NULL));
	int freq = 1;
	system("pause");
	clock_t start = clock();
	vector<char> queue;
	bool koniec = 0;
	queue.push_back('a');
	int punkty = 0;
	float hardness = 0.1;
	while (!koniec)
	{
		if (getWaitingTime(start) > freq)
		{
			for (int i = 0; i < hardness; i++)
			{
				queue.push_back(randomLetter());
			}
			hardness += 0.1;
			
			system("cls");
			for (int i = 0; i < queue.size(); i++)
			{
				cout << queue.at(i) << " ";
			}
			start = clock();
		}
		if (_kbhit())
		{
			char input;
			input = _getch();
			if (input == queue.at(0))
			{
				punkty++;
				queue.erase(queue.begin());
			}
			else
			{
				koniec = 1;
			}
		}
		
		
	}
	cout << endl <<  "You lost! Your score: " << punkty << endl;;
	system("pause");
}