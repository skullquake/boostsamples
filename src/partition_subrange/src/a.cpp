/*
 * partition_subrange partitions elements of a collection according to a predicate. if the elements satisfy the predicate they are put at the beginning of the collection, otherwise after them
 * it takes 4 iterators
 *  two indicate the whole range
 *  two indicate the subrange
 */
#include<iostream>
#include<vector>
#include<boost/algorithm/sort_subrange.hpp>
int main(int argc,char** argv){
	std::vector<int> a={1,0,2,9,3,8,4,7,5,6};
	for(auto const& b:a){
		std::cout<<b<<" ";
	}std::cout<<std::endl;
	boost::algorithm::partition_subrange(
		std::begin(a),
		std::end(a),
		std::begin(a)+0,
		std::begin(a)+5
	);
	for(auto const& b:a){
		std::cout<<b<<" ";
	}std::cout<<std::endl;
	return 0;
}
