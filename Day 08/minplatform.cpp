//https://www.codingninjas.com/codestudio/problems/minimum-number-of-platforms_8230720?challengeSlug=striver-sde-challenge


int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at, at+n);
    sort(dt, dt+n);

    int pltcount = 1;
    int i = 1;
    int j = 0;

    while(i < n){
        if(at[i] > dt[j]) j++;
        else pltcount++;

        i++;
    }

    return pltcount;
}
