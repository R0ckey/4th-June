You are given an array of integers. In one operation, you can make all elements to the left or right of a position equal to the element at that position,
with a given cost. Find the minimum total cost to make all elements in the array equal.

Formula :
form forward:
  Cost = a[i]*(i-1) 
form backward:
  Cost = a[i]*(n-i) 

Observation 1 :-> Make all array elements equal to target element :-> Target will be one of the array elements;
(if you make hashmap of all distinct elements as key for it) //RRRRR 

Observation 2 :-> Utmost one prefix operation should be done; and utmost one suffix operation should be done; // RRRRR 
-> If you decide to do prefix operation at index “i”;suffix operation should always be done at index>=i 

Solution :-> For each partition [1….i] + [i+1…n] ; we will see what is the cost if prefix and suffix operations are made at index “i” 


Case :- if (a[i]==a[i+1]) ⇒ cost = c1 + c2; c1 = cost of making prefix[1…i] == a[i] ; -> a[i-c+1]*(i-c); c = count of equal elements ending at index i; similarly do for suffix; 
Case :- if(a[i]!=a[i+1]) => cost = if left is solved first then right => c1 + c2; c1 should be calculated like before…. ; c2 = a[i]*(n-i) 

=> cost if right is solved first => c1 + c2;c2 should be calculated like before; c1 = a[i+1]*(i);
