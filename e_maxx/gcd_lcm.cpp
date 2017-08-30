/*
 Euclid's algorithm.
 gcd(a, b) = max x such that x|a and x|b.
 lcm(a, b) = min x such that a|x and b|x

 Time Complexity: O(log(a + b)).
 Memory Complexity: O(1).

 @author Andrei Kalendarov
 @source e-maxx.ru/algo/euclid_algorithm
*/



// Alternative: __gcd(a, b)
T gcd(T a, T b)
{
	while(b != 0)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}

T lcm(T a, T b)
{
	return a / gcd(a, b) * b;
}

