#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#include "Graph.h"

// This declare is for that whether the longest path is founded or not.
bool found;

/*  The blow is the Quick sorting algorithm function which using on the sorted the divisor of the given number
    and so that will more easier to do the work. The complexity of this algorithm is O(nlogn),
    because we divide the element into two parts and sort them recursively. 
*/
int Partition(int args[], int first, int end) {
    int i,j;
    int temp;
    i = first;
    j = end;

    while (i < j) {
        //scan the right side
        while (i < j && args[i] < args[j]) {
            j--;
        }
        if (i < j) {
            temp = args[i];
            args[i] = args[j];
            args[j] = temp;
            i++;
        }
        //scan the left side
        while (i < j && args[i] <= args[j]) {
            i++;
        }
        if (i < j) {
            temp = args[i];
            args[i] = args[j];
            args[j] = temp;
            j--;
        }
    }
    return i;
}

//Quick sort algorithm, recursive call
void QuickSort(int args[], int first, int end) {
    int core;
    if (first < end) {
        core = Partition(args, first, end);
        QuickSort(args, first, core - 1);
        QuickSort(args, core + 1, end);
    }
}

/*  This funtion is for the stage2, the second condition all digits in x also occur in y.
    we need find all digits in a number. So, I use the mod algorithm to find every digits of a number.
    The complexity of this function is O(n). 
*/

int *arry (int a[],int n,int m) {
    int i;
    for (i = 0; i < m; i++) {
        if (n != 0) {
        a[i] = n%10;
        n=n/10;
        }  
    }
    return a;
}

/*  This is just for counting the how many numbers of digits of a element,
    The complexity of this function is O(n). 
*/

int counting(int n) {
    int amount=0;
    /*  because the number that given is at most 2,147,483,647 which have 10 digits, 
        so we count that at most 10 times. 
    */
    for (int i = 0; i < 10; i++) {
        if (n != 0) {
        n=n/10;
        amount++;
        }
    }
    return amount;
}

/*  This is for checking the condition of if all digits in x, then is it also occur in y?
    The complexity of this function is O(n^2). 
*/
int checking (int n, int d){
    int m = counting(n); 
    int k = counting(d); 
    int a[m]; // a[] contain m digits of n
    int e[k]; // e[] contain n digits of d
    arry(a,n,m);
    arry(e,d,k);
    int check = 1;
    for (int i=0; i<m; i++) {
        for (int j =0; j<k; j++) {
            if (a[i] == e[j]) {
                break;
            }
            else if(j == k-1) {
                check = 0;
                break;
            }
            else {
                continue;
            }
        }
        if (check == 0){
            return 0;
        }
        else{
            continue;
        }
    }
    return 1;
}

/*  This function is for print the  Longest path, we find the maximum length and visited vertice.
    And  we use the divisor record and vertice at now to record the path from the last one to first one.
    Finally, we print the final_arry which contain the all vertices in the Longest path.
    The complexity of this function is O(n).
*/
void print_chain(Vertex v, Vertex visited[], int len, int record[]) {
    //int final_arry[len];
    int final_arry[1000];
    int i = len;
    while (v != visited[v]) {
        final_arry[i] = v;
        i--;
        v = visited[v];
    }
    final_arry[i] = v;
    printf("%d", record[final_arry[0]]);
    for (i = 1; i <= len; i++) {
        printf(" < %d", record[final_arry[i]]);
    }
    printf("\n");
}
/*  This function is checking that is there a longest length path from two vertices at now.
    If there is the longest length path, then we print all paths and return.
    And if not we just choose another way or return back, to find smaller length path.
    So, the complexity of this function is O(2^n).
*/
void _longest_path(Graph g, Vertex prev, Vertex v, Vertex visited[], int now, int longestlengh, int record[]) {
    assert(visited[v] == -1);
    visited[v] = prev;
    // if length at now == longestlengh, then we found the path. 
    // we change the found from flase to true and print the lengh.
    if (now == longestlengh) {
        if (!found) {
            found = true;
            printf("Longest monotonically increasing sequences: \n");
        }
        print_chain(v, visited, now-1, record);
        visited[v] = -1;
        return;
    }
    // if length at now != longestlengh which means we need keep find longestlengh.
    int w;
    for (w = 0; w < g->nV; w++) {
        if (adjacent(g, v, w) && visited[w] == -1) {
            _longest_path(g, v, w, visited, now + 1, longestlengh, record); //T(n) = c*T(n-1)
        }
    }
    visited[v] = -1;
}

