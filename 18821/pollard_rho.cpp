#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// TODO: pollard rho implementation
vector<ll> factorize(long long n);

// C DLL export
int isodd(ll n) {
  vector<ll> v = factorize(n);
  return v.size() % 2;
}

extern "C" {
__declspec(dllexport) int isoddc(ll n) {
  return isodd(n);
}
}