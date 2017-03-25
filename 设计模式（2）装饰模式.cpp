#include<iostream>
using namespace std;
class Base{
	private:
		Base *next;
	public:
		Base(Base *t=NULL){
			cout<<"Base.gouzao"<<endl;
			next=t;
		}
		virtual void fun(){
			cout<<"Base.fun"<<endl;
			if(next){
				next->fun();
			}
		}
		virtual ~Base(){
			cout<<"Base.des"<<endl;
		}
};
class A:public Base{
	public:
		A(Base *t=NULL):Base(t){
			cout<<"A.gouzao"<<endl;
		}
		void fun(){
			cout<<"A.fun()"<<endl;
			Base::fun();
		}
		~A(){
			cout<<"A.des"<<endl;
		}
};
class B:public Base{
	public:
		B(Base *t=NULL):Base(t){
			cout<<"B.gouzao"<<endl;
		}
		void fun(){
			cout<<"B.fun("<<endl;
			Base::fun();
		}
		~B(){
			cout<<"B.des"<<endl;
		}
};
class Decorater:public Base{
	public:
		Decorater(Base *t=NULL):Base(t){
			cout<<"Decorater.gouzao"<<endl;
		}
		 virtual void fun(){
		}
		~Decorater(){
			cout<<"Decorater.des"<<endl;
		}
};
class D1:public Decorater{
	public:
		D1(Base *t=NULL):Decorater(t){
			cout<<"D1.gouzao()"<<endl;
		}
		void fun(){
			cout<<"D1.fun()"<<endl;
			Base::fun();
		}
		~D1(){
			cout<<"D1.des"<<endl;
		}
};
class D2:public Decorater{
	public:
		D2(Base *t=NULL):Decorater(t){
			cout<<"D2.gouzao()"<<endl;
		}
		void fun(){
			cout<<"D2.fun()"<<endl;
			Base::fun();
		}
		~D2(){
			cout<<"D2.des"<<endl;
		}
};
class D3:public Decorater{
	public:
		D3(Base *t=NULL):Decorater(t){
			cout<<"D3.gouzao()"<<endl;
		}
		void fun(){
			cout<<"D3.fun()"<<endl;
			Base::fun();
		}
		~D3(){
			cout<<"D3.des"<<endl;
		}
};
class My{
	private:
		Base *base;
	public:
		My(Base *t=NULL){
			base=t;
		}
		void dofun(){
			base->fun();
		}
		~My(){
			cout<<"My.des"<<endl;
		}
};
int main(void)
{
	D3 *d3=new D3();
	D2 *d2=new D2(d3);
	A *a=new A(d2);
	My *my=new My(a);
	my->dofun();
	delete my;
	my=NULL;
	delete a;
	a=NULL;
	delete d2;
	d2=NULL;
	delete d3;
	d3=NULL;
	return 0;
}