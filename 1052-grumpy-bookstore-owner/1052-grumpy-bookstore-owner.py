class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        n = len(grumpy)
        total_customers = 0;
        for i in range(n):
            if(grumpy[i]==0):
                total_customers+= customers[i]
            
        for i in range(minutes):
            if(grumpy[i]==1):
                total_customers += customers[i]
                
        maximum_customers = total_customers
        for i in range(minutes,n,1):
            if(grumpy[i]==1):
                total_customers+= customers[i]
            if(grumpy[i-minutes]==1):
                total_customers-= customers[i-minutes]
            maximum_customers = max(maximum_customers,total_customers)
        return maximum_customers