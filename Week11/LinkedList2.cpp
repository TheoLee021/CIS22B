#include <iostream>
using namespace std;

class FriendNode {
   public:
      FriendNode(string nameInit = "", FriendNode* nextLoc = nullptr);
      void InsertAfter(FriendNode* nodeLoc);
      FriendNode* GetNext();
      void PrintNodeData();
   private:
      string nameVal;
      FriendNode* nextNodePtr;
};

FriendNode::FriendNode(string nameInit, FriendNode* nextLoc) {
   this->nameVal = nameInit;
   this->nextNodePtr = nextLoc;
}

void FriendNode::InsertAfter(FriendNode* nodeLoc) {
   FriendNode* tmpNext = nullptr;

   tmpNext = this->nextNodePtr;
   this->nextNodePtr = nodeLoc;
   nodeLoc->nextNodePtr = tmpNext;
}

FriendNode* FriendNode::GetNext() {
   return this->nextNodePtr;
}

void FriendNode::PrintNodeData() {
   cout << this->nameVal << endl;
}

int main() {
   FriendNode* headFriend = nullptr;
   FriendNode* currFriend = nullptr;
   FriendNode* lastFriend = nullptr;
   int friendCount;
   string inputValue;
   int i;

   cin >> friendCount;

   headFriend = new FriendNode("name");
   lastFriend = headFriend;

   for (i = 0; i < friendCount; ++i) {
      cin >> inputValue;
      currFriend = new FriendNode(inputValue);
      lastFriend->InsertAfter(currFriend);
      lastFriend = currFriend;

      cout << inputValue << endl;
      cout << "currFriend: " << currFriend << endl;
   }

   currFriend = headFriend;
   while (currFriend != nullptr) {
      currFriend->PrintNodeData();
      currFriend = currFriend->GetNext();
   }

   return 0;
}
