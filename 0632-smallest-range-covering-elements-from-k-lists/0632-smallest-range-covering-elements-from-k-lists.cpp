
class Node 
{
     public:
     int data;
     int  row ; 
     int col; 
     Node(int data , int row , int col )
     {
         this->data=data ;
         this->row=row;
         this->col =col ;

     }
};
 class compare {
     public: 
     bool operator()(Node * a , Node * b )
     {
         return a->data >  b->data  ;
     }
 };
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int maxi =INT_MIN ,mini = INT_MAX ;
        vector<int >ans;
        priority_queue<Node* , vector<Node*>,compare>minHeap;
        for(int i=0;i<nums.size();++i)
        {
            int ele = nums[i][0];
            mini = min(mini,ele );
            maxi = max(maxi , ele );
            minHeap.push(new Node(ele, i , 0 ));

        }
        int start = mini , end =maxi;
        while(!minHeap.empty())
        {
            Node * temp =minHeap.top();
            minHeap.pop();
            mini=temp->data;
            if(end-start > maxi - mini )
            {
                end =maxi;
                start = mini;

            }
            if(temp->col+1<nums[temp->row].size())
            {
                maxi =max(maxi , nums[temp->row][temp->col+1]);
                minHeap.push(new Node(nums[temp->row][temp->col+1],temp->row , temp->col +1 ));

            }
            else 
            {
                break;
            }
        }
        ans.push_back(start);
        ans.push_back(end);
        return ans ; 
    }
};