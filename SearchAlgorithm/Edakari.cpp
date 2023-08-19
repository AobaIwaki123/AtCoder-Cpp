int N, X, B[10], A[10];

bool dfs(int pos, int sum){
    if(pos == N){
        if(sum == X) return true;
        else return false;
    }
    // 枝刈り
    if(X < sum || sum + B[pos + 1] < X) return false;
    // 遷移
    bool I1 = dfs(pos+1, sum);
    bool I2 = dfs(pos+1, sum + A[pos + 1]);
    if(I1 == true || I2 == true) return true;
    return false;
}