#include <bits/stdc++.h>
using namespace std; 
// int _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll;
typedef pair<ll, ll> P;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main(){
	int h, w, n;
	cin >> h >> w >> n;
	vector<pair<int, int>> cheeze(n);
	vector<string> b(h);
	for(int i = 0; i < h; i++){
		cin >> b[i];
	}

	int sx, sy;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			if(b[i][j] == '.' || b[i][j] == 'X')continue;
			if(b[i][j] == 'S'){
				sx = i;
				sy = j;
			}else{
				int idx = b[i][j] - '0' - 1;
				cheeze[idx] = make_pair(i, j);
			}
		}
	}

	queue<pair<int, int>> q;
	q.emplace(sx, sy);
	vector<vector<int>> init(h, vector<int>(w, 0));
	vector<vector<int>> dist(h, vector<int>(w, 0));
	int result = 0;
	vector<int> dx = {1, -1, 0, 0};
	vector<int> dy = {0, 0, 1, -1};
	int cheeze_idx = 0;
	int gx = cheeze[cheeze_idx].first;
	int gy = cheeze[cheeze_idx].second;
	while(!q.empty()){
		if(cheeze_idx == n)break;
		pair<int, int> current = q.front();
		q.pop();
		int cx = current.first;
		int cy = current.second;
		for(int i = 0; i < 4; i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if(nx < 0 || nx >= h || ny < 0 || ny >= w)continue;
			if(b[nx][ny] == 'X')continue;
			if(dist[nx][ny] > 0)continue;
			dist[nx][ny] = dist[cx][cy] + 1;
			q.emplace(nx, ny);
			if(nx == gx && ny == gy){
				result += dist[gx][gy];
				dist = init;
				cheeze_idx++;
				queue<pair<int, int>> temp;
				q = temp;
				q.emplace(gx, gy);
				gx = cheeze[cheeze_idx].first;
				gy = cheeze[cheeze_idx].second;
				break;
			}
		}
	}

	cout << result << endl;

}
