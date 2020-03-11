#include"boost/date_time/gregorian/gregorian.hpp"
#include<iostream>
#include<string>
int main(int argc,char** argv){
	using namespace boost::gregorian;
	try{
		std::string s("2001-10-9");
		date d(from_simple_string(s));
		std::cout<<d<<std::endl;
		std::cout<<to_simple_string(d)<<std::endl;
		//read iso standard(CCYYMMDD) and output to ISO extended
		std::string ud("20011009");
		date d1(from_undelimited_string(ud));
		std::cout<<to_iso_extended_string(d1)<<std::endl;
		//in one go
		std::cout<<boost::gregorian::to_iso_extended_string(boost::gregorian::date(boost::gregorian::from_undelimited_string(std::string("20011009"))))<<std::endl;
		//output parts of the date - Tuesday Octoboer 9, 2001,
		std::cout
				<<boost::gregorian::from_simple_string(
					std::string(
						"2001-10-9"
					)
				).year_month_day().day
				<<std::endl
				<<boost::gregorian::from_simple_string(
					std::string(
						"2001-10-9"
					)
				).year_month_day().month
				<<std::endl
				<<boost::gregorian::from_simple_string(
					std::string(
						"2001-10-9"
					)
				).year_month_day().month.as_long_string()
				<<std::endl
				<<boost::gregorian::from_simple_string(
					std::string(
						"2001-10-9"
					)
				).year_month_day().year
				<<std::endl
				<<boost::gregorian::from_simple_string(
					std::string(
						"2001-10-9"
					)
				).day_of_week().as_long_string()
				<<std::endl;
		//computations
		std::cout
			<<(
				boost::gregorian::from_simple_string(
					std::string(
						"2000-01-01"
					)
				)-
				boost::gregorian::from_simple_string(
					std::string(
						"1990-01-01"
					)
				)
			).days()
			<<std::endl
			;
		date d3(1990,1,1);
		//and use with stl
		std::vector<boost::gregorian::date> vdate;
		for(int i=0;i<32;i++){
			vdate.push_back(d3+boost::gregorian::days(i));
		}
		//and iterate
		for(
			std::vector<boost::gregorian::date>::iterator it=vdate.begin();
			it!=vdate.end();
			++it
		){
			std::cout<<(*it)<<std::endl;
		}
		//get todays date
		std::cout<<boost::gregorian::day_clock::local_day()<<std::endl;
		//you can also initialize a date with a date, for example from the local_day
		std::cout<<boost::gregorian::date(boost::gregorian::day_clock::local_day())<<std::endl;
		//utc
		std::cout<<boost::gregorian::day_clock::universal_day()<<std::endl;
	}catch(std::exception& e){
		std::cerr<<"Exception:"<<e.what()<<std::endl;
	}
	return 0;
}
