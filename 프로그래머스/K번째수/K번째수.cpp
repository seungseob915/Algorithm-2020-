
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    int comm_size = commands.size();

    for (int m = 0; m < comm_size; m++) {
        vector<int> temp;
        int i = commands[m][0];
        int j = commands[m][1];
        int k = commands[m][2];

        for (int n = i - 1; n < j; n++)
            temp.push_back(array[n]);

        sort(temp.begin(), temp.end());
        answer.push_back(temp[k - 1]);
    }

    return answer;
}
