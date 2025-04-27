# CSC36000 Project 4
---
## Project Details

- **Name**: Tyler Ward  
- **Date**: April 27, 2025  
- **Platform**: macOS 
- **Errors**: 

IMPORTANT NOTE: must finish in 2 seconds or less

---

## Summary
The problem involved partitioning a digit string into 9 innings to maximize the score. Each segment can be a number up to 10 digits. I used dynamic programming with memoization so that it runs in less than 2 seconds. 

I defined max_score(i, k) where i is the string index and k is innings remaining. It tries all valid segments lenths 1-10, converts each to a number and recursively solves for the remaining string with (k-1) innings. 

I used a 2D DP table to cache results and a choice[i][k] array to track segment lengths for linescore reconstruciton. 

---

# Compilation
```bash
g++ -std=c++20 Proj4.cpp -o proj4

./proj4 

```