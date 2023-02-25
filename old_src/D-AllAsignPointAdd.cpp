// 長さNの数列Aが与えられれる。
// Q個のクエリが与えれるので、順番に全てを処理する。
// 1 xq : Aの全ての要素にxqを代入する。
// 2 iq xq : A[iq]にxqを加える。
// 3 iq : A[iq]の値を出力する。
// 入力
// N
// A[0] A[1] ... A[N-1]
// Q
// query1
// query2
// ...
// queryQ

#include<iostream>
#include<vector>
#include<numeric>

int main(){
    using namespace std;

    unsigned N;
    cin >> N;

    // 列をbaseからの差分で管理
    vector<unsigned long>A(N);
    unsigned base{};

    for(auto &&a : A) cin >> a;
    A.emplace(begin(A));

    // 差分が0出ないかもしれない場所
    // はじめは、1,...,Nすべて
    vector<unsigned> added_index(N);
    iota(begin(added_index), end(added_index), 1U);

    unsigned Q;
    cin >> Q;

    for(unsigned _{}; _ < Q; ++_){
        unsigned type;
        cin >> type;
        if(type == 1){
            // 差分が0でないところを消去
            while(!empty(added_index)){
                A[added_index.back()] = 0;
                added_index.pop_back();
            }
        } else if(type == 2){
            // index番目の差分に加える
            unsigned index, value;
            cin >> index >> value;
            A[index] += value;
            added_index.emplace_back(index);
        } else{
            // baseにindex番目の差分を加える
            unsigned index;
            cin >> index;
            cout << base + A[index] << endl;
        }
    }
    return 0;
}