//�ṹ�����ģʽ�еĴ���ģʽ
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
			cout<<"���ȹ���ʵ��"<<endl;
		}
};
//�˴����ж��ַ���ģʽ���ܵȴ�����ȥ�ã�����ģʽ���һ�£����ڴ�ʡ�ԣ�
class Proxy:public Base{//���� 
	private:
		Base *t;
		public:
			Proxy(Base *t){
				this->t=t;
			} 
			void method(){
				t->method();
				cout<<"������ʵ��"<<endl; 
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
