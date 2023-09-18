#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/**
 * Definition for singly-linked list.
 * 
 * 
 * 
 * 
 */

 struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
	struct ListNode *slow = head;
	struct ListNode *fast = head;
	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return true;
	}
	return false;
}

int main(int argc, char *argv[]) {
	struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *node1 = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *node2 = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *node3 = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *node4 = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *node5 = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->val = 1;
	head->next = node1;
	node1->val = 2;
	node1->next = node2;
	node2->val = 3;
	node2->next = node3;
	node3->val = 4;
	node3->next = node4;
	node4->val = 5;
	node4->next = node5;
	node5->val = 6;
	node5->next = node3;
	printf("%d\n", hasCycle(head));
	return 0;
}