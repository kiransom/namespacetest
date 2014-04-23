#include <iostream>
#include <memory>
#include <vector>
#include <thread>

class ThreadSafeSingleton {
  static std::unique_ptr<ThreadSafeSingleton> _instance;
public:
  ~ThreadSafeSingleton() {
    std::cout << "ThreadSafeSingleton says goodbye\n";
  }

  static ThreadSafeSingleton& instance() {
    // in C++11 static declarations is threadsafe. It is called only once. 
    // And all concurrent control wait till the object is inited
    static auto poor_mans_call_once = ( []() {  
      _instance = std::unique_ptr<ThreadSafeSingleton>(new ThreadSafeSingleton());
      std::cout << "thread id " << std::this_thread::get_id() << std::endl; 
      std::cout << "created singleton " << std::endl;
      }(), true );
    std::cout << "thread id " << std::this_thread::get_id() << std::endl; 
    std::cout << "returning singleton " << std::endl;
    return *_instance;
  }
};

std::unique_ptr<ThreadSafeSingleton> ThreadSafeSingleton::_instance;

int mainPoorManSubscribePublish() {
  
  std::vector<std::thread> vthreads;
  for(int i=0; i < 20; ++i) {
    vthreads.push_back(std::thread(ThreadSafeSingleton::instance));
  }

  for(int i=0; i < 20; ++i) {
    vthreads[i].join();
  }

  return 0;
}
