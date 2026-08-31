/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int prev=head->val;
        int dist=1;
        int right=-1;
        int left=-1;
        int mindist=INT_MAX;
        int maxdist=INT_MIN;
        ListNode* temp=head->next;
        while(temp->next!=NULL){
            dist++;
            if(temp->val>prev&&temp->val>temp->next->val||temp->val<prev&&temp->val<temp->next->val){
                if(left==-1)left=dist;
                else{
                    if(right!=-1)mindist=min(mindist,dist-right);
                    else mindist=min(mindist,dist-left);
                    right=dist;    
                }
            }
            prev=temp->val;
            temp=temp->next;
        }
        if(left!=-1&&right!=-1){
            maxdist=right-left;
        }
        if(left!=-1&&right!=-1){
            return {mindist,maxdist};
        }
        return {-1,-1};
    }
};