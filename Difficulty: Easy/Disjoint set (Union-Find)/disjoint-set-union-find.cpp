/*Complete the functions below*/
int find(int par[], int x) {
    // add code here
    if(par[x] == x) return x;
    return find(par,par[x]);
}

void unionSet(int par[], int x, int z) {
    // add code here.
     int lrep = find(par,x);
     int jrep = find(par,z);

     par[lrep]=jrep;
     
     return ;
}