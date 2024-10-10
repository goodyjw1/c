// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
#define int int64_t
#define NN 100


int N, M;
int board[NN][NN];
int dy[4] = { 0,1,0,-1 }, dx[4] = { 1,0,-1,0 };

bool safe(int y, int x) { return 0 <= x && x < N && 0 <= y && y < M; }

void prt()
{
	cout << endl;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			printf("%2d ", board[y][x]);

		}
		cout << endl;
	}
	cout << endl;
}


int bfs()
{
	queue<pair<int, int>>q;
	q.push({ N - 1,0 });
	board[N - 1][0] = 1;

	while (!q.empty())
	{
		auto p = q.front();
		q.pop();
		int y = p.first;
		int x = p.second;

		prt();

		if (y == 0 && x == M - 1)//출구도달하면 경로의 길이 반환
		{
			return board[y][x];
		}

		for (int i = 0; i < 4; i++)
		{
			int yy = y + dy[i];
			int xx = x + dx[i];

			if (safe(yy, xx) && board[yy][xx] == 0)
			{

				q.push({ yy,xx });
				board[yy][xx] = board[y][x] + 1;
			}
		}
	}

	return -1;
}





int32_t main()
{
	cin >> N >> M;
	for (int y = 0; y < N; y++)
	{
		string a;
		cin >> a;
		for (int x = 0; x < M; x++)
		{
			board[y][x] = a[x] - '0';

		}
	}
	cout << bfs();
	return 0;
}

