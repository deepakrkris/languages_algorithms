#include <iostream>
#include <thread>

using namespace std;

void helloFunction(){
  std::cout << "Hello from a function. " <<  std::this_thread::get_id() << std::endl;
}

class HelloFunctionObject{
  public:
    void operator()() const {
      std::cout << "Hello from a function object. " << std::this_thread::get_id() << std::endl;
    }
};

int main(){
  cout << endl << endl << " START " <<  " Threads " <<  std::this_thread::get_id() << endl;
  cout << std::string(20, '_') << endl;

  thread function_thread(helloFunction);
  HelloFunctionObject helloFunctionObject;
  thread functor_thread(helloFunctionObject);

  thread lambda_thread([](){ cout << "Hello From a lambda. " <<  std::this_thread::get_id() << endl; });

  function_thread.join();
  functor_thread.join();
  lambda_thread.join();

  cout << std::string(20, '_') << endl;
}
