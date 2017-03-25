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
	private:
		Product *p;
	public:
		Factory(int n){
			cout<<"Factory.cout"<<endl;
			switch(n){
				case 1:p=new ProductA();break;
				case 2:p=new ProductB();break;
				case 3:p=new ProductC();break;
			}
		}
		void send(){
			p->Do();
		}
		~Factory(){
			delete p;
			p=NULL;
			cout<<"Factory.des"<<endl;
		}
};
int main(void){
	int i;
	cin>>i;
	Factory *f=new Factory(i);
	f->send();
	delete f;
	f=NULL;
	return 0;
}
