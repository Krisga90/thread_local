#include <iostream>
#include <random>
#include <thread>
#include <vector>

thread_local std::mt19937 mt;
static std::mt19937 SMT;

void func() {
  std::uniform_int_distribution<int> dist(0, 100);
  std::cout << "thread ID: " << std::this_thread::get_id()
            << "\n thread_local: ";

  for (int i = 0; i < 10; i++) {
    std::cout << dist(mt) << ", ";
  }
  std::cout << "\n static: ";
  for (int i = 0; i < 10; i++) {
    std::cout << dist(SMT) << ", ";
  }
  std::cout << "\n";
}

int main() {

  std::thread thr1(func);
  thr1.join();

  std::thread thr2(func);
  thr2.join();
  return 0;
}
