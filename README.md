# CSC36000 Project 4
---
## Project Details

- **Name**: Tyler Ward  
- **Date**: April 16, 2025  
- **Platform**: macOS 
- **Errors**: 

---

## Summary
I began by reading the data from a file and verifying it loaded correctly. For 1D, I sorted clients by the chosen survey and compared adjacent values. For 2D, I first used a brute-force method, then implemented a recursive divide-and-conquer algorithm that checks both sides of a midpoint and a narrow strip for the closest pair. The program supports three modes—1D by survey1, 1D by survey2, and 2D—using command-line arguments. 

---

# Compilation
```bash
g++ -std=c++20 proj4.cpp -o proj4

./proj4 <input_file> 

```