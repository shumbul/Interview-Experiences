Q1. You are given a tree with n nodes (numbered 1 to n), where each node represents a light bulb.  
The tree is represented by a parent array P (1-indexed) where P[i] is the parent of node i.  
If a node is the root, P[i] = -1.  
If P[i] = 1, treat it as having parent 0th index.  
You are also given a brightness array B where B[i] is the brightness of the bulb at node i.  
You can choose to turn ON any set of bulbs with the following rule:  
If a parent is ON, you must turn ON an even number of its children (can be 0, 2, 4, ...).  
If a parent is OFF, you may turn ON any number of its children.  
Find the maximum total brightness sum achievable.  
[solution](https://github.com/Manasvee16/Interview-Experiences/blob/main/Bottomline/My%20Interview/ques1.cpp)

Q2. You are given n bottles, each with capacity c units of water.  
Some bottles already contain water, given in an array A of size n.  
In one operation, you can:  
Select a source bottle that has at least 1 unit of water.  
Select a target bottle that has less than c units of water.  
Transfer exactly 1 unit of water from the source to the target.  
You cannot transfer from an empty bottle, and you cannot transfer to a full bottle.  
Return the maximum number of transfers possible until no more transfers can be made.  
Example:  
n = 2, c = 3, A = [2, 1]  
Transfers:  
[2, 1] → [3, 0] → [2, 1] → [1, 2] → [0, 3]  
Total transfers = 3  
[solution](https://github.com/Manasvee16/Interview-Experiences/blob/main/Bottomline/My%20Interview/ques2.cpp)  
