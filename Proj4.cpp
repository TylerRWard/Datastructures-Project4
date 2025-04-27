#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
//constrants
const int MAX_N = 91;
const int K = 9;
const long long MAX_SCORE = 9999999999LL;
//dp table
long long dp[MAX_N][K+1];
int choice [MAX_N][K+1];

//try to make number
long long to_number(const string& s, int start, int len){
    if (start + len > s.length()) return -1;
    if (len > 10) return -1; //mercy
    string sub = s.substr(start, len);
    if(sub.length() > 1 && sub[0]=='0'){
        //allow for 0001
        for (char c : sub) if (c!= '0')break;
    }
    try{
        size_t pos;
        long long num = stoll(sub, &pos);
        if(pos!= sub.length()) return -1;
        if (num > MAX_SCORE) return -1;//mercy rule
        return num;
    } catch (...){
        return -1;
    }
}
//recursive function k = innings left
long long max_score (const string& s, int i, int k){
    if(k == 0 && i == s.length()) return 0; //base case
    if(k==0 || i >= s.length()) return -1;
    if (dp[i][k]!= -1) return dp[i][k];//memoize

    long long best = -1; 
    int best_len = -1;

    //try everything
    for (int len = 1; len <= 10 && i + len <= s.length(); len++){
        long long num = to_number(s, i, len);
        if (num == -1)continue; //invalid num

        //recurse
        long long next = max_score(s,i+len, k-1);
        if (next ==-1) continue; //not valid
        long long total = num + next;
        if(total > best){
            best = total;
            best_len = len;
        }
    }
    choice[i][k] = best_len;
    return dp[i][k] = best; 
}
void print_linescore(const string& s){
    vector<string> scores;
    int i = 0; 
    int k = K; 
    while (k > 0&& i < s.length()){
        int len = choice[i][k];
        if (len == -1) break;//solution doesn't exist
        scores.push_back(s.substr(i,len));
        i += len;
        k--;
    }
    cout <<"Linescore: ";
    for (int j = 0; j <scores.size(); j++){
        cout << " "<<scores[j];
    }
    cout <<endl;
}
int main(){
    string s;
    cout<<"Enter a score: "<<endl;
    cin >>s;
    //dp table
    memset(dp, -1, sizeof(dp));
    memset(choice, -1, sizeof(choice));

    //max score
    long long result = max_score(s, 0, K);

    //output
    cout << "Total Score "<<result <<endl;
    print_linescore(s);

    return 0;
}