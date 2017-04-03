#include<iostream>//接口适配，实现了软件的复用，接口转换
using namespace std;
class Base{
	public:
		virtual void mythind()=0;
		virtual~Base(){
			cout<<"Base.des"<<endl;
		} 
};
class adaptA:public Base{
	public:
		void mythind(){
			cout<<"adaptA()"<<endl;
		}
		~adaptA(){
			cout<<"adaptA.des"<<endl;
		}
};
class adapter{
	public:
		void mythind(int i){
			cout<<"adapter.d"<<endl;
			cout<<i<<endl;
		}
		~adapter(){
			cout<<"adapter.des"<<endl;
		}
};
class adaptB:public Base{
	private:
		adapter *p;
	public:
		adaptB(adapter *t=NULL){
			p=t;
		}
		void mythind(){
			int t;
			cin>>t;
			p->mythind(t);
		}
		~adaptB(){
			cout<<"adapteB.des"<<endl;
			delete p;
			p=NULL;
		}
};
int main(void){
	Base *base=new adaptB(new adapter());
	base->mythind();
	delete base;
	base=NULL;
	return 0;
}
