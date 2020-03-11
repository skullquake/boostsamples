#include<iostream>
#include<boost/multiprecision/cpp_int.hpp>
#include<boost/multiprecision/cpp_dec_float.hpp>
#include<boost/math/constants/constants.hpp>
int main(int argc,char** argv){
	//boost/multiprecision/cpp_int.hpp
	//Big Integer data type: we can use either
	// int128_t
	// int256_t
	// int512_t
	// int1024_t
	//data type according to your requirement
	//by using either of these you can achieve
	//precision of 1024 bit 
	{
		boost::multiprecision::int128_t a{1234567890};
		boost::multiprecision::int128_t b{1234567890};
		std::cout<<(a*b)<<std::endl;
	}
	//Arbitrary precision data type
	//we can use any precision with the help of
	//cpp_int data type if we are not sure
	//about how much precision is needed
	//in the future
	//it automatically converts the desired precision
	//at runtime
	//
	{
		boost::multiprecision::cpp_int a{1234567890};
		for(int i=0;i<8;i++){a*=a;}
		std::cout<<(a)<<std::endl;
	}
	//multiprecision float
	//with boost multiprecision float we can achieve
	//precision up to 50 and 100 decimal with
	//cpp_float_50 and cpp_float_100 respectively
	//
	{
		boost::multiprecision::cpp_dec_float_50 r{1};
		auto a=2*boost::math::constants::pi<boost::multiprecision::cpp_dec_float_50>()*r;
		//auto a=2*r;
		std::cout
			<<std::setprecision(std::numeric_limits<boost::multiprecision::cpp_dec_float_50>::digits10)
			<<a
			<<std::endl
		;
	}
	{
		boost::multiprecision::cpp_dec_float_100 r{1};
		auto a=2*boost::math::constants::pi<boost::multiprecision::cpp_dec_float_100>()*r;
		//auto a=2*r;
		std::cout
			<<std::setprecision(std::numeric_limits<boost::multiprecision::cpp_dec_float_100>::digits10)
			<<a
			<<std::endl
		;
	}
	return 0;
}
