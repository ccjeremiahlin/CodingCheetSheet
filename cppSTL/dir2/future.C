#include <iostream>
#include <future>
#include <thread>
using namespace std; 
int main()
{
    // future from a packaged_task
    packaged_task<int()> task([](){return 7;}); 
    future<int> f1 = task.get_future();
    task();
 
    // future from an async()
    future<int> f2 = async(launch::async, [](){return 8;}); 
 
    // waiting results
    std::cout << "Waiting..." << std::flush;

    f1.wait();
    f2.wait();

    //print out all results
    std::cout << "Done!\nResults are: ";
    cout<<f1.get()<<", "<<f2.get()<<endl;
}
