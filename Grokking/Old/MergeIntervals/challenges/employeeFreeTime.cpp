/*
For ‘K’ employees, we are given a list of intervals representing each employee’s working hours. Our goal is to determine if there is a free interval which is common to all employees. You can assume that each list of employee working hours is sorted on the start time.

Example 1:

Input: Employee Working Hours=[[[1,3], [5,6]], [[2,3], [6,8]]]
Output: [3,5]
Explanation: All the employees are free between [3,5].

Example 2:

Input: Employee Working Hours=[[[1,3], [9,12]], [[2,4]], [[6,8]]]
Output: [4,6], [8,9]
Explanation: All employees are free between [4,6] and [8,9].

Example 3:

Input: Employee Working Hours=[[[1,3]], [[2,4]], [[3,5], [7,9]]]
Output: [5,7]
Explanation: All employees are free between [5,7].
*/

using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class Interval {
 public:
  int start = 0;
  int end = 0;

  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class EmployeeFreeTime {
 public:
  struct startCompare {
    bool operator()(const pair<Interval, pair<int, int>> &x,
                    const pair<Interval, pair<int, int>> &y) {
      return x.first.start > y.first.start;
    }
  };

  static vector<Interval> findEmployeeFreeTime(const vector<vector<Interval>> &schedule) {
    vector<Interval> result;
    if (schedule.empty()) {
      return result;
    }

    // PriorityQueue to store one interval from each employee
    priority_queue<pair<Interval, pair<int, int>>, vector<pair<Interval, pair<int, int>>>,
                   startCompare>
        minHeap;

    // insert the first interval of each employee to the queue
    cout << "STEP 1: " << " ";
    for (int i = 0; i < schedule.size(); i++) {
      minHeap.push(make_pair(schedule[i][0], make_pair(i, 0)));
      cout << schedule[i][0].start << "," << schedule[i][0].end << "  ";
    }
    cout << "\n";
    // [({1,3}, (0,0)), ({2,3}, (1,0))]
    Interval previousInterval = minHeap.top().first;
    // prevInterval = {1,3}
    cout << "previous interval is: " << minHeap.top().first.start <<  "," << minHeap.top().first.end << "\n";
    while (!minHeap.empty()) {
      auto queueTop = minHeap.top();
      cout << "queueTop is: " << minHeap.top().first.start << "," << minHeap.top().first.end << " //// " << minHeap.top().second.first << "," << minHeap.top().second.first << "\n";
      // queueTop = ({2,3}, (1,0))
      minHeap.pop();
      // []
      // if previousInterval is not overlapping with the next interval, insert a free interval
      if (previousInterval.end < queueTop.first.start) {
        cout << previousInterval.end << " is less than: " << queueTop.first.start << "\n";
        // if (3) < (2)
        result.push_back({previousInterval.end, queueTop.first.start});
        cout << "Pushing : " << previousInterval.end << "," << queueTop.first.start << "\n";
        previousInterval = queueTop.first;
      } else {  // overlapping intervals, update the previousInterval if needed
        if (previousInterval.end < queueTop.first.end) {
          previousInterval = queueTop.first;
        }
      }

      // if there are more intervals available for the same employee, add their next interval
      vector<Interval> employeeSchedule = schedule[queueTop.second.first];
      if (employeeSchedule.size() > queueTop.second.second + 1) {
        
        cout << "More intervals available " << " (Next position: " << queueTop.second.second + 1 << " is less than schedule size: " << employeeSchedule.size() << ") " <<"\n";
        minHeap.push(make_pair(employeeSchedule[queueTop.second.second + 1],
                               make_pair(queueTop.second.first, queueTop.second.second + 1)));
        cout << "adding to minHeap: " << employeeSchedule[queueTop.second.second + 1].start <<  "," << employeeSchedule[queueTop.second.second + 1].end << "\n";
      }
    }

    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<Interval>> input = {{ {1,3}, {5, 6}}, {{2, 3}, {6, 8}}};
  vector<Interval> result = EmployeeFreeTime::findEmployeeFreeTime(input);
  cout << "Free intervals: ";
  for (auto interval : result) {
    cout << "[" << interval.start << ", " << interval.end << "] ";
  }
  cout << endl;

  input = {{{1, 3}, {9, 12}}, {{2, 4}}, {{6, 8}}};
  result = EmployeeFreeTime::findEmployeeFreeTime(input);
  cout << "Free intervals: ";
  for (auto interval : result) {
    cout << "[" << interval.start << ", " << interval.end << "] ";
  }
  cout << endl;

  input = {{{1, 3}}, {{2, 4}}, {{3, 5}, {7, 9}}};
  result = EmployeeFreeTime::findEmployeeFreeTime(input);
  cout << "Free intervals: ";
  for (auto interval : result) {
    cout << "[" << interval.start << ", " << interval.end << "] ";
  }
}
