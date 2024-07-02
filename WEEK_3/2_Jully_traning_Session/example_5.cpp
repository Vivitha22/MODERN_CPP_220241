#include <iostream>
#include <thread>
#include <mutex>

class Bank
{
private:
    std::mutex mt;
    int32_t m_amount{1000};

public:
    Bank(int32_t amount) : m_amount{amount} {}
    ~Bank() = default;
    Bank() = default;
    Bank(Bank &&) = delete;
    Bank &operator=(const Bank &) = delete;
    Bank &operator=(const Bank &&) = delete;
    Bank(Bank&&)= delete;

    void Deposit()
    {
        for (int i = 0; i < 100; i++)
        {
            // creating an delay in the output
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
            mt.lock();
            m_amount += 10;
            mt.unlock();
        }
    }

    void Withdraw()
    {
        for (int i = 0; i < 100; i++)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
            mt.lock();
            m_amount -= 10;
            mt.unlock();
        }
    }

    int32_t amount() const { return m_amount; }
};

int main()
{
    Bank b1{1000};

    std::thread t1{&Bank::Deposit, &b1};
    std::thread t2{&Bank::Withdraw, &b1};

    t1.join();
    t2.join();

    std::cout << "The amount is :" << b1.amount() << "\n";
}