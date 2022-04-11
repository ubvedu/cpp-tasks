#include <iostream>
#include <cstddef>

using namespace std;

struct Task {
    float duration;
    float rel_priority;
    size_t index;
};

Task read_task(size_t index) {
    float duration, priority;
    cin >> duration >> priority;
    return Task{duration, priority / duration, index};
}

bool compare(Task const &a, Task const &b) {
    return a.rel_priority > b.rel_priority;
}

// 5 tasks
// 3 3, 3 3, 3 3, 5 5, 5 5,
// 9 hours

int main() {
    size_t n;
    cin >> n;
    auto tasks = new Task[n];
    for (size_t i = 0; i < n; i++) {
        tasks[i] = read_task(i);
    }
    float time;
    cin >> time;
    sort(tasks, tasks + n, compare);
    auto work_times = new float[n];
    for (size_t i = 0; i < n && time > 0; i++) {
        auto work_time = min(tasks[i].duration, time);
        work_times[tasks[i].index] = work_time;
        time -= work_time;
    }
    for (size_t i = 0; i < n; i++) {
        cout << work_times[i] << " ";
    }
    cout << endl;
    return 0;
}