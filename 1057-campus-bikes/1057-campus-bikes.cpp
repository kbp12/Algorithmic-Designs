class Solution {
public:
    // Function to return the Manhattan distance
    int findDistance(vector<int>& worker, vector<int>& bike) {
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }
    
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        // List of WorkerBikeTuples's to store all the possible triplets
        vector<tuple<int, int, int>> allTriplets;
        
        // Generate all the possible pairs
        for (int worker = 0; worker < workers.size(); worker++) {
            for (int bike = 0; bike < bikes.size(); bike++) {
                int distance = findDistance(workers[worker], bikes[bike]);        
                allTriplets.push_back({distance, worker, bike});
            }
        }
        
        // Sort the triplets. By default, each sorting will prioritize the
        // Tuple's first value, then second value, and finally the third value
        sort(allTriplets.begin(), allTriplets.end());  
        
        // Initialize all values to false, to signify no bikes have been taken
        vector<int> bikeStatus(bikes.size(), false);
        // Initialize all index to -1, to signify no worker has a bike
        vector<int> workerStatus(workers.size(), -1);
        // Keep track of how many worker-bike pairs have been made
        int pairCount = 0;
        
        for (auto[dist, worker, bike] : allTriplets) { 
            // If both worker and bike are free, assign them to each other
            if (workerStatus[worker] == -1 && !bikeStatus[bike]) {
                bikeStatus[bike] = true;
                workerStatus[worker] = bike;
                pairCount++;
                
                // If all the workers have the bike assigned, we can stop
                if (pairCount == workers.size()) {
                    return workerStatus;
                }
            }
        }
        
        return workerStatus;
    }
};