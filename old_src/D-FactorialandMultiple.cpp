// 模範解答
#include <bits/stdc++.h>
using namespace std;

int main() {
	long long k,p,a,n,x,ans=1;
	cin >> k;
    // Kの平方根以下の回数ループする
	for(p=2;(p*p)<=k;p++){
		a=0;
        // 素因数の肩の整数aを求める
		while(k%p==0)k /= p, a++;
		n=0;
        // 素因数の個数aを含む最小の値nを求める
		while(a>0){
			n+=p;
			x=n;
            // xが持つ素因数の個数によってaを減じる
			while(x%p==0)x /= p,a--;
		}
        // 今まで計算したansよりもnが大きければ下限を更新する
		ans=max(ans,n);
	}
    // 上半分に素数の素因数が存在する場合に対応するためにmaxをとる。
	ans=max(ans,k);
	cout << ans <<endl;
	return 0;
}

// 別解
#include <iostream>
#include <numeric>
using namespace std;
typedef long long ll;
 
int main() {
	ll k;
	cin >> k;
    // Kの値の範囲の平方根だけ回す
	for (ll i = 1; i <= 2000000; i++) {
        // iの持つ全ての素因数を除去する
		k /= gcd(k, i);
		if (k == 1) {
			cout << i << '\n';
			return 0;
		}
	}
	cout << k << '\n';
}

	