#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
class Thread
{
public:
    long long num;
    long long time;
};

struct Compare {
    bool operator () (const Thread &a, const Thread &b) {
        if (a.time == b.time)
            return a.num > b.num;
        return a.time > b.time;

    }
};

class JobQueue {
 private:
  int n;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> n >> m;
    jobs_.resize(m);
    assigned_workers_.resize(m);
    start_times_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {

    priority_queue <Thread, vector<Thread>, Compare > next_free_time;
    for (int i = 0; i < n ; i ++) {
        Thread x;
        x.num = i;
        x.time = 0;
        next_free_time.push(x);
    }

    for (int i = 0; i < jobs_.size(); ++i) {
      int duration = jobs_[i];

      Thread next_thread = next_free_time.top();
      next_free_time.pop();

      assigned_workers_[i] = next_thread.num;
      start_times_[i] = next_thread.time;
      next_thread.time += duration;

      next_free_time.push(next_thread);
    }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
