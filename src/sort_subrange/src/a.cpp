#include<iostream>
#include<vector>
#include<boost/algorithm/sort_subrange.hpp>
int main(int argc,char** argv){
	std::vector<int> a={1,4,2,3,5,8,6,7};
	for(auto b:a){
		std::cout<<b<<" ";
	}std::cout<<std::endl;
	boost::algorithm::sort_subrange(
		std::begin(a),
		std::end(a),
		std::begin(a),
		std::begin(a)+4
	);
	for(auto b:a){
		std::cout<<b<<" ";
	}std::cout<<std::endl;
	return 0;
}
