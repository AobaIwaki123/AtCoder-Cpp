#include <bits/stdc++.h>
using namespace std;

int main() {
    
	int N;
	cin>>N;
	
	long long ans = 0;
	
	for(int i=1;i<N;i++){
		int X = i,Y = N-i; // X,Yを固定する
		long long x = 0,y = 0;
		for(int j=1;j*j<=X;j++){  // a*b<=Xの間ループする
			if(X%j==0){
				x++; // a,bが適切なら+1
				if(X!=j*j)x++; // Xが平方数出ないなら+1
			}
		}
		for(int j=1;j*j<=Y;j++){
			if(Y%j==0){
				y++; // c,dが適切なら+1
				if(Y!=j*j)y++; // Yが平方数出ないなら+1
			}
		}
		ans += x * y; // AB,CDの組み合わせを掛け合わせたものをたす
	}
	
	cout<<ans<<endl;
	
	return 0;
}
