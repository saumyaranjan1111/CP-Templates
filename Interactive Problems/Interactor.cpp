
#include<bits/stdc++.h>
// #define endl "\n"
#define ll long long

using namespace std;
using namespace chrono;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 

// struct Interactor{
//     int hiddenNumber;
//     int queriesTillNow;
//     int limitQueries;
//     string numType;
//     bool printInteraction;
//     int divCount;

//     Interactor(){
//         hiddenNumber = getRandomNumber(1, 100);
//         queriesTillNow = 0;
//         limitQueries = 20;
//         printInteraction = false;
//         divCount = 0;

//         for(int i = 2; i<=100; i++){
//             if(hiddenNumber % i == 0) divCount++;
//         }

//         if(divCount>=2) numType = "composite";
//         else numType = "prime";
//     }

//     void checkTotalQueries(){
//         if(queriesTillNow >= limitQueries){
//             cout << "Made more than limit queries for " << hiddenNumber << endl;
//         }
//         assert(queriesTillNow < limitQueries);        
//     }

//     string make_query(int x){
//         checkTotalQueries();
//         queriesTillNow++;
        
//         if(printInteraction)
//             cout << "? " << x << endl;
//         if(hiddenNumber % x == 0){
//             // cout<<"yes"<<endl;
//             return "yes";
//         }
//         else{
//             // cout<<"no"<<endl;
//             return "no";
//         }
//     }

//     bool isValidOutput(string prediction){
//         if(prediction == numType){
//             // cout<<"Passed for number : "<<hiddenNumber<<","<<prediction<<", queries: "<<queriesTillNow<<endl;
//             return true;
//         }
//         else {
//             // cout<<"Failed for number : "<<hiddenNumber<<","<<" prediction : "<<prediction<<","<<" actual : "<<numType<<", queries: "<<queriesTillNow<<endl;
//             return false;
//         }
//     }
// };


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // int tests = 10000;
    // int failed = 0, passed = 0;
    // map<int, int> q;
    // for(int x = 0; x<tests; x++){
            // 
        // Interactor it = Interactor();
        // 
        vector<int> primesandsquaresunder100 = {4, 9, 25, 49, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
        int count = 0;
        for(int i = 0; i<primesandsquaresunder100.size(); i++){
            cout<<primesandsquaresunder100[i]<<endl;

            string response;
            // response = it.make_query(primesandsquaresunder100[i]);
            cin>>response;

            if(response == "yes") {
                count++;
            }
            if(count>=2){
                break;
            }
        }

        if(count>=2) {
            cout<<"composite"<<endl;
            // it.isValidOutput("composite") ? passed++ : failed++;
        }
        else {
            cout<<"prime"<<endl;
            // it.isValidOutput("prime") ? passed++ : failed++;
        }
        // q[it.queriesTillNow]++;
    // }
    // cout<<"Passed "<<passed<<" testcases"<<endl;
    // cout<<"Failed "<<failed<<" testcases"<<endl;

    // for(auto it = q.begin(); it!= q.end(); it++){
    //     cout<<it->first<<" "<<it->second<<endl;
    // }
}