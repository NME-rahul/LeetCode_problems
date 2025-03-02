struct ListNode *newNode(int val){
    struct ListNode *temp = malloc(sizeof(struct ListNode));
    temp -> val = val;
    temp -> next = NULL;
    return temp;
}

struct ListNode *addNode(struct ListNode *head, int val){
    head -> next = newNode(val);
    return head -> next;
}


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {

    if(listsSize == 0) return NULL;

    bool flag = true;
    bool findMin = false;
    struct ListNode *head = newNode(0);
    struct ListNode *t = head;

    while(flag){
        flag = false;
        int min = 0;
        struct ListNode *save = NULL;
        short int saveIndex = -1;

        for(int k = 0; k < listsSize; k++){
            if(lists[k] != NULL){
                flag = true; //if at least one non-NULL pointer is there
                if(findMin == false){
                    min = lists[k] -> val; //first non NULL min
                    save = lists[k]; //save its address
                    saveIndex = k; //save its index

                    lists[k] = lists[k] -> next; //increment the address
                    findMin = true; //make false so it again not assign
                }
                else if(min > lists[k] -> val){
                    lists[saveIndex] = save; //if find new min restore then previous min

                    min = lists[k] -> val; //assign new min

                    saveIndex = k; //save current min index
                    save = lists[k]; //save current min address

                    lists[k] = lists[k] -> next; //increment address of new min
                }
            }
        }
        if(flag)
            t = addNode(t, min); //add min in new list
        findMin = false; //again find new min
    }
    
    return head -> next;
}
