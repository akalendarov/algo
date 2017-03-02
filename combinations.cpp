/*
Combinations

Input:
	const int MOD; // prime module
	const int N; // max(n)

Usage:
	precalc();
	comb(n, k);
*/

const int MOD = ...;
const int N = ...; 

int fact[N];

int bp(int a, int n)
{
	ll ans = 1;
	while(n)
	{
		if(n & 1) 
			ans = ans * a % MOD;
		a = a * a % MOD;
		n >>= 1;
	}
	return (int)ans;
}

inline int inv(int x)
{
	return bp(x, MOD - 2);
}

inline void precalc()
{
	fact[0] = 1;
	for(int i = 1; i < N; ++i)
		fact[i] = (ll)fact[i - 1] * i % MOD;
}

inline int comb(int n, int k)
{
	return (int)((ll)fact[n] * inv(fact[n - k]) % MOD * inv(fact[k]) % MOD);	
}
