#include <bits/stdc++.h>

using namespace std;

class Grader {
public:
    int attempt(string password);

    void complete();

    Grader();

    Grader(int n, string answer, long long int x);

private:
    int N;
    string answer;
    long long answerD;
    long long X;
    long long attempts;
    bool error;
    bool found;
};

int attempt(string password);

//Do not edit the code above this point


unordered_map<long long, int> memory;
long long MX = 9;
long long digits;

bool bigger(long long v){
    if(v > MX) return true;
    if(memory[v]) return memory[v] == -1;
    
    string value = to_string(v);
    while(value.size() < digits) value = "0" + value;
    int output = attempt(value);
    memory[v] = output;
    
    if(output == 0) throw 0;
    if(output == 2) throw 1;
    if(output == 1) return false;
    return true;
}

//Complete the function solve
void solve(int N, long long X) {
    try {
        digits = N;
        for(int i=1;i<N;i++) MX = MX * 10 + 9;
        
        long long lo = 0, hi = MX;
        while(lo <= hi){
            long long mid = (lo+hi)/2;
            bool big = bigger(mid);
            if(big) hi = mid;
            else lo = mid+1;
        }
    } catch(int e){
        // done
    }
}

//Do not edit the code below this point

int Grader::attempt(string password) {
    if (++attempts > X) {
        error = true;
        return -2;
    }
    if (found || error) {
        error = true;
        return -2;
    }
    if (password.length() != N) {
        error = true;
        return -2;
    }
    if (answer == password) {
        found = true;
        return 0;
    }
    try {
        long long passwordD = stoll(password);
        if (passwordD < answerD) {
            return 1;
        }
        return -1;
    } catch (exception &e) {
    }

    error = true;
    return -2;
}

Grader::Grader() {}

void Grader::complete() {
    printf("%lld %d %d\n", attempts, found, error);
}

Grader::Grader(int n, string answer, long long int x) : N(n), answer(answer), X(x) {
    attempts = 0;
    error = false;
    found = false;
    answerD = stoll(answer);
}

Grader grader;

int main() {
    int N;
    long long X;
    scanf("%d %lld", &N, &X);
    char input[N + 1];
    scanf("%s", input);
    string answer = string(input);
    grader = Grader(N, answer, X);

    solve(N, X);

    grader.complete();
}

int attempt(string password) {
    return grader.attempt(password);
}
