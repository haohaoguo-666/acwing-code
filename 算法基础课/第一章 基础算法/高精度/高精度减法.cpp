#include <iostream>
#include <vector>

using namespace std;

bool cmp(vector<int> &A, vector<int> &B)
{
    if(A.size() != B.size())return A.size() > B.size();
    for(int i = A.size() - 1;i >= 0;i--)
    if(A[i] !=  B[i])
        return A[i] > B[i];
    return true;
}


vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    for(int i = 0,t = 0;i < A.size();i++)
    {   
        //t来表示临时的结果
        t = A[i] - t;
        if(i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);
        if(t < 0)t = 1;
        else t = 0;

    }

    while(C.size() > 1 && C.back() == 0)C.pop_back();

    return C;
}

int main()
{
    string a, b;
    vector<int> A, B;
    cin >> a >> b;

    for(int i = a.size() - 1;i >= 0;i--)A.push_back(a[i] - '0');
    for(int i = b.size() - 1;i >= 0;i--)B.push_back(b[i] - '0');

    if(cmp(A,B))
    {
        vector<int> C = sub(A,B);

        for(int i = C.size() - 1;i >= 0;i--)printf("%d",C[i]);
    }
    else
    {
        vector<int> C = sub(B,A);
        printf("-");
        for(int i = C.size() - 1;i >= 0;i--)printf("%d",C[i]);
    }


}

