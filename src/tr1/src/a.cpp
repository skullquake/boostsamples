#include<boost/smart_ptr/shared_ptr.hpp>
#include<iostream>
class A{
	public:
		A(){};
		~A(){};
	private:
	protected:
};
class B{
	public:
		B(){};
		~B(){};
		void set_a(boost::shared_ptr<A> aP){
			this->m_a=aP;
		};
		boost::shared_ptr<A> get_a(){
			return this->m_a;
		};
	private:
		boost::shared_ptr<A> m_a;
	protected:
};
int main(){
	boost::shared_ptr<A> ptr_a(new A);
	B b0;
	B b1;
	B b2;
	b0.set_a(ptr_a);
	b1.set_a(ptr_a);
	b2.set_a(ptr_a);
	std::cout<<ptr_a<<std::endl;
	std::cout<<b0.get_a()<<std::endl;
	std::cout<<b1.get_a()<<std::endl;
	std::cout<<b2.get_a()<<std::endl;
	//free(ptr_a.get());
	ptr_a.reset();
	std::cout<<ptr_a<<std::endl;
	std::cout<<b0.get_a()<<std::endl;
	std::cout<<b1.get_a()<<std::endl;
	std::cout<<b2.get_a()<<std::endl;
	return 0;
}
