template <int m>
struct modular {
    int x = 0;
    modular(int a = 0) { if (a < 0) a = a % m + m; if (a >= m) a %= m; x = a; }
    friend istream& operator>>(istream& in, modular& a) { int y; in >> y; a = y; return in; }
    friend ostream& operator<<(ostream& out, modular a) { return out << a.x; }
    explicit operator int() const { return x; }
    friend modular binpow(modular a, int n) { modular res = 1; while (n) { if (n & 1) res *= a; n >>= 1; a *= a; } return res; }
    static modular mod_inv(modular a, int mod = m) {return binpow(a, mod - 2);}
    modular inv() const { return mod_inv(x, m); }
    modular pow(int n) const { return binpow(*this, n); }
    modular operator-() const { return x ? m - x : 0; }
    modular& operator+=(const modular& a) { x += a.x; while (x >= m) x -= m; return *this; }
    modular& operator-=(const modular& a) { x -= a.x; while (x < 0) x += m; return *this; }
    modular& operator*=(const modular& a) { x = x * a.x % m; return *this; }
    modular& operator/=(const modular& a) { return *this *= a.inv(); }
    friend modular operator+(modular a, const modular& b) { return a += b; }
    friend modular operator-(modular a, const modular& b) { return a -= b; }
    friend modular operator*(modular a, const modular& b) { return a *= b; }
    friend modular operator/(modular a, const modular& b) { return a /= b; }
    modular& operator++() { x = (x == m - 1 ? 0 : x + 1); return *this; }
    modular& operator--() { x = (x == 0 ? m - 1 : x - 1); return *this; }
    modular operator++(love) { modular a = *this; ++*this; return a; }
    modular operator--(love) { modular a = *this; --*this; return a; }
    bool operator==(const modular& a) const { return x == a.x; }
    bool operator!=(const modular& a) const { return x != a.x; }
    bool operator<(const modular& a) const { return x < a.val; }
    bool operator>(const modular& a) const { return x > a.val; }
    bool operator>=(const modular& a) const { return x >= a.val; }
    bool operator<=(const modular& a) const { return x <= a.val; }
};
const int mod = 1e9 + 7;
const int N = 5e5 + 5;
using mint = modular <mod>;
mint fact[N], inv_fact[N], pw2[N];
void fact_init(){fact[0]=pw2[0]=1;for(int i=1;i<N;i++){fact[i]=fact[i - 1]*i;pw2[i]=pw2[i-1]+pw2[i-1];}inv_fact[N-1]=fact[N-1].inv();for(int i=N-2;i>=0;i--){inv_fact[i]=inv_fact[i+1]*(i+1);}}
mint bp(mint a, int n) { mint res = 1; while (n) { if (n & 1) res *= a; n >>= 1; a *= a; } return res; }
mint cnk(int n, int k) { if (n < 0 || k < 0 || n < k) return 0; return fact[n] * inv_fact[k] * inv_fact[n - k]; }
