//结构型设计模式中的代理模式
#include<iostream>
using namespace std;
class Base{
	public:
		virtual void method()=0;
		virtual ~Base(){
			cout<<"Base.des"<<endl;
		} 
}; 
class Source:public Base{
	public:
		void method(){
			cout<<"咖啡功能实现"<<endl;
		}
};
//此处还有都种方法模式功能等待代理去用，基本模式框架一致，故在此省略；
class Proxy:public Base{//代理 
	private:
		Base *t;
		public:
			Proxy(Base *t){
				this->t=t;
			} 
			void method(){
				t->method();
				cout<<"代理功能实现"<<endl; 
			}
			~Proxy(){
				delete t;
				t=NULL;
				cout<<"Proxy.des"<<endl;
			}
}; 
int main(void)
{
	Proxy *t=new Proxy(new Source);
	t->method();
	delete t;
	t=NULL;
	return 0;
 } 
