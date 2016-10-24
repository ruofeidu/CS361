#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

struct node
{
	int key;
	node *pre;
};
typedef node *Tnode;
char tmp[100005];

class BigInt
{
public:
	Tnode Head;
	BigInt(string s="0")
	{
		int st=0,sign=1;
		//-xxxx
		if (s[st]=='-') sign=-1,++st;
		else if (s[st]=='+') sign=1,++st;
		
		//000xxxx
		while ((st<s.size()) && s[st]=='0')
			++st;
		Head=new(node);
		if (st==s.size())
		{
			Head->pre=NULL;
			Head->key=0;
			return;
		}
		int len=s.size()-1;
		Head->key=sign*(s[len]-'0');
		Tnode cur=Head;
		for (int i=len-1;i>=st;--i)
		{
			cur->pre=new(node);
			cur=cur->pre;
			cur->key=sign*(s[i]-'0');
		}
		cur->pre=NULL;
	}
	
	void Print()
	{
		int len=0;
		for (Tnode cur=Head;cur;cur=cur->pre)
		{
			tmp[len++]=abs(cur->key)+'0';
			if (!cur->pre)
				if (cur->key<0) tmp[len++]='-';
		}
		
		for (int i=len-1;i>=0;--i)
			printf("%c",tmp[i]);
		puts("");
	}
};
BigInt c;

BigInt & operator +(const BigInt &a,const BigInt &b)
{
	Tnode ta=a.Head,tb=b.Head,tc=c.Head;
	
	tc->key=tb->key+ta->key;
	tc->pre=NULL;
	Tnode NotZero=tc;
	while (1)
	{
		if (ta) ta=ta->pre;
		if (tb) tb=tb->pre;
		
		if (!ta && !tb) break;
		
		int aa=0,bb=0;
		if (ta) aa=ta->key;
		if (tb) bb=tb->key;
		
		tc->pre=new(node);
		
		tc->pre->key=aa+bb+tc->key/10;
		tc->key%=10;
		tc=tc->pre;
		tc->pre=NULL;
		
		if (tc->key!=0) NotZero=tc;
	}
	
	while (abs(tc->key)>=10)
	{
		tc->pre=new(node);
		
		tc->pre->key=tc->key/10;
		tc->key%=10;
		tc=tc->pre;
		tc->pre=NULL;
		
		if (tc->key!=0) NotZero=tc;
	}
	
	if (NotZero->key!=0)
	{
		int sign=NotZero->key;
		sign/=abs(sign);
		NotZero->pre=NULL;
		
		NotZero=c.Head;
		for (tc=c.Head;tc;tc=tc->pre)
		{
			if (tc->key * sign<0)
			{
				tc->key+=sign*10;
				tc->pre->key-=sign;
			}
			if (tc->key!=0) NotZero=tc;
		}
		
		NotZero->pre=NULL;
	}
	
	return c;
}

int main()
{
	freopen("plus.in","r",stdin);
	freopen("plus.out","w",stdout);
	
	string s1,s2;
	cin >> s1 >> s2;
	BigInt a(s1),b(s2);
	(a+b).Print();
	
	return 0;
}
