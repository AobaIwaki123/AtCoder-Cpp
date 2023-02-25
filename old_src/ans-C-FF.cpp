#include<iostream>
#include<set>
#include<utility>

int main(void)
{
    using namespace std;
    
    unsigned N, Q;
    cin >> N >> Q;

    // フォロー関係を集合followsに保持する。
    set<pair<unsigned, unsigned>> follows;
    // 与えられるクエリを次の様に言い換える。
    // 1. 集合Sに順序対(A,B)を追加する。
    // 2. 集合Sから順序対(A,B)を取り除く。
    // 3. 順序対(A,B), (B,A)がいずれもSに含まれているか判定する。
    for(unsigned _{}; _ < Q; ++_)
    {
        unsigned type, A, B;
        cin >> type >> A >> B;
        if(type == 1) 
        {
            follows.emplace(A,B);
        }
        else if(type == 2)
        {
            follows.erase({A,B});
        } 
        else
        {
            cout << (follows.count({A,B}) && follows.count({B,A}) ? "Yes" : "No") << endl;
        } 
    }
    return 0;
}