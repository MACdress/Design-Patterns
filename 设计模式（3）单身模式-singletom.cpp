#include<iostream>
using namespace std;
class My{
	private:
		int i;
		int j;
		static My * m;
		My(int i,int j){
			this->i=i;
			this->j=j; 
		} 
	public:
		static My * Creat(int i,int j ){
			if(m==NULL){
				m=new My(i,j);
			}
		}
		void Print(){
			cout<<"i="<<i<<endl;
			cout<<"j="<<j<<endl;
		}
};
My* My::m=NULL;
int main(void)
{
	My *my;
	my=My::Creat(3,5);
	my->Print();
	delete my;
}