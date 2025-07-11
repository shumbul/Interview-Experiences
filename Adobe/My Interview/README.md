1. Count the number of sequences of length N using numbers from 1 to M, such that the absolute difference between any two adjacent numbers is at least K.  
N = length of the sequence  
M = max number allowed in the sequence  
K = minimum absolute difference between adjacent numbers  
We use DP to build valid sequences from length 1 to N  
At each step, we check whether the absolute difference with the previous number is at least K
[solution](https://github.com/Manasvee16/Interview-Experiences/blob/main/Adobe/My%20Interview/ques1.cpp)
