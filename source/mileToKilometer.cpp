#include <iostream>
#include <string>
#include <cmath>


double mileToKilometer(double m){
		double k = 1.60934;
		m = m * k;

	    return m;
	}


int main(){

	int n;

	std::cout << "Bitte geben Sie eine Meilenanzahl ein:"
			  << std::endl;

	std::cin >> n;
	std::cout << "Die Kilometeranzahl betraegt: " << mileToKilometer(n) << "km." << std::endl;

	return 0;

}
