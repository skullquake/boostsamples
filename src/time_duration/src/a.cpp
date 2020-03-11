#include"boost/date_time/posix_time/posix_time.hpp"
#include<iostream>
#include<vector>
#include<string>
int main(int argc,char** argv){
	std::vector<boost::posix_time::time_duration> vd;
	vd.push_back(
		boost::posix_time::milliseconds(10)
	);
	vd.push_back(
		boost::posix_time::microseconds(10)
	);
	vd.push_back(
		boost::posix_time::seconds(10)
	);
	vd.push_back(
		boost::posix_time::minutes(10)
	);
	vd.push_back(
		boost::posix_time::hours(10)
	);
	vd.push_back(
		boost::posix_time::milliseconds(10)+
		boost::posix_time::microseconds(10)+
		boost::posix_time::seconds(10)+
		boost::posix_time::minutes(10)+
		boost::posix_time::hours(10)
	);

;
	boost::posix_time::ptime now=boost::posix_time::second_clock::local_time();
	//boost::posix_time::ptime now=boost::posix_time::microsec_clock::universal_time();
	for(
		std::vector<boost::posix_time::time_duration>::iterator it=vd.begin();
		it!=vd.end();
		++it
	){
		std::cout<<now+(*it)<<std::endl;
	}
	return 0;
}
