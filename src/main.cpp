#include <chrono>
#include <thread>
#include "atomic/Resource.h"

int main()
{
    /*
    * Use some code for run with the generated executable here
    * 
    * Example:
    * 
    * #include "hello/hello.cpp"
    * 
    * hello();
    */
    std::shared_ptr<Resource> resource = std::make_shared<Resource>();

    auto t1 = std::thread([&resource]() {
        resource->request([](std::string status) {
            std::cout << status << std::endl;
        });
    });

    auto t2 = std::thread([&resource]() {
        auto start = std::chrono::high_resolution_clock::now();
        std::this_thread::sleep_for(std::chrono::milliseconds(001));
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> elapsed = end - start;
        
        resource->cancel();
        
        std::cout << "Waited " << elapsed.count() << " ms" << std::endl;
    });

    t1.join();
    t2.join();

    return 0;
}