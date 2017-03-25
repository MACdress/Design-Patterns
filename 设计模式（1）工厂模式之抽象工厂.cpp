//��ģʽ��������ģʽ���Խ���� 
//һ����������һ����ƽ�����ڲ�Ʒ�ĵ����ӣ����ٿͻ��˵��鷳 
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
//B��C������A����һ�£�����ʡ�ԡ� 
int main(void){
	Factory *f=new FactoryA(); 
	f->send();
	delete f;
	f=NULL;
	return 0;
}