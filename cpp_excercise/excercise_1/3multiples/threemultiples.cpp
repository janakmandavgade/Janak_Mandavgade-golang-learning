#include <vector>
using namespace std;

vector<int> ThreeMultiple(vector<int> &arr)
{
    int n = arr.size();
    vector<int> output;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 5 == 0)
        {
            output.push_back(arr[i]);
        }
    }

    return output;
}
