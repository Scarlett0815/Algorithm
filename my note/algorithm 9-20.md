# algorithm 9-20

## Lower Bounds of ***Comparison-Based Sorting***

### decision tree solution

Complexity varies from n^2 to nlogn, but we need to find the boundary of this kind of sorting time complexity. 

sort(A) = B

A = a1 ~ an

there are n! possibilities of the array's order.

we try to find out the right output from these orders.

assume ai != aj

if we make one comparison between ai and aj, we can delete 1/2 of the possibilities of the orders.

so the best case is **log2_n! = theta(nlgn)**

> n! >= (n/2)^(n/2)

> through the decision tree, we can narrow down our solution space

## Counting Sorting

* hidden assumption

* time complexity Theta(n)

## Radix Sorting

## Backet Sorting

