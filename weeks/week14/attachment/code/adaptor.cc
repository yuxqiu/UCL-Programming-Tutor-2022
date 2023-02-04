#include <iostream>

// std::stack
#include <stack>
// std::queue and std::priority_queue
#include <queue>

int main() {
  /* std::stack */
  std::stack<int> stack;
  stack.push(1);
  stack.push(2);

  // output: 2 1
  std::cout << stack.top() << " ";
  stack.pop();
  std::cout << stack.top() << std::endl;
  /* std::stack ends */

  /* std::queue starts */
  std::queue<int> queue;
  queue.push(1);
  queue.push(2);

  // output: 1 2
  std::cout << queue.front() << " ";
  queue.pop();
  std::cout << queue.front() << std::endl;
  /* std::queue ends */

  /* std::priority_queue */
  // By default, it builds a max-heap
  std::priority_queue<int> pq;

  for (int i = 0; i < 10; ++i) {
    pq.push(i);
  }

  for (int i = 0; i < 10; ++i) {
    std::cout << pq.top() << " ";
    pq.pop();
  }
  std::cout << std::endl;

  // Check documentations to see how:
  // - to use it with custom type
  // - to build a min-heap
  // And see whether you can build a heap sort based on this

  /* std::priority_queue ends */
}
