class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode dummy(0);
        ListNode* temp = &dummy;

        while(a != NULL && b != NULL){
            if (a->val <= b->val){
                temp->next = a;
                a = a->next;
            }
            else{
                temp->next = b;
                b = b->next;
            }
            temp = temp->next;
        }
        if(a != NULL){
            temp->next = a;
        }
        else{
            temp->next = b;
        }
        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return NULL;
        }

        ListNode* result = NULL;

        for(int i = 0; i < lists.size(); i++){
            result = mergeTwoLists(result, lists[i]);
        }
        return result;
    }
};
