Q1. Problem:
You are given the start and end times of n students’ exams. The exams take place in the same room, but the invigilator needs to be present only when there are at least k students in the room at the same time. Write a program to calculate the total amount of time the invigilator must be present.  
Input:  
An integer n — number of students.  
An integer k — minimum number of students required for invigilator presence.  
Two integer arrays of length n:  
start[i] — start time of the ith student’s exam.  
end[i] — end time of the ith student’s exam.  
Output:  
Print the total number of time units the invigilator is present.  
Constraints:  
1 <= n <= 10^5  
1 <= k <= n  
0 <= start[i] < end[i] <= 10^9  
Example 1:  
Input:  
n = 4, k = 2  
start = [1, 2, 3, 5]  
end   = [3, 3, 5, 6]  
Output: 2  
Explanation:  
At time 1: 1 student (no invigilator)  
At time 2: 2 students (invigilator present)  
At time 3: 2 students → 1 student (invigilator leaves after 3)  
At time 5: 2 students (invigilator present)  
Total = (3 - 2) + (6 - 5) = 1 + 1 = 2  
[solution](https://github.com/Manasvee16/Interview-Experiences/blob/main/ION/My%20Interview/ques1.cpp)  

Q2. [Sum of XOR of all Subarrays](https://www.geeksforgeeks.org/dsa/sum-of-xor-of-all-subarrays/)
