#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> q;
    for (int i = 0; i < (int)students.size(); i++)
        q.push(students[i]);

    int i = 0, count = 0;
    while (!q.empty() && count < (int)q.size()) {
        if (q.front() == sandwiches[i]) {
            q.pop();
            i++;
            count = 0;
        } else {
            q.push(q.front());
            q.pop();
            count++;
        }
    }
    return q.size();
}

int main() {
    int s_arr[] = {1, 1, 0, 0};
    int sand_arr[] = {0, 1, 0, 1};

    vector<int> students(s_arr, s_arr + 4);
    vector<int> sandwiches(sand_arr, sand_arr + 4);

    cout << countStudents(students, sandwiches) << endl;
    return 0;
}
