// using swap function
#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;

int main() {
	// Your code here
    int N;
    cin>>N;
    int arr[N];
    for (int i = 0; i < N; i++){
        cin>>arr[i];
    }
    for (int i = 0; i < N/2; i++){
        swap(arr[i], arr[N-i-1]);
    }
    for (int i = 0; i < N; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}


// not actually reversing, just printing the reversed form of an array
for (int i = N-1; i < 0; i++){
  cout<<arr[i]<<" ";
}

// using reverse function, STL
for (int i = 0; i < N/2; i++){
  reverse(arr[i], arr[N-i-1];
}

// swapping using a third variable
// using a new array to print the reversed array

// TC is O(N/2)
