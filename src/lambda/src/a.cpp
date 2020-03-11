#include<boost/lambda/lambda.hpp>
#include<boost/range/algorithm.hpp>
#include<boost/bind.hpp>
#include<iostream>
int foo(int);
int main();
int main(){
	std::list<int> v(10);
	for_each(
		v.begin(),
		v.end(),
		boost::lambda::_1=1
	);
	std::list<int*> vp(v.size());
	boost::range::transform(
		v.begin(),
		v.end(),
		v.begin(),
		1//&boost::lambda::_1
	);
	for(
		std::list<int>::iterator it=v.begin();
		it!=v.end();
		++it
	){
		std::cout<<(*it)<<std::endl;
	}
	return 0;
}
int foo(int a){
	return a+1;
}
