#include <chrono>
#include <iostream>
#include <vector>

#include "ThreadPool.h"

class MyClass {
   public:
    int doSomething(int x, int y) {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        return x + y;
    }
};

int main() {
    ThreadPool pool(4);
#if 0
    std::vector<std::future<int> > results;

    for (int i = 0; i < 8; ++i) {
        results.emplace_back(pool.enqueue([i] {
            std::cout << "hello " << i << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "world " << i << std::endl;
            return i * i;
        }));
    }

    for (auto&& result : results) {
        // std::cout << result.get() << ' ';
    }
    std::cout << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(1));
#endif
    MyClass obj;

    auto doSomethingWrapper = [&obj](int x, int y) { return obj.doSomething(x, y); };
    auto f1 = pool.enqueue(doSomethingWrapper, 3, 4);
    std::cout << f1.get() << std::endl;

    auto doSomethingBound = std::bind(&MyClass::doSomething, &obj, std::placeholders::_1, std::placeholders::_2);

    auto f2 = pool.enqueue(doSomethingBound, 5, 6);
    std::cout << f2.get() << std::endl;

    auto f3 = pool.enqueue(obj, &MyClass::doSomething, 1, 2);
    std::cout << f3.get() << std::endl;

    return 0;
}
