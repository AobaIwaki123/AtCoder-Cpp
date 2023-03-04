#include <bits/stdc++.h>
using namespace std;

int main() {
    
	int N;
	cin>>N;
	
	long long ans = 0;
	
	for(int i=1;i<N;i++){
		int X = i,Y = N-i; // X,Yを定める
		long long x = 0,y = 0;
		for(int j=1;j*j<=X;j++){
			if(X%j==0){
				x++; // A,Bが適切なら+1
				if(X!=j*j)x++; // Xが平方数でないなら+1
			}
		}
		for(int j=1;j*j<=Y;j++){
			if(Y%j==0){
				y++; // C,Dが適切なら+1
				if(Y!=j*j)y++; // Yが平方数でないなら+1
			}
		}
		ans += x * y; // Xの選び方とYの選び方を掛け合わせてたす
	}
	
	cout<<ans<<endl;
	
	return 0;
}
