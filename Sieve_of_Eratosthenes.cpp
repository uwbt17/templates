vector <int> primes;
int lp[N];
void Sieve_of_Eratosthenes () {
	lp[1] = 1;
	for (int i = 2; i < N; i ++) {
		if (!lp[i]) {
			lp[i] = i;
			primes.pb(i);
			for (int j = i * i; j < N; j += i) { lp[j] = i; }
		}
	}
}
