/*
 Binary exponentiation.
 power(a, b) % c

 Time Complexity: O(log(b)).
 Memory Complexity: O(1).

 @author Andrei Kalendarov
 @source http://e-maxx.ru/algo/binary_pow
*/



T bp(T a, T b, T c)
{
	T ans = 1;
	
	while(b)
	{
		if(b & 1)
		{
			ans = ans * a % c;
		}
		a = a * a % c;
		b >>= 1;
	}

	return ans;
}

