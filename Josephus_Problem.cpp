int josephus2(int n)
{
    int p = 1;
    while (p <= n)
        p *= 2;
    return (2 * n) - p + 1;
}
int josephus(int n, int k) { // from 0 index
    if (n == 1)
        return 0;
    if (k == 1)
        return n-1;
    if (k > n)
        return (josephus(n-1, k) + k) % n;
    int cnt = n / k;
    int res = josephus(n - cnt, k);
    res -= n % k;
    if (res < 0)
        res += n;
    else
        res += res / (k - 1);
    return res;
}
void Josephus2(int n){
    ll a = 1, b = 0;
    while(n > 0) {
    	for (ll i = 2; i <= n; i+=2) {
    		cout<<a*i + b<<' ';
    	}
    	if (n&1) cout<<a + b<<' ', b += a;
    	else b -= a;
    	a <<= 1;
    	n >>= 1;
    }
}