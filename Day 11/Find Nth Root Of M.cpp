//https://www.codingninjas.com/codestudio/problems/find-nth-root-of-m_8230799?challengeSlug=striver-sde-challenge&leftPanelTab=0

double findpow(int a, int b){
  double pow = 1;
  for(int i = 0 ; i < b; i++){
    pow = pow * a;
  }
  return pow;
}

int NthRoot(int n, int m) {
  // Write your code here.
  int start = 1;
  int end = m;

  while(start <= end){
    int mid = (end + start)/2 ;
    double res = findpow(mid, n);
    if(res == m){
      return mid;
    }
    else if(res > m){
      end = mid - 1;
    }
    else{
      start = mid + 1;
    }
  }

 return -1;
}
