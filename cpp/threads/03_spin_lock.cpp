#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

using namespace std;

/*
Create ten workers with each owning a number from 1...10
Print following pattern where each thread prints one number per line

use spin lock

1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
1 2 3 5 4 6 7 8 9 10
1 2 3 5 4 6 7 8 9 10
1 2 3 5 4 6 7 8 9 10
*/

class Spinlock{
  std::atomic_flag flag;

public:
  Spinlock(): flag(ATOMIC_FLAG_INIT){}

  void lock() {
    while(flag.test_and_set()) {}
  }

  void unlock() {
    flag.clear();
  }
};

Spinlock spin;

void workOnResource(int num) {
  std::this_thread::sleep_for(std::chrono::milliseconds(20 * num));
  auto start = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < 10; i++) {
    spin.lock();
    cout << " " << num << ((num == 10) ? '\n' : ' ');
    spin.unlock();
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

  // Calculate the CPU load
  double cpu_load = (double)duration / (double)std::chrono::microseconds::period::den;
  std::cout << "CPU load: " << cpu_load * 100 << "%" << std::endl;

  std::cout << " Work done :  " << num << std::endl;
}

int main() {
    cout << string(20, '_') << endl;
    cout << endl << " START  spin lock " << endl;
    std::vector<std::thread> v;

    for (int i = 1; i <= 10; i++) {
        v.emplace_back(workOnResource, i);
    }

    cout << "hardware_concurrency() = "<< thread::hardware_concurrency() << endl;

    for (auto& t : v) {
        t.join();
    }

    cout << endl << string(20, '_') << endl;
}
