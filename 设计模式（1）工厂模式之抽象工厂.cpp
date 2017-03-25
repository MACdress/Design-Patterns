//该模式与适配器模式可以结合用 
//一个工厂负责一个铲平，便于产品的的增加，减少客户端的麻烦 
#include<iostream>
using namespace std;
class Product{
	public:
		virtual void Do(){
			cout<<"Product.Do"<<endl;
		}
		virtual ~Product(){
			cout<<"Product.des"<<endl;
		}
};
class ProductA:public Product{
	public:
		void Do(){
			cout<<"ProductA.Do"<<endl;
		}
		~ProductA(){
			cout<<"ProductA.des"<<endl;
		}
};
class ProductB:public Product{
	public:
		void Do(){
			cout<<"ProductB.Do"<<endl;
		}
		~ProductB(){
			cout<<"ProductB.des"<<endl;
		}
};
class ProductC:public Product{
	public:
		void Do(){
			cout<<"ProductC.Do"<<endl;
		}
		~ProductC(){
			cout<<"ProductC.des"<<endl;
		}
};
class Factory{
	protected:
		Product *p;
	public:
	virtual void send()=0;
	virtual~Factory(){
			delete p;
			p=NULL;
			cout<<"Factory.des"<<endl;
		}
};
class FactoryA:public Factory{
	public:
		FactoryA(){
			p=new ProductA();
			cout<<"Factory.cout"<<endl;
		}
		void send(){
			p->Do(); 
		}
		~FactoryA(){
			delete p;
			p=NULL;
			cout<<"FactoryA.des"<<endl;
		}
}; 
//B与C工厂与A工厂一致，这里省略。 
int main(void){
	Factory *f=new FactoryA(); 
	f->send();
	delete f;
	f=NULL;
	return 0;
}