#include <iostream>
#include <algorithm>
#include <queue>
#include <stdio.h>

using namespace std;

int mainM()
{
	priority_queue<int> Heap;
	while (true)
	{
		char command;
		scanf("%c ", &command);

		switch (command)
		{
		case 'A':
			int newValue;
			scanf("%d\n", &newValue);
			Heap.push(newValue);

			break;
		case 'L':
			if (!Heap.empty())
			{
				printf("%d\n", Heap.top());
			}
			else
			{
				printf("Not available\n");
			}

			break;
		case 'Q':
			return 0;
			break;
		case 'R':
			if (!Heap.empty())
			{
				printf("%d\n", Heap.top());
				Heap.pop();
			}
			else
			{
				printf("Not available\n");
			}

			break;
		default:
			break;
		}
	}
	return 0;
}