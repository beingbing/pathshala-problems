// ~~ industries in kingdom ~~

// cf 1337-c

// depth of industry cities should be maximized w.r.t. capital
// and if two cities has equal depth then that city should be selected which has least number of
// industry cities beyond it.

// for a node, no. of industries in its subtree will be equal to no. of nodes it has in its subtree

// + no. of tourism industries gained by making a city industry city - no. of tourism industries lost in path

// we should try to maximize the above equation.

// we should only consider a city to be industry-city only if we have already choosen all its 
// children to be industry-city

// so, if two nodes have equal depth ,then we will pick the node for which
// depth - cnt_of_children is higher.

// algo -
// for each node calculate 'depth' and 'cnt of children', then sort them in decreasing order
// w.r.t. depth - cnt_of_children
// then pick first k nodes among them.
