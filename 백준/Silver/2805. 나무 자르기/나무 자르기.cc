#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


bool possible(vector<int> tree, long long height, int N, int M)
{
    long long len = 0;
    //나무를 잘라본다
    for (int i = 0; i < N; i++)
    {
        if (tree[i] - height > 0)
        {
            len += tree[i] - height;
        }
    }


    if (len >= M)
        return true;

    return false;
}



int main(void)
{
    int N;
    long long M;

    cin >> N >> M;

    vector<int> tree(N);
    long long low = 1;

    for (int i = 0; i < N; i++)
    {
        cin >> tree[i];
    }

    sort(tree.begin(), tree.end());
    long long high = tree[N - 1];
    long long result = 0;

    while (low <= high)
    {
        long long mid = (low + high) / 2;

        if (possible(tree, mid,N,M))
        {
            result = max(result, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    cout << result << "\n";

    return 0;

}
