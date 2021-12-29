//
//  main.cpp
//  Monotonic Queue
//
//  Created by Jose Mari Syjuco on 29/12/21.
//

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

class MonotonicQueue {
public:
    MonotonicQueue();
    deque<int> mq;
    void push(int i, vector<int>& arr);
    void pop(int currIdx, int range, vector<int>& arr);
};

MonotonicQueue::MonotonicQueue() { }
void MonotonicQueue::push(int i, vector<int>& arr) {
    int currVal = arr[i];
    // Can either be INC or DEC
    while (!mq.empty() && currVal > arr[mq.back()]) mq.pop_back();
    mq.push_back(i);
}
void MonotonicQueue::pop(int currIdx, int range, vector<int>& arr) {
    int idxOutOfRange = currIdx - range + 1;
    if (idxOutOfRange == mq.front()) mq.pop_front();
}

int main(int argc, const char * argv[]) {
    MonotonicQueue* monoQ1 = new MonotonicQueue();
    vector<int> nums1 = { 1,3,-1,-3,5,3,6,7 };
    for (int i = 0; i < nums1.size(); ++i) {
        monoQ1->push(i, nums1);
        
        for (auto j : monoQ1->mq) cout << nums1[j] << " ";
        cout << "\n";
        monoQ1->pop(i, 2, nums1); // Range is 2
    }
    
    cout << "------------------------------\n";
    
    MonotonicQueue* monoQ2 = new MonotonicQueue();
    vector<int> nums2 = { 5, 3, 1, 2, 4 };
    for (int i = 0; i < nums2.size(); ++i) {
        monoQ2->push(i, nums2);
        
        for (auto j : monoQ2->mq) cout << nums2[j] << " ";
        cout << "\n";
        monoQ2->pop(i, 2, nums2); // Range is 2
    }
    
    cout << "\nFIN\n";
    return 0;
}
