class product{
public:
    product(){}
    virtual ~product() = 0;
    virtual void use() = 0;
};
product::~product(){}//纯虚析构函数需要定义实现
class productA{
public:
    productA(){}
    virtual ~productA(){}
    virtual void show(){}
};
class productB{
public:
    productB(){}
    virtual ~productB(){}
    virtual void show(){}
};
class factory{
public:
    factory(){}
    virtual ~factory(){}
    static product* createproduct(string name);
};
product* factory::createproduct(string name){
    if(name == 'A')
        return new productA();
    if(name == 'B')
        return new productB();
    return nullptr;
};
