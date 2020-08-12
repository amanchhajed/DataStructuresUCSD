#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>


using std::vector;
using std::cin;
using std::cout;

struct Worker {
  int i;
  long long time;

  bool operator()(const Worker& a, const Worker& b) {
    return a.time==b.time ? a.i>b.i : a.time > b.time;
  }
};

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;
  std::priority_queue<Worker, vector<Worker>, Worker> threads;
  

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
    for(int i=0;i<num_workers_;i++) {
      threads.push(Worker{i, 0});
    }
  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    // vector<long long> next_free_time(num_workers_, 0);
    // for (int i = 0; i < jobs_.size(); ++i) {
    //   int duration = jobs_[i];
    //   int next_worker = 0;
    //   for (int j = 0; j < num_workers_; ++j) {
    //     if (next_free_time[j] < next_free_time[next_worker])
    //       next_worker = j;
    //   }
    //   assigned_workers_[i] = next_worker;
    //   start_times_[i] = next_free_time[next_worker];
    //   next_free_time[next_worker] += duration;
    // }
    for(int i=0;i<jobs_.size();i++) {
      Worker temp = threads.top();
      assigned_workers_[i] = temp.i;
      start_times_[i] = temp.time;
      threads.pop();
      temp.time += jobs_[i];
      threads.push(temp);
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
