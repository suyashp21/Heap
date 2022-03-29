#include <iostream>
#include <math.h>

using namespace std;

int floor(int x);

int main() {
  int len;
  cout << "How many numbers will you input? "; cin >> len;
  int heap[len+1];
  heap[0] = 2147483647;
  cout << "Enter your numbers one at a time below:" << endl;
  for (int i=1; i < len+1; i++) {
    cin >> heap[i];
    int k = i;
    while (heap[floor(k/2)] < heap[k]) {
      int temp = heap[k];
      heap[k] = heap[floor(k/2)];
      heap[floor(k/2)] = temp;
      k = floor(k/2);
    }    
  }

  cout << "\n";

  for (int i=1; i < len+1; i++) {
    cout << heap[i] << endl;
  }
  return 0;
}

int floor(int x) {
  if (x%2==0) {
    return int(x/2)+1;
  }
  else {
    return int((x-1)/2)+1;
  }
}
