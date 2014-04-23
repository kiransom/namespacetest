#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

class ThreadSafeSingleton {
  static ThreadSafeSingleton* _instance;
  static std::once_flag flag;
public:
  static ThreadSafeSingleton& instance() {
    std::call_once(flag, []() {  _instance = new ThreadSafeSingleton();
                                 std::cout << "thread id " << std::this_thread::get_id() << std::endl; 
                                 std::cout << "created singleton " << std::endl;

                                } );
    std::cout << "thread id " << std::this_thread::get_id() << std::endl; 
    std::cout << "returning singleton " << std::endl;
    return *_instance;
  }
  ~ThreadSafeSingleton() {
    delete _instance;
  }
};

ThreadSafeSingleton* ThreadSafeSingleton::_instance = 0;
std::once_flag ThreadSafeSingleton::flag;

int mainThreadSafeSingleton() {
  
  std::vector<std::thread> vthreads;
  for(int i=0; i < 20; ++i) {
    vthreads.push_back(std::thread(ThreadSafeSingleton::instance));
  }

  for(int i=0; i < 20; ++i) {
    vthreads[i].join();
  }

  return 0;
}