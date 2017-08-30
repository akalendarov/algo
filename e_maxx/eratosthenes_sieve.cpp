/*
 Sieve of Eratosthenes.
 Finds all prime numbers from 2 to n.
 Also finds least prime factor for each number from 2 to n.
 
 Time Complexity: O(nloglog(n)) or O(n).
 Memory Complexity: O(n).

 @author Andrei Kalendarov
 @source e-maxx.ru/algo/eratosthenes_sieve
*/


/*
 @returns v[x] = 1 if x is prime, 0 otherwise
*/
vector<bool> sieve_nloglogn(int n)
{
	vector<bool> ans(n + 1, true);
	ans[0] = ans[1] = false;
	
	for(int i = 2; i * i <= n; ++i)
	{
		if(ans[i])
		{
			for(int j = i * i; j <= n; j += i)
			{
				ans[j] = false;
			}
		}
	}
	return ans;
}

/*
 @returns {list of prime numbers, ld[x] = least prime factor for x}.
*/
pair<vector<int>, vector<int>> sieve_n(int n)
{
	vector<int> pr, ld(n + 1);
	ld[0] = ld[1] = 1;

	for(int i = 2; i <= n; ++i)
	{
		if(ld[i] == 0)
		{
			ld[i] = i;
			pr.push_back(i);
		}
		for(int j : pr)
		{
			if(i * j > n || j > ld[i])
			{
				break;
			}

			ld[i * j] = j;
		}
	}

	return {pr, lp};
}
