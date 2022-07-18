class product{
public:
    product(){};
    virtual ~product(){};
    void setA(){}
    void setB(){}
    void setC(){}
    void show(){}
};
class builder{
public:
    builder(){pro = new product;};
    virtual ~builder(){};
    virtual void buildpartA(){}
    virtual void buildpartB(){}
    virtual void buildpartC(){}
    virtual product* getResult(){return pro;}
    product* pro;
};
class director{
public:
    director(){}
    virtual ~director(){}
    builder* bu;
    product* construct(){
        b->buildpartA();
        b->buildpartB();
        b->buildpartC();
        return b->getResult();
    }
    void setbuilder(builder* bu){b = bu;}
private:
    builder* b;
};
class productAbuilder : public builder{
public:
    productAbuilder(){}
    virtual ~productAbuilder(){}
    virtual void buildpartA(){ pro->setA();}
    virtual void buildpartB(){ pro->setB();}
    virtual void buildpartC(){ pro->setC();}
};
class productBbuilder : public builder{
    productBbuilder(){}
    virtual ~productBbuilder(){}
    virtual void buildpartA(){ pro->setA(); }
    virtual void buildpartB(){ pro->setB();}
    virtual void buildpartC(){ pro->setC();}
};
/*
 *int main(){
    productAbuilder* pab = new productAbuilder();
    director dir;
    dir.setbuilder(pab);
    product* pro = dir.construct();
    pro.show();
    delete builder;
    delete pro;
    return 0;

 }
 *
 *
 * */
