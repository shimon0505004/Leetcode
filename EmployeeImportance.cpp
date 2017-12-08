/*
	https://leetcode.com/problems/employee-importance/
	shimon0505004
*/


/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(std::unordered_map<int,Employee*>& employeetable, int id);

    int getImportance(vector<Employee*> employees, int id) {
        std::unordered_map<int,Employee*> employeeTable;
        for(Employee* employee : employees)
            employeeTable.insert({employee->id,employee});
        
        return getImportance(employeeTable,id);
    }
    
};

int Solution::getImportance(std::unordered_map<int,Employee*>& employeetable, int id)
{
    Employee* currentEmployee = employeetable[id];
    
    int importanceSum = currentEmployee->importance;
    for(int subordinateID : currentEmployee->subordinates)
        importanceSum += getImportance(employeetable, subordinateID);
    
    return importanceSum;    
}