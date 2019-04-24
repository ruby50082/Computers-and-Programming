# Overlapping Segment
Another method to compute the total overlapping length for a line set is to sort two endpoints of all lines in increasing order. 
In the sorted list, each point is attached with a attribute to indicate the left or right endpoint. 
Then we start to scan the sorted point list and perform the following operations:
1. If current point is a left endpoint, insert this point into the active line list, where each line is represented by its left endpoint in the list and a line is in the list if it contains current scan point.
2. if current point is a right endpoint, scan the active line list and do the following operations:
  (1) if current left endpoint is its left endpoint, remove this left endpoint from the active line list.
  (2) if current left endpoint is not its left endpoint, compute the overlapping length of these two lines.
