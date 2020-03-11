#include"boost/date_time/posix_time/posix_time.hpp"
#include"boost/date_time/gregorian/gregorian.hpp"
#include<iostream>
#include<string>
void demoiterator(){
	boost::posix_time::ptime now=boost::posix_time::second_clock::local_time();
	boost::gregorian::date today=now.date();
	boost::gregorian::date tommorrow=today+boost::gregorian::days(1);
	boost::posix_time::ptime tommorrow_start(tommorrow);
	boost::posix_time::time_iterator titr(now,boost::posix_time::hours(1));
	for(;titr<tommorrow_start;++titr){
		std::cout<<boost::posix_time::to_simple_string(*titr)<<std::endl;
	}
	boost::posix_time::time_duration remaining=tommorrow_start-now;
	std::cout<<"Time left till midnight: "
		<<boost::posix_time::to_simple_string(remaining)
		<<std::endl;
}
void demodatetime(){
	boost::gregorian::date d(2002,boost::gregorian::Feb,1);
	boost::posix_time::ptime t1(
		d,
		boost::posix_time::hours(5)+
		boost::posix_time::minutes(4)+
		boost::posix_time::seconds(2)+
		boost::posix_time::millisec(1)
	);
	boost::posix_time::ptime t2=t1-
		boost::posix_time::hours(5)-
		boost::posix_time::minutes(4)-
		boost::posix_time::seconds(2)-
		boost::posix_time::millisec(1);
	boost::posix_time::time_duration td=t2-t1;
	std::cout<<boost::posix_time::to_simple_string(t2)
		<<" - "
		<<boost::posix_time::to_simple_string(t1)
		<<" = "
		<<boost::posix_time::to_simple_string(td)
		<<std::endl;
}
void timeperioddemo(){
	// a date
	boost::gregorian::date d0=boost::gregorian::date(1990,1,1);
	boost::posix_time::hours h0=boost::posix_time::hours(24);
	// a time period of a day from the stard date
	boost::posix_time::time_period p0=
		boost::posix_time::time_period(
			boost::posix_time::ptime(
				d0
			),
			boost::posix_time::ptime(
				d0,
				h0
			)
		);
	// a date
	boost::gregorian::date d1=boost::gregorian::date(1990,1,2);
	boost::posix_time::hours h1=boost::posix_time::hours(24);
	// a time period of a day from the stard date
	boost::posix_time::time_period p1=
		boost::posix_time::time_period(
			boost::posix_time::ptime(
				d1
			),
			boost::posix_time::ptime(
				d1,
				h1
			)
		);
	boost::posix_time::ptime t0(d0,boost::posix_time::hours(1));
	if(p0.contains(t0)){
		std::cout<<"tp0 contains t0"<<std::endl;
	}else{
		std::cout<<"tp0 not contains t0"<<std::endl;
	}
	boost::posix_time::ptime t1(d0,boost::posix_time::hours(25));
	if(p0.contains(t1)){
		std::cout<<"tp0 contains t1"<<std::endl;
	}else{
		std::cout<<"tp0 not contains t1"<<std::endl;
	}
	if(p0.intersects(p0)){
		std::cout<<"p0 intersects p0"<<std::endl;
	}else{
		std::cout<<"p0 not intersects p0"<<std::endl;
	}
	if(p0.intersects(p1)){
		std::cout<<"p0 intersects p1"<<std::endl;
	}else{
		std::cout<<"p0 not intersects p1"<<std::endl;
	}
	//constructing time dureations from times
	boost::posix_time::time_period p2=
		boost::posix_time::time_period(
				t0,
				t1
		);
	//constructing time dureations from dates
	boost::posix_time::time_period p3=
		boost::posix_time::time_period(
			boost::posix_time::ptime(
				d0
			),
			boost::posix_time::ptime(
				d1
			)
		);


}
int main(int argc,char** argv){
	timeperioddemo();
	return 0;
}
