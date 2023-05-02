# Josephus-Problem

This project is the solution for the Josephus Problem using circular linked-list in C++. This implementation requires that you start from the first node (HEAD) and the rotations are clockwise.

## The solution of the problem:
For a given N (number of players) and M (number of rotations), you start from the head (or the first node) and for every node M nodes away from the current node you delete it and you start again from the node right after it.

Let's assume here that N = 10 & M = 3. Now I am at node number 1, node number 4 is M(3) nodes away from node number 1 thus we delete it and we start counting again from the node right after it, which would be 5, and 8 is M(3) nodes away from 5 thus we delete it aswell, and we keep going as displayed in the image below.

<img src="https://imgtr.ee/images/2023/05/02/JfGvJ.png" height=300px width=450px></img>

## The output:

<img src="https://imgtr.ee/images/2023/05/02/JfqZc.png"></img>
