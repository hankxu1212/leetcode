#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <ctype.h>
#include <math.h>
#include <set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//ENSURES: inplace reverse
void revList(ListNode* &head){
    ListNode* curr = head;
    ListNode* prev = NULL, *next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

vector<int> toVec(ListNode* head){
    vector<int> v;
    for(ListNode* i = head; i != NULL; i = i->next)
        v.push_back(i->val);
    return v;
}

ListNode* toList(vector<int> v){
    ListNode* res = new ListNode();
    ListNode* dummy = res;
    for(int i = 0; i < v.size(); i ++){
        res->next = new ListNode(v[i]);
        res = res->next;
    }
    return dummy->next;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    vector<int> v = toVec(head);
    v.erase(v.begin() + v.size() - n);
    return toList(v);
}

ListNode* mergeTwoLists(ListNode* &list1, ListNode* &list2) {
    ListNode *i = list1;
    ListNode *j = list2;
    ListNode *res = new ListNode();
    ListNode *dummy = res;
    while(i != NULL && j != NULL){
        if(i->val < j->val){
            res->next = i;
            i = i->next;
        }
        else{
            res->next = j;
            j = j->next;
        }
        res = res->next;
    }
    while(i != NULL){
        res->next = i;
        res = res->next;
        i = i->next;
    }
    while(j != NULL){
        res->next = j;
        res = res->next;
        j = j->next;
    }
    return dummy->next;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* res;
    for(int i=0; i < lists.size(); i++){
        res = mergeTwoLists(res, lists[i]);
    }
    return res;
}

ListNode* swapPairs(ListNode* head) {
    if(head == NULL || head->next == NULL) return head;
    ListNode *tmp = head->next;
    head->next = tmp->next;
    tmp->next = head;
    head->next = swapPairs(head->next);
    return head;
}

 ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == NULL) return head;

    auto nxtHead = head;
    for (int i = 0; i < k; ++i) {
        if (nxtHead == NULL) return head;
        nxtHead = nxtHead->next;
    }

    auto curr = head;
    ListNode* prev = NULL;

    for (int i = 0; i < k; ++i) {
        auto temp = curr;
        curr = curr->next;
        temp->next = prev;
        prev = temp;
    }

    head->next = reverseKGroup(nxtHead, k);

    return prev;
}

int main(){
    ListNode *l = new ListNode();
    l->next = new ListNode(1);
    l->next->next = new ListNode(2);
    l->next->next->next = new ListNode(3);
    l->next->next->next->next = new ListNode(4);
}