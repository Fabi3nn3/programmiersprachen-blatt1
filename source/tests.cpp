#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <cmath>
#define M_PI   3.14159265358979323846 


int gcd(int a, int b){

	if(b == 0){
		return a; 
	}
	else{
 		return gcd(b, a % b);
 	}

	return 1;
}

int checksum(int n){

	int result = 0;
	while(n != 0){
		result = result + n % 10; // oder result += n % 10 
		n = n / 10;
	}

	return result; 
}

int sumMultiples(){
	int result = 0;
	for(int i=1; i <= 1000; ++i){
		if(i % 3 == 0 || i % 5 == 0){
			result = result + i;
		}
	}
	return result;
}

float fract(float x){
	int a(x);
	return x - float(a);
}

float zylinderv(float h, float r){

	float v = M_PI * r*r * h;
	return v;
}

float zylindero(float h, float r){

	float o = 2*M_PI*r*r+2*M_PI*r*h;
	return o;

}

double mileToKilometer(double m){
	double k = 1.60934;
	m = m * k;

	return m;

}

TEST_CASE("mileToKilometer","[mileToKilometer]"){
	REQUIRE(mileToKilometer(1) == Approx(1.60934));
	REQUIRE(mileToKilometer(2.45) == Approx(3.942893));
	REQUIRE(mileToKilometer(4.58) == Approx(7.370796));
}

TEST_CASE("describe_zylindero","[zylindero]"){
	REQUIRE(zylindero(5.89,2.37) == Approx(123.000892));
	REQUIRE(zylindero(4.23,1.63) == Approx(60.0157294));
	REQUIRE(zylindero(6.41,3.12) == Approx(186.821719));
}

TEST_CASE("describe_zylinderv","[zylinderv]"){
	REQUIRE(zylinderv(5.89,2.37) == Approx(103.935009));
	REQUIRE(zylinderv(4.23,1.63) == Approx(35.3073765));
	REQUIRE(zylinderv(6.41,3.12) == Approx(196.02754));
}

TEST_CASE("describe_fract","[fract]"){
	REQUIRE(fract(3.777) == Approx(0.777));// Approx wenn Rückgabetyp float, zb bei Pi
	REQUIRE(fract(6.4589) == Approx(0.4589));
	REQUIRE(fract(5.386) == Approx(0.386));
	REQUIRE(fract(4.2386) == Approx(0.2386));
}

TEST_CASE("describe_sumMultiples", "[sumMultiples]"){
	REQUIRE(sumMultiples() == 234168);
}

TEST_CASE("describe_checksum", "[checksum]"){
	REQUIRE(checksum(234) == 9);
	REQUIRE(checksum(116357) == 23);
	REQUIRE(checksum(452) == 11);
	REQUIRE(checksum(632) == 11);
}

TEST_CASE("describe_gcd", "[gcd]"){
	REQUIRE(gcd(2,4) == 2);
	REQUIRE(gcd(6,9) == 3);
	REQUIRE(gcd(3,7) == 1);
}

int main(int argc, char* argv[]){
	return Catch::Session().run(argc, argv);
}

