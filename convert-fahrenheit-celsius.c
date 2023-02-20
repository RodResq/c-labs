#include <stdio.h>

/* print Fahrenheit-celsius table
 * for fahr = 0 , 20, ...., 300 */

int main() {
	float fahr, celsius;
	float lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	printf("%s\t%s\n", "Celsius", "Fahrenheit");
	
	while(fahr <= upper) {
		celsius = 5 * (fahr - 32) / 9;
	       	printf("%3.2f %6.1f\n", fahr, celsius);
       	       	fahr = fahr + step;	       
	}

	return 0;
}


