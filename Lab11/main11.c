#include <stdio.h>
#include "math_utils.h"

int main(int argc, char **argv)
{
	int numbers = sum(2,5,5);
	int max_num = max(5,1,2,5,4,3);
	int min_num = min(5,5,1,4,3,2);
	double avg_num = avg(10,1,2,3,4,5,6,7,8,9,10);
	printf("%d\n",numbers);
	printf("%d\n",max_num);
	printf("%d\n",min_num);
	printf("%f\n",avg_num);
	return 0;
}
