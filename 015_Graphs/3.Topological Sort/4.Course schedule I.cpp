/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:
    Input: numCourses = 2, prerequisites = [[1,0]]
    Output: true
    Explanation: There are a total of 2 courses to take. 
    To take course 1 you should have finished course 0. So it is possible.
Example 2:
    Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
    Output: false
    Explanation: There are a total of 2 courses to take. 
    To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Constraints:
    1 <= numCourses <= 2000
    0 <= prerequisites.length <= 5000
    prerequisites[i].length == 2
    0 <= ai, bi < numCourses
    All the pairs prerequisites[i] are unique.

*/

class Solution {
public:

    vector<int> get_topoSort(int &numCourses, vector<vector<int>> &graph){
        vector<int> topoSort;
        queue<int> q;
        vector<int> indegree(numCourses, 0);

        for(int i=0; i<numCourses; i++){
            for(auto adj : graph[i]) indegree[adj]++;
        }
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0) q.push(i);
            
        }
        
        while(!q.empty()){
            int basicCourse = q.front();
            q.pop();

            topoSort.push_back(basicCourse);

            for(auto advanceCourse : graph[basicCourse]){
                indegree[advanceCourse]--;

                if(indegree[advanceCourse]==0){
                    q.push(advanceCourse);
                }
            }
        }

        return topoSort;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        bool allCoursesFinishable;
        vector<vector<int>> graph(numCourses);
        vector<int> topologicalSort;

        for(int i=0; i<prerequisites.size(); i++){
            int basicCourse = prerequisites[i][1];
            int advanceCourse = prerequisites[i][0];
            
            graph[basicCourse].push_back(advanceCourse);
        }

        topologicalSort = get_topoSort(numCourses, graph);

        allCoursesFinishable = (topologicalSort.size()==numCourses) ? true : false;
        return allCoursesFinishable;
    }
};