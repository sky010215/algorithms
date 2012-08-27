#include <iostream>
#include <algorithm>
using namespace std;
int *a;
int len;

void ComputePut(int n,int m)
{
	if(n < 1 || m < 1 || (n == 1 && m != 1)) return;

	for(int i = n; i >= 1; i--)
	{
		if(m == i)
		{
			a[i-1] = 1;
			for(int j = 0; j < len; j++)
			{
				if(a[j])
					cout << j+1 << " ";
			}
			cout << endl;
			a[i-1] = 0;
		}
		else if(m > i)
		{
			a[i-1] = 1;
			ComputePut(i-1,m-i);
			a[i-1] = 0;
		}
	}
}
int main()
{
	int n,m;
	cin >> n >> m;
	
	const int N = min(n,m);
	a = new int[N];
	memset(a,0,sizeof(int)*N);
	len = N;

	ComputePut(N,m);
	return 0;

}