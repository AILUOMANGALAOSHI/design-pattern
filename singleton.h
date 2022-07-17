/*
 *对于local static 对象，其初始化发生在控制流第一次执行到该对象的初始化语句时。多个线程的控制流可能同时到达其初始化语句。

 在C++11之前，在多线程环境下local static对象的初始化并不是线程安全的。具体表现就是：如果一个线程正在执行local static对象的初始化语句但还没有完成初始化，此时若其它线程也执行到该语句，那么这个线程会认为自己是第一次执行该语句并进入该local static对象的构造函数中。这会造成这个local static对象的重复构造，进而产生内存泄露问题。所以，local static对象在多线程环境下的重复构造问题是需要解决的。

 而C++11则在语言规范中解决了这个问题。C++11规定，在一个线程开始local static 对象的初始化后到完成初始化前，其他线程执行到这个local static对象的初始化语句就会等待，直到该local static 对象初始化完成。
 *
 *
 * */

class Singleton{
public:
    static Singleton& getInstance(){
        static Singlenton Instance;
        return instance;
    }
private:
    Singleton(){}
    ~Singleton(){}
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

};
/*
 *由于在main函数之前初始化，所以没有线程安全的问题。但是潜在问题在于no-local static对象（函数外的static对象）在不同编译单元中的初始化顺序是未定义的。也即，static Singleton instance;和static Singleton& getInstance)(二者的初始化顺序不确定，如果在初始化完成之前调用 getInstance( 方法会返回一个未定义的实例。
 *
 * */
class SingletonEager{
public:
    static SingletonEager& getInstance(){
        return instance;
    }
private:
    SingletonEager(){}
    ~SingletonEager(){}
    SingletonEager(const SingletonEager&) = delete;
    SingletonEager operator=(const SingletonEager&) delete;
    static SingletonEager SingletonEager;
};
