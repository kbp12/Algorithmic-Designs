class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),
            [](vector<int>&person1,vector<int>&person2){
                if(person1[0]!=person2[0]) return person1[0]>person2[0];
                return person1[1]<person2[1];
        });
        for(int i=0;i<people.size();i++){
            int j = i;
            while(people[j][1]!=j){
                swap(people[j],people[j-1]);
                j--;
            }
        }
        return people;
    }
};