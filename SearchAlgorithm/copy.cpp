#include <bits/stdc++.h>
using namespace std;

const static long long NIL = -1;
const long long INF = 1LL << 60;
using ll = long long;

int main(){
	int W, H;
	cin >> W >> H;
	int h = H + 2;
	int w = W + 2;
	vector<vector<int>> fi(h, vector<int>(w, 0));
	for(int i = 1; i <= H; i++){
		for(int j = 1; j <= W; j++){
			cin >> fi[i][j];
		}
	}
	// x の偶奇による
	int dx[2][6] = {
		{1, 0, -1, 0, 1, -1},
		{1, 0, -1, 0, 1, -1}
	};
	int dy[2][6] = {
		{0, 1, 0, -1, -1, -1},
		{0, 1, 0, -1, 1, 1}
	};
		
	queue<pair<int, int>> q;
	q.emplace(0, 0);
	
	while(!q.empty()){
		pair<int, int> current = q.front();
		q.pop();
		int cx = current.first;
		int cy = current.second;
		for(int d = 0; d < 6; d++){
			int nx = cx + dx[cx % 2][d];
			int ny = cy + dy[cx % 2][d];
			if(nx < 0 || nx >= h || ny < 0 || ny >= w)continue;
			if(fi[nx][ny] == 1)continue;
			if(fi[nx][ny] == NIL)continue;
			fi[nx][ny] = NIL;
			q.emplace(nx, ny);
		}
	}

	int result = 0;
	for(int i = 1; i <= H; i++){
		for(int j = 1; j <= W; j++){
			if(fi[i][j] == NIL)continue;
			for(int d = 0; d < 6; d++){
				int nx = i + dx[i % 2][d];
				int ny = j + dy[i % 2][d];
				if(fi[nx][ny] == NIL){
					result++;
				}
			}
		}
	}

	cout << result << endl;
}
