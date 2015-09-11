# Energy Constrained Routing

This is an experimental project to explore if Djikstra's can be applied with energy constraints in an efficient manner.
The objective is:

Given a starting amount of energy, find the shortest path (by traversal time) to an endpoint on the graph with charging depots.

## Assumptions
We are given the amount of charge and time required to traverse a link (E, T).
We have a limited capacity percentage (100%) we can charge to, and we can never drop below 5%.
We know how long it takes to charge from one percentage to another. i.e. we have a function c(a,b) which gives the time
to charge from a% -> b%. We can also assume the following properties on ct:
* Nonnegative for a<=b i.e. c(a,b) >= 0 for all 0 <= a <= b <= 100
* Monotonically increasing on fixed a,b: c(a,x) <= c(a,y) and c(x,b) >= c(y,b) for x <= y

## Algorithm (in progress)
We can calculate the shortest route by running Djikstra's in reverse from the end point, while keeping track of the charge state.
If we reach a point where charge exceeds 100%, we assume do not update the cost/path from that node. Anytime we reach a charger,
we calculate the time it would have taken to charge from 5% and add that to the proposed cost of the node.