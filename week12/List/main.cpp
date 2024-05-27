#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
    Queue queue;
    int n;

    cout << "큐에 삽입할 5개의 정수를 입력 >> ";
    for (int i = 0; i < 5; i++) {
    cin >> n;
    queue.enqueue(n);
    // queue.pushBack(n); // 컴파일 오류
    }

    cout << "큐에서 두 개의 원소를 제거하여 출력한다." << endl;
    for (int i = 0; i < 2; i++) {
    cout << queue.dequeue() << " ";
    // cout << queue.popFront() << " "; // 컴파일 에러
    }

    cout << "\nEmpty? " << (queue.empty() ? "true" : "false") << endl;

    cout << "큐의 원소를 순서대로 모두 제거하여 출력한다." << endl;

    while(!queue.empty()) cout << queue.dequeue() << " ";
    
    cout << "\nEmpty? " << (queue.empty() ? "true" : "false") << endl;
}