// NAME: Cody Wright
// DATE: 3/6/2019
// LAST MODIFIED: 3/6/2019
// FILE: cnPtrQueue.cpp
// ABSTRACT: This class implements a queue using two of the stl stacks,
//           Which will hold nodes to be processed by the queue

#include "cnPtrQueue.h"
#include <cassert>
using namespace std;

namespace CS3358_SP2019_A5P2
{
   cnPtrQueue::cnPtrQueue() : numItems(0){}

   bool cnPtrQueue::empty() const
   {
      return outStack.empty() && inStack.empty();
   }

   cnPtrQueue::size_type cnPtrQueue::size() const
   {
      return numItems;
   }

   CNode* cnPtrQueue::front()
   {
      assert(!inStack.empty() || !outStack.empty());

      if (outStack.empty())
      {
         while (!inStack.empty())
         {
            outStack.push(inStack.top());
            inStack.pop();
         }
      }
      return outStack.top();
   }

   void cnPtrQueue::push(CNode* cnPtr)
   {
      inStack.push(cnPtr);
      ++numItems;
   }

   void cnPtrQueue::pop()
   {
      assert(!inStack.empty() || !outStack.empty());
      if (outStack.empty())
      {
         while (!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
         }
      }
      outStack.pop();
      --numItems;
   }
}
