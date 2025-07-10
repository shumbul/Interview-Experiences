1. https://www.geeksforgeeks.org/dsa/count-of-k-length-substrings-containing-exactly-x-vowels/?utm_source=chatgpt.com

2. You're given:  
A target distance (end of the line).  
A list of charging station positions.  
A drone with a maximum range of 10 units per charge.  
You carry the drone and can walk until you reach the next station it can charge from, then place it, it flies further (up to 10 units), you retrieve it, and so on.  
Goal: Compute the total units walked (by you) from start (0) to finish (target).  
[solution](https://github.com/Manasvee16/Interview-Experiences/blob/main/Okta/My%20Interview/ques2.cpp)

3. Uses a vector<char> input like {'B', 'A', 'C', 'D'}  
Places corresponding shapes (A–E) onto a blank n×n grid initialized with 0  
Fills each shape with unique numbers starting from 1 (based on order in the vector)  
Avoids overlap and skips shapes if they don't fit  
Uses 1-based indexing in the filled grid to mark which shape (by order) is placed  
[solution](https://github.com/Manasvee16/Interview-Experiences/blob/main/Okta/My%20Interview/ques3.cpp)

4. Input:  
code: an integer (e.g., 1212)  
fragments: an array of integer fragments (e.g., {1, 12, 12, 212})  
Goal:  
Count the number of ordered pairs (i, j) such that concatenating the strings of fragments[i] and fragments[j] equals the decimal representation of code.  
[solution](https://github.com/Manasvee16/Interview-Experiences/blob/main/Okta/My%20Interview/ques4.cpp)
