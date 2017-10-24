#include <stdio.h>

enum COUNT {
	ZERO, 
	ONE, 
	TWO	
};

int main(void) {
	enum COUNT nCount;
	nCount = ONE;
	printf("%d", nCount);
	return 0;
}