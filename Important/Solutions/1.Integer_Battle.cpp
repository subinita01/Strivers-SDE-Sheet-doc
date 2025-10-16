#include <bits/stdc++.h>
using namespace std;

// Function to find the prime factorization of a number K
// Returns a map where key is the prime factor and value is its exponent.
map<long long, int> primeFactorize(long long k) {
    map<long long, int> factors;

    // Check for factor 2
    while (k % 2 == 0) {
        factors[2]++;
        k /= 2;
    }

    // Check for odd factors from 3 upwards
    for (long long i = 3; i * i <= k; i += 2) {
        while (k % i == 0) {
            factors[i]++;
            k /= i;
        }
    }

    // If k is still greater than 2, it must be a prime itself
    if (k > 2) {
        factors[k]++;
    }

    return factors;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long k;
    cin >> n >> k;

    // Step 1: Prime factorize K
    map<long long, int> k_factors = primeFactorize(k);

    // Step 2: Initialize a map to store the total counts of prime factors from the input array
    map<long long, long long> total_prime_counts;
    for (auto const& kv : k_factors) {
        long long prime = kv.first;
        total_prime_counts[prime] = 0;
    }

    // Step 3: Iterate through the input array and count the relevant prime factors
    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;

        // For each prime factor of K, count how many times it divides the current number 'a'
        for (auto const& it : k_factors) {
            long long prime = it.first;
            while (a % prime == 0) {
                total_prime_counts[prime]++;
                a /= prime;
            }
        }
    }

    // Step 4: Determine the limiting factor and find the minimum score
    long long min_score = LLONG_MAX;

    for (auto const& kv : k_factors) {
        long long prime = kv.first;
        int exponent_in_k = kv.second;
        long long current_score = total_prime_counts[prime] / exponent_in_k;
        min_score = min(min_score, current_score);
    }

    // If min_score was not updated (e.g., K has a prime factor not found at all), set it to 0.
    if (min_score == LLONG_MAX) {
        min_score = 0;
    }

    cout << min_score << '\n';
    return 0;
}