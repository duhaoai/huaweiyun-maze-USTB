#include "../include/main.h"
using namespace std;
int random_maze(vector<vector<int>> &maze, int N)
{
	try
	{

		for (int i = 0; i < N; i++)
		{
			int max1 = 0;
			for (int j = 0; j < N; j++)
			{
				if (max1 <= N / 2)
					maze[i][j] = rand() % 2;
				else
					maze[i][j] = 0;

				if (maze[i][j] == 1)
					max1++;
			}
		}
		return 1;
	}
	catch (const std::exception &)
	{
		cerr << "maze init error";
		return -1;
	}
};
int random_size(int max)
{
	return rand() % max;
}
int random_mode()
{
	return rand() % 2;
}