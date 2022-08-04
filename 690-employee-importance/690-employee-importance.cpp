/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int dfs(vector<Employee*>& employees, int id){
        Employee* temp;
        for(int i=0;i<employees.size();i++){
            if(employees[i]->id == id){
                temp = employees[i];
            }
        }
        int sum = temp->importance;
        for(auto next:temp->subordinates){
            sum+=dfs(employees,next);
        }
        return sum;
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        return dfs(employees,id);
    }
};