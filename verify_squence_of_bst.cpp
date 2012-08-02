#include <vector>
#include <iostream>
using namespace std;

bool verify_squence_bst(int squence[],int len)
{
	if(squence == NULL || len <= 0)
		return false;

	int key = squence[len-1];
	int i;
	for(i = 0; i < len-1; i++)
	{
		if(squence[i] > key)
			break;
	}

	int j = i;
	for(; j < len-1; j++)
	{
		if(squence[j] < key)
			return false;
	}


	bool left = true;
	if(i > 0)
		left = verify_squence_bst(squence,i);

	bool right = true;
	if(j < len-1)
		right = verify_squence_bst(squence+i,len-i-1);

	return left&right;
	
}

int main()
{
	int num;
	cin >> num;
	int *s = new int[num];
	for(int i = 0; i < num; i++)
		cin >> s[i];

	cout << verify_squence_bst(s,num) << endl;
	delete [] s;
	return 0;
}