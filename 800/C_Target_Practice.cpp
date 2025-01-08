#include <bits/stdc++.h>
using namespace std;

const int score[10][10] = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,2,2,2,2,2,2,2,2,1},
	{1,2,3,3,3,3,3,3,2,1},
	{1,2,3,4,4,4,4,3,2,1},
	{1,2,3,4,5,5,4,3,2,1},
	{1,2,3,4,5,5,4,3,2,1},
	{1,2,3,4,4,4,4,3,2,1},
	{1,2,3,3,3,3,3,3,2,1},
	{1,2,2,2,2,2,2,2,2,1},
	{1,1,1,1,1,1,1,1,1,1}
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        char a[10][10];
        for (int i = 0; i < 10; i++) // 10
        {
            string s;
            cin >> s;
            for (int j = 0; j < 10; j++) // 10
            {
                a[i][j] = s[j];
            }
        }
        // input

        int total_score = 0;
        for (int i = 0; i < 10; i++) // 10
        {
            for (int j = 0; j < 10; j++) // 10
            {
                if (a[i][j] == 'X')
                {
                    total_score += score[i][j];
                }
            }
        }
        cout << total_score << endl;
    }
    return 0;
}

// tc - O(n^2) = O(100)
// sc - O(10*10) = O(100)
