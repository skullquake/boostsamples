/*
 * returns the first iterator it finds in the
 * unsorted subrange of a collection
 */
#include<iostream>
#include<vector>
#include<boost/algorithm/is_partitioned_until.hpp>
bool isOdd(int a){
	return a%2==1;
}
bool isEven(int a){
	return a%2==0;
}
bool isLt5(int a){
	return a<6;
}
int main(int argc,char** argv){
	std::vector<int> a={0,2,4,6,8,2,4,6,9};
	for(auto const& b:a){
		std::cout<<b<<" ";
	}std::cout<<std::endl;
	{
		auto b=boost::algorithm::is_partitioned_until(
			std::begin(a),
			std::end(a),
			isOdd
		);
		std::cout<<(b==a.end()?"Not found":std::to_string((*b)))<<std::endl;
	}
	{
		auto b=boost::algorithm::is_partitioned_until(
			a.begin(),
			a.end(),
			isEven
		);
		std::cout<<(b==a.end()?"Not found":std::to_string((*b)))<<std::endl;
	}
	{
		auto b=boost::algorithm::is_partitioned_until(
			a.begin(),
			a.end(),
			isLt5
		);
		std::cout<<(b==a.end()?"Not found":std::to_string((*b)))<<std::endl;
	}
	return 0;
}
