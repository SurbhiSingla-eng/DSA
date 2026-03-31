#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;
int cardFlips(int n, int top[], int bottom[]){
//   int n = top.size();
  vector<int> faceA(7,0), faceB(7,0), same(7,0);
  for (int i = 0; i < n; i++){
    ++faceA[top[i]];
    ++faceB[bottom[i]];
    if (top[i] == bottom[i]){
      ++same[top[i]];
    }
  }
    int minRotation = INT_MAX;
    for (int i = 1; i <= 6; i++) {
        if (faceA[i] + faceB[i] - same[i] == n) {
            int rotationsNeeded = min(n - faceA[i], n - faceB[i]);
            minRotation = min(minRotation, rotationsNeeded);
        }
    }
    return (minRotation == INT_MAX) ? -1 : minRotation;
}
int main() {
	// Your code here
    int n;
    cin >> n;
    int top [n];
    for (int i = 0; i < n; i++){
        cin >> top[i];
    }
    int bottom [n];
    for (int i = 0; i < n; i++){
        cin >> bottom[i];
    }
    cout << cardFlips(n, top, bottom);
    return 0;
}
