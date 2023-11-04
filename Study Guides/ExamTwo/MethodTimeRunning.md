### Suppose that each row of an n×n array A consists of 1’s and 0’s such that, in any row of A, all the 1’s come before any 0’s in that row. Assuming A is already in memory, describe a method running in O(nlogn) time (not O(n2) time!) for counting the number of 1’s in A.

---

Correctness: The binary search is used to find the position of the first occurrence of 0 in each row. The count of 1's in that row is equal to the position of the first 0. By summing up these counts for all rows, you obtain the total count of 1's in the array. Since all rows follow the condition that 1's come before 0's, this algorithm is correct.


Function countOnesInArray(A):
    n = length(A)
    count = 0

    for i from 1 to n:
        left = 0
        right = n - 1

        while left <= right:
            mid = (left + right) / 2

            if A[i][mid] == 1:
                left = mid + 1
            else:
                right = mid - 1

        # The count of 1's in this row is the position of the first 0.
        # Increment the count accordingly.
        count += left

    return count