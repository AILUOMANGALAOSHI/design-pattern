
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
class abstractfactory{
public:
    factory(){}
    virtual ~factory(){}
    virtual product* createproduct() = 0;
};
class factoryA : abstractfactory{
public:
    factoryA(){}
    virtual ~factoryA(){}
    product* createproduct(){
        return new productA();
    }
};
class factoryB : abstractfactory{
public:
    factoryB(){}
    virtual ~factoryB(){}
    product* createproduct(){
        return new productB();
    }
};

product* factory::createproduct(string name){
    if(name == 'A')
        return new productA();
    if(name == 'B')
        return new productB();
    return nullptr;
}

/*
 *int main(){
    abstractfactory* fa = new factoryA();
    product* pro = fa->createproduct();
    pro->show();
    //析构
 }
 * */
