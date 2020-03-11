#include<boost/lexical_cast.hpp>
#include<string>
#include<iostream>
int main(){
	std::string si("1");
	std::string sj("1");
	int i=boost::lexical_cast<int>(si);
	int j=boost::lexical_cast<int>(sj);
	try{
		std::string sk("foo");
		int k=boost::lexical_cast<int>(sk);
		std::cout<<k<<std::endl;
	}catch(const boost::bad_lexical_cast &e){
		std::cerr<<e.what()<<std::endl;
	}
	return 0;
}
