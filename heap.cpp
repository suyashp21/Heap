#include <iostream>
#include <math.h>
#include <cstring>
#include <fstream>
#include <climits>

using namespace std;

int halffloor(int x);
int min(int x, int y);

int main() {
  int len = 0;
  int heap[100];
  for (int i=0; i<100; i++) {
    heap[i] = INT_MIN;
  }
  char input[8];

  cout << "How would you like to input numbers? (CONSOLE or FILE) "; cin >> input;


  if (strcmp(input, "CONSOLE") == 0 || strcmp(input, "console") == 0) {
    cout << "How many numbers will you input? "; cin >> len;
    heap[0] = INT_MAX;
    cout << "Enter your numbers one at a time below:" << endl;
    for (int i=1; i < len+1; i++) {
      cin >> heap[i];
      int k = i;
      while (heap[halffloor(k)] < heap[k]) {
        int temp = heap[k];
        heap[k] = heap[halffloor(k)];
        heap[halffloor(k)] = temp;
        k = halffloor(k);
      }    
    }
  }

  else if (strcmp(input, "FILE") == 0 || strcmp(input, "file") == 0) {
    // cout << "Step 1!" << endl;
    ifstream myfile ("Numbers.txt");
    heap[0] = INT_MAX;
    for (int i=1; i<=11; i++) {
      len++;
      // cout << "Step 2!" << endl;
      myfile >> heap[i];
      // cout << heap[i] << endl;
      int k = i;
      while (heap[halffloor(k)] < heap[k]) {
	int temp = heap[k];
	heap[k] = heap[halffloor(k)];
	heap[halffloor(k)] = temp;
	k = halffloor(k);
      }
    }
    myfile.close();
  }

  cout << "\n";

  /* for (int i=1; i < len+1; i++) {
    cout << heap[i] << endl;
    } */


  // visually display tree

  for (int i=0; i<7; i++) {
    for (int x=0; x<pow(2,(6-i)); x++) {
      cout << " ";
    }
    for (int j=pow(2,i); j<min(len+1, pow(2,i+1)); j++) {
      if (heap[j] != INT_MIN) {cout << heap[j];}
      for (int x=0; x<pow(2,7-i); x++) {
	cout << " ";
      }
    }
    cout << "\n";
  }

  // print in decreasing order and remove

  for (int i=len; i>0; i--) {
    cout << heap[1] << endl;
    heap[1] = heap[i];
    heap[i] = INT_MIN;

    int k = 1;

    while (true) { // does not exit until we specifically call for break
      if (k >= 50) {
	break;
      }
      else if (heap[k] >= heap[2*k] && heap[k] >= heap[2*k+1]) {
	break;
      }
      else if (heap[2*k] >= heap[2*k+1]) {
	int temp = heap[k];
	heap[k] = heap[2*k];
	heap[2*k] = temp;
	k = 2*k;
      }
      else if (heap[2*k+1] >= heap[2*k]) {
	int temp = heap[k];
	heap[k] = heap[2*k+1];
	heap[2*k+1] = temp;
	k = 2*k+1;
      }
    }
  }
  return 0;
}

int halffloor(int x) {
  if (x%2==0) {
    return x/2;
  }
  else {
    return (x-1)/2;
  }
}


int min(int x, int y) {
  if (x>y) {
    return y;
  }
  else {
    return x;
  }
}
