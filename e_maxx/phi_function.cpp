/*
 Euler's phi function.
 Phi(n) = #x <= n such that gcd(n, x) = 1.

 Time Complexity: O(sqrt(n)).
 Memory Complexity: O(1).

 @author Andrei Kalendarov
 @source e-maxx.ru/algo/euler_function
*/



T phi(T n)
{
	T ans = n;
	
	for(T i = 2; i * i <= n; ++i)
	{
		if(n % i == 0)
		{
			while(n % i == 0)
			{
				n /= i;
			}
			ans -= ans / i;
		}
	}

	if(n > 1)
	{
		ans -= ans / n;
	}

	return ans;
}

