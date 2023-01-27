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
    while(flag.test_and_set(std::memory_order_acquire)) {}
  }

  void unlock() {
    flag.clear(std::memory_order_release);
  }
};

Spinlock spin;

void workOnResource(int num) {
  std::this_thread::sleep_for(std::chrono::milliseconds(10 * num));
  for (int i = 0; i < 10; i++) {
    spin.lock();
    cout << " " << num << ((num == 10) ? '\n' : ' ');
    spin.unlock();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

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
