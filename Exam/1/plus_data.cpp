#include <iostream>
using namespace std;

inline void get()
{
	int l=rand()%18+1;
	if (rand()%2==1) printf("-");
	
	for (int i=0;i<l;++i)
		printf("%d",rand()%10);
	puts("");
}

int main()
{
	freopen("plus.in","w",stdout);
	
	srand(time(0)^15678641);
	
	get();get();
	
	return 0;
}
