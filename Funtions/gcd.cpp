ll GCD(ll a, ll b){
    return b ? GCD(b, a % b) : a;
}