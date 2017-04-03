#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
class AbstractFile{
	private:string name;
	public:
	AbstractFile(string t){
		name=t;
	} 
	AbstractFile(){
		name="未命名文件"; 
	}
	virtual void out(){
		cout<<name<<" ";
	}
	virtual void deletes()=0;
	virtual ~ AbstractFile(){
		cout<<"AbstractFile.des"<<endl;
	}
}; 
class File:public AbstractFile{
	public:
		File(){}
		File(string t):AbstractFile(t){}
		void out(){
			AbstractFile::out();
		}
		void deletes(){
		}
		~File(){
			cout<<"File.des"<<endl;
		} 
};
class Folder:public AbstractFile{
	private:
		vector<AbstractFile*>vec;
	public:
		Folder(){}
		Folder(string t):AbstractFile(t){}
		void Add(AbstractFile*t){
			vec.push_back(t);
		}
		void out(){
			AbstractFile::out();
			cout<<endl;
			vector<AbstractFile*>::iterator i;
			for(i=vec.begin();i!=vec.end();i++){
				(*i)->out();
			}
		}
		void deletes(){
			vector<AbstractFile*>::iterator i;
			for(i=vec.begin();i!=vec.end();i++){
				(*i)->deletes();
				delete (*i);
			}
		}
		~Folder(){
			cout<<"Filder.des"<<endl; 
		}
};
int main(void){
	Folder *t1=new Folder("C:\\");
	t1->Add(new File("text1"));
	t1->Add(new File("text2"));
	t1->Add(new File());
	Folder *t2=new Folder("Wenjian:\\");
	t1->Add(t2);
	t2->Add(new File("xiaoming"));
	t2->Add(new File("name"));
	t2->Add(new File());
	Folder *t3=new Folder();
	t2->Add(t3);
	t1->out();
	t1->deletes();
	delete t1;
	return 0; 
}
