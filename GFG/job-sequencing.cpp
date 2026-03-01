/*

struct Job
{
    int id;	 // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

class Solution {
  public:
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) {
        // your code here
        // sort the jobs in the descending order of profits
        sort(arr, arr+n, [](Job& a, Job& b){
            return a.profit > b.profit;
        });
        
        int maxDead = 0, totProfit = 0, cnt = 0;
        
        for(int i = 0; i<n; i++){
            maxDead = max(maxDead, arr[i].dead);
        }
        
        // to keep track of which job is done on which day 
        vector<int> hash(maxDead+1, -1);
        
        for(int i = 0; i<n; i++){
            for(int j = arr[i].dead; j>0; j--){
                // check if final deadline day is empty, if yes then assign that job for that day and move on to the next highest profit job
                if(hash[j] == -1){
                    hash[j] = arr[i].id;
                    cnt++;
                    totProfit += arr[i].profit;
                    break;
                }
                // if not empty then check for prior days
            }
        }
        
        return {cnt, totProfit};
    }
};

// 1. delay the job to the end days (hence start assigning jobs at the deadline day)
// 2. pick the job with current maximum profit (hence sort in descending order of profit)