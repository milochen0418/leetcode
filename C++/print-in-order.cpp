#include <semaphore.h>

class Foo {
    //https://leetcode.com/problems/print-in-order
protected:
    sem_t first_done;
    sem_t second_done;
public:
    //Semaphore API sem_init, sem_wait, sem_post
    //https://blog.csdn.net/houxiaoni01/article/details/103316566
    //Detail of video to teach how semaphore using in share memeory
    //https://www.youtube.com/watch?v=ukM_zzrIeXs
    
    /*
        int sem_init(sem_t *sem, int pshared, unsigned int value);
        此函數初始化由sem指向的信號對象，設置它的共享選項，並給它一個初始的整數值
        pshared 為 0 表示此信號量是當前進程的局部信號量，否則信號量就可以在多進程之間共享，
        value 為 sem 的初始值。調用成功時返回0，失敗返回-1
        
        int sem_wait(sem_t *sem)
        該函數相當於以原子操作的方式將信號量的值減1。原子操作就是，如果兩個線程企圖同時給一個信號量
        加1或減1時，它們之間不會互相干。
        等待信號量，如果個號量的值大於0，將信號量的值減1，立即返回，如果信號量的值為零，則線程阻塞。
        相當於P操作。
        成功返回0，失敗返回-1。sem 指向的對象是由 sem_init 調用初始化的信號量
        
        int sem_post(sem_t *sem)
        該函數用於雨原子操作的方式將信號量的值加1。
        釋放信號量，讓信號量的值加1。
        相當於V操作。
        與sem_wait 一樣，sem 指向的對象是由sem_init調用初始化的
        信號量。調用成功時返回0，失敗返回-1
        
        int sem_destroy(sem_t *sem)
        該函數對於用完的信號量的清理。成功時返回0，失敗時返回-1
    */
    
    Foo() {
        sem_init(&first_done,0,0);
        sem_init(&second_done,0,0);
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        sem_post(&first_done);
    }

    void second(function<void()> printSecond) {
        sem_wait(&first_done);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        sem_post(&second_done);

    }

    void third(function<void()> printThird) {
        sem_wait(&second_done);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};