/*  This function find the longest path. This means that if the path contains the maximum number of vertices,
    then the path will be the longest path. So, we begin with the longest length theoretically which is the max_dest.
    Because if there it is, it will be the longestpath.
    The complexity of this function is O(n*2^n)，because the _longest_path also need O(2^n) time to find.
    Hence, the total is =O(n*2^n).
*/
void LongestPath(Graph g, int record[], int num) {
    found = false;
    // because the there is no more than 1000 divisors of a number so we just give max value of the visited[1000].
    Vertex visited[1000];
    // i is varibal for loop and v is vertice of the beginning, 
    // and max_dest is Length of the longest path theoretically.
    int i, v, max_dest;
    for (i = 0; i < num; i++) { 
        visited[i] = -1;
    }
    for (max_dest = num; max_dest > 0; max_dest--) {
        if (found) {
            return;
        }
        for (v = 0; v < num; v++) {
            if (visited[v] == -1) {
                _longest_path(g, v, v, visited, 1, max_dest, record);
            }
        }
    }
}

/*  This is main function which contain the task A and task B. For the task A, 
    we need build build and output the partial order graph. 
    Task A:
    The complexity of this task A is O(m^2*n^2),
    because we need use two for loop to insert the graph edges and print the divisor relationship.
    Task B:
    And The complexity of this task B is O(2^n),
    because it is done in the LongestPath() function, So, we just call the function.Hence it is O(n^3).
*/
int main(int argc, char* argv[]) {
    /*  i,j are loop varibles, p is command line argument 
        q is floor(sqrt(p)) which use on finding the divisors of p
        c is arry varible to locate the position, and count is the number of divesors of p. 
    */
    int i,j,p,q,c=0,count=0; 
    /*  due to the p will have no more than 1000 divisors,
        we define the arry that the size is smaller than 1000.
    */
    int number[1000];
    // P is get the given number, q is for the find the divisor fastly.
    p = atoi(argv[1]);
    q = floor(sqrt(p));
    // we use q can more effciency than  one by one to find the all divisors of p.
    // evry time we find the divisor i, we record that in number[] and record the count.
    for (i=1; i<=q; i++) {
        if(p%i == 0) { 
            count++;
            number[c]=i;
            c++;
            if(p/i != i) { 
                count++;
                number[c]=p/i;
                c++;
            }
	    }    
    }
 
    // After we recording, we QuickSort the number[] in ascending order and print the partial order
    QuickSort(number,0,count-1);
    printf("Partial order: \n");
    // For printing partial order,firstly, we create a new graoh and edge. And we check the condition one by one,
    // if 2 divisors are satisfy the condition, 
    // we print that and create the a directed edge in graph, which has modified in graoh.c.
    Graph partialGraph;
    partialGraph = newGraph(count);
    Edge e;
    //
    for (i=0; i<count; i++) {
        printf("%d: ", number[i]);
        for (j=i+1; j<count; j++) {
            if (number[j]%number[i] == 0 && checking(number[i],number[j]) == 1) {
                printf("%d ", number[j]);
                e.v = i;
                e.w = j;
                insertEdge(partialGraph,e);
            }
        }
        printf("\n");
    }
    printf("\n");
    // This is task B which is output all longest monotonically increasing sequences over this partial order.
    LongestPath(partialGraph, number, count);
    // At the finally, we free the graph 
    // and because the s is point the number and number is not mallc the memrory.
    freeGraph(partialGraph);
    return 0;
}