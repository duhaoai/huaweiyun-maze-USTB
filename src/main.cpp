#include "../include/main.h"
using namespace std;
#define INT_MAX 2147483647
int MAXN = 20;
int MINN = 4;
int main(int argc, char **argv)
{
	int output_mode = int(*argv[1]) - '0';
	srand((int)time(0));
	int N;
	N = random_size(MAXN);
	if (N < MINN)
		N += 3;

	vector<vector<int>> maze; //�Թ���ͼ

	vector<int> ball; //���λ��
	ball.push_back(random_size(N));
	ball.push_back(random_size(N));
	vector<int> hole; // ����λ��
	hole.push_back(random_size(N));
	hole.push_back(random_size(N));

	int hole_mode; //����mode:1,�� 0����
	hole_mode = random_mode();

	int m = N, n = N; //�Թ��ĳ��Ϳ�
	for (int i = 0; i < n; i++)
	{
		vector<int> dim(N, 0);
		maze.push_back(dim);
	}
	random_maze(maze, N);

	maze[ball[0]][ball[1]] = 0;
	maze[hole[0]][hole[1]] = 0;

	vector<vector<int>> dists(m, vector<int>(n, INT_MAX));
	vector<vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
	vector<char> way{'l', 'u', 'r', 'd'};
	queue<pair<int, int>> q;
	unordered_map<int, string> u;
	dists[ball[0]][ball[1]] = 0;
	q.push({ball[0], ball[1]});
	while (!q.empty())
	{
		auto t = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int x = t.first, y = t.second, dist = dists[x][y];
			string path = u[x * n + y];
			if (hole_mode == 1)
				while (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0 && (x != hole[0] || y != hole[1]))
				{
					x += dirs[i][0];
					y += dirs[i][1];
					++dist;
				}
			else if (hole_mode == 0)
			{
				while (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0)
				{
					x += dirs[i][0];
					y += dirs[i][1];
					++dist;
				}
			}
			if (x != hole[0] || y != hole[1])
			{
				x -= dirs[i][0];
				y -= dirs[i][1];
				--dist;
			}
			path.push_back(way[i]);
			if (dists[x][y] > dist)
			{
				dists[x][y] = dist;
				u[x * n + y] = path;
				if (x != hole[0] || y != hole[1])
					q.push({x, y});
			}
			else if (dists[x][y] == dist && u[x * n + y].compare(path) > 0)
			{
				u[x * n + y] = path;
				if (x != hole[0] || y != hole[1])
					q.push({x, y});
			}
		}
	}
	string res = u[hole[0] * n + hole[1]];
	string ans = res.empty() ? "-1" : res;
	if (output_mode == 1 && ans != "-1")
	{
		cout << "maze size:" << N << endl;
		cout << "start positin(" << ball[0] << "," << ball[1] << ")" << endl;
		cout << "hole position(" << hole[0] << "," << hole[1] << ")" << endl;
		cout << "hole or star?" << (hole_mode == 1 ? "hole" : "star") << endl;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (ball[0] == i && ball[1] == j)
					cout << "+";
				else if (hole[0] == i && hole[1] == j)
				{
					if (hole_mode == 0)
						cout << "*";
					else
						cout << "O";
				}
				else if (maze[i][j] == 0)
					cout << " ";
				else if (maze[i][j] == 1)
					cout << "#";
			}
			cout << endl;
		}
		cout << ans << endl;
	}
	else if (output_mode == 0)
		cout << ans << endl;
}