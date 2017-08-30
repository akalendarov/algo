/*
 Fibonacci numbers.
 f(n) = f(n - 1) + f(n - 2)

 Time Complexity: O(log(n)) or O(n).
 Memory Complexity: O(1).
 
 Requires:
  - matrix exponentiation function (bp)
  - matrix multiplication function (mul)
 
 @author Andrei Kalendarov
 @source http://e-maxx.ru/algo/fibonacci_numbers
*/



T fib(T n)
{
	vector<vector<int>> a(1, vector<int>(2, 1));
	a[0][0] = 0;

	vector<vector<int>> b(2, vector<int>(2, 1));
	b[0][0] = 0;
	b = bp(b, n);

	return mul(a, b)[0][0];
}

