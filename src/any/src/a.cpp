/*
 * boost::any is used to store any type of value in a variable
 * many scripting languages like javascript provides a type capable of storing any data type supported by the language
 * with boost::any any type of value can be assigned to
 * a variable by just making its datatype boost::any
 */
#include<iostream>
#include<boost/any.hpp>
int main(int argc,char** argv){
	boost::any a;
	a=0;
	std::cout<<boost::any_cast<int>(a)<<std::endl;
	a=(double)0.1;
	std::cout<<boost::any_cast<double>(a)<<std::endl;
	a=(float)0.2;
	std::cout<<boost::any_cast<float>(a)<<std::endl;
	a=(char)'a';
	std::cout<<boost::any_cast<char>(a)<<std::endl;
	a=std::string("lorem");
	std::cout<<boost::any_cast<std::string>(a)<<std::endl;
	return 0;
}
