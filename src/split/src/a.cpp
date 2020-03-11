#include<iostream>
#include<boost/algorithm/string.hpp>
int main(int argc,char**argv){
	std::string a("foo|bar|baz");
	std::vector<std::string> b;
	boost::split(
		b,
		a,
		boost::is_any_of("|")
	);
	for(auto c:b){
		std::cout<<c<<std::endl;
	}
	return 0;
}
