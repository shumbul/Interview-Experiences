#include <bits/stdc++.h>
using namespace std;
struct Student {
    int start, end;
};
int main() {
    int n, k;
    cin >> n;
    vector<Student> students(n);
    for (int i = 0; i < n; i++) 
      {
        cin >> students[i].start;
      }  
    for (int i = 0; i < n; i++) 
      {
        cin >> students[i].end;
      }
    cin >> k;
    // Sort students by start time
    sort(students.begin(), students.end(), [](Student &a, Student &b) {
        return a.start < b.start;
    });
    priority_queue<int, vector<int>, greater<int>> minHeap; // stores end times
    long long totalTime = 0;
    int prevTime = -1;
    for (auto &s : students) {
        // Remove students whose exams ended before current start time
        while (!minHeap.empty() && minHeap.top() < s.start) {
            int endTime = minHeap.top();
            minHeap.pop();
            if ((int)minHeap.size() + 1 >= k) {
                // +1 because we just removed this student
                totalTime += endTime - prevTime + 1;
            }
            prevTime = endTime + 1;
        }
        // If we already have k-1 students before adding current
        if ((int)minHeap.size() >= k - 1) {
            if (prevTime == -1) 
                prevTime = s.start;
            else 
                prevTime = min(prevTime, s.start);
        }
        minHeap.push(s.end);
    }
    // Process remaining students in heap
    while (!minHeap.empty()) {
        int endTime = minHeap.top();
        minHeap.pop();
        if ((int)minHeap.size() + 1 >= k) {
            totalTime += endTime - prevTime + 1;
        }
        prevTime = endTime + 1;
    }
    cout << totalTime << "\n";
    return 0;
}
