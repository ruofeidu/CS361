#include <cstdio>
#include <cstring>
#define maxn 1005

char stack[maxn],s[10];

int main()
{
	freopen("parser.in","r",stdin);
	freopen("parser.out","w",stdout);
	
	int top=0;
	for (;scanf("%s",s)!=EOF;)
	{
		if (s[0]=='i')
		{
			//if
			if (scanf("%s",s)==EOF || strcmp(s,"then")!=0)
			{
				puts("WRONG");
				goto Break;
			}
			stack[++top]='i';
		}else if (s[0]=='b')
		{
			//begin
			stack[++top]='b';
		}else if (s[0]=='e' && s[1]=='n')
		{
			//end
			while (top && stack[top]!='b') --top;
			if (!top)
			{
				puts("WRONG");
				goto Break;
			}
			--top;
		}else if (s[0]=='e' && s[1]=='l')
		{
			//else
			if (!top || stack[top]!='i')
			{
				puts("WRONG");
				goto Break;
			}
			--top;
		}else if (strcmp(s,"then")==0)
		{
			//then
			puts("WRONG");
			goto Break;
		}
	}
	
	while (top && stack[top]=='i') --top;
	if (top)
	{
		puts("WRONG");
		goto Break;
	}
	
	puts("CORRECT");
	Break:;
	
	return 0;
}
