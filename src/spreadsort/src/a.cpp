#include<iostream>
#include<vector>
#include<boost/sort/spreadsort/spreadsort.hpp>
int main(int argc,char** argv){
	std::vector<double> a={
		1.1,
		5.5,
		-2.2,
		3.3,
		-7.7
	};
	for(auto b:a){
		std::cout<<b<<" ";
	}std::cout<<std::endl;
	boost::sort::spreadsort::spreadsort(begin(a), end(a));
	for(auto b:a){
		std::cout<<b<<" ";
	}std::cout<<std::endl;
	return 0;
}

