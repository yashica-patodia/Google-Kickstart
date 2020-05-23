#include <bits/stdc++.h>
using namespace std;

int L[303], R[303];
int A[303][303], B[303][303], D[303][303], F[303];

int solve(int N)
{
    stack<int> S;

    for(int i=1; i<=N; i++)
    {
        while(!S.empty() && F[S.top()] >= F[i])
            S.pop();
        
        if(S.empty())
            L[i] = 1;
        else
            L[i] = S.top() + 1;
        
        S.push(i);
    }

    while(!S.empty())
        S.pop();
    
    for(int i=N; i>=1; i--)
    {
        while(!S.empty() && F[S.top()] > F[i])
            S.pop();
        
        if(S.empty())
            R[i] = N;
        else
            R[i] = S.top() - 1;
        
        S.push(i);
    }

    int ans = 0;
    
    for(int i=1; i<=N; i++)
        ans = max(ans, F[i] * (R[i] - L[i] + 1));

    return ans;
}

int func(int R, int C, int K)
{
    int ans = 0;

    for(int i=1; i<=R; i++)
    {
        for(int j=1; j<=C; j++)
        {
            D[i][j] = 1;
            int left = A[i][j], right = A[i][j];

            for(int k=j-1; k>=1; k--)
            {
                left = min(left, A[i][k]);
                right = max(right, A[i][k]);

                if(right - left <= K)
                    D[i][j]++;
                else
                    break;
            }
        }
    }
    
    for(int i=1; i<=C; i++)
    {
        for(int j=1; j<=R; j++)
            F[j] = D[j][i];
        
        ans = max(ans, solve(R));
    }

    return ans;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int T;
    cin >> T;

    for(int test=1; test<=T; test++)
    {
        cout << "Case #" << test << ": ";

        int R, C, K;
        cin >> R >> C >> K;

        for(int i=1; i<=R; i++)
            for(int j=1; j<=C; j++)
                cin >> A[i][j];
        
        cout << func(R, C, K) << "\n";
    }

    return 0;
}
