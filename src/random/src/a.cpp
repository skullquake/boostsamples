#include<boost/random.hpp>
#include<boost/random/random_device.hpp>
void demorange(){
	boost::random::mt19937 rnd(std::time(0));
	boost::random::uniform_int_distribution<int> uid(0,32);
	int r=uid(rnd);
	std::cout<<r<<std::endl;
}
void democast(){
	std::time_t now=std::time(0);
	boost::random::mt19937 gen{static_cast<std::uint32_t>(now)};
	std::cout<<gen()<<std::endl;
}
void demornddev(){
	boost::random::random_device rd;
	std::cout<<rd()<<std::endl;
}
int main(){
	demornddev();
	return 0;
}
