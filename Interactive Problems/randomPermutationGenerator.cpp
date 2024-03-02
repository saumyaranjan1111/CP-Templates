vector<int> generateRandomPermutation(vector<int> arr){
    int n = arr.size();
    for(ll i = n-1; i>=1; i--){
        ll ind = getRandomNumber(0, i-1);
        swap(arr[ind], arr[i]);
    }
    return arr;
}
