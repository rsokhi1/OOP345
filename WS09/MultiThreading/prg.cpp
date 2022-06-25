#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;
void add(unsigned long& value,mutex& key) {
   for (size_t i = 0; i < 100; i++) {
      //key.lock();
      lock_guard<mutex> lg(key); // So that if a exception is created while adding the ke automatically unlocks
      value++;
      //key.unlock();
   }
}

int main() {
   unsigned long value;
   int num = 1000;
   mutex key;
   for (int i = 0; i < num; i++) {
      value = 0;
      vector<thread> adds;
      for (int i = 0; i < 100; i++) {
         adds.push_back(thread(add, ref(value),ref(key)));
      }
      for (thread& a : adds) {
         a.join();
      }
      cout << value << " ";
   }
   cout << endl;
   return 0;
}