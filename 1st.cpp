public static int longestZigZag(int[] A){
  int n = A.length;
  int[][] Z = new int[n][2];
  for(int i = 0; i < Z.length; i++){
    Z[i] = new int[2];
  }
  Z[0][0] = 1;
  Z[0][1] = 1;
  
  int best = 1;
  
  for(int i = 1; i < n; i++){
    for(int j = i-1; j>= 0; j--){
      if(A[j] < A[i]) Z[i][0] = Math.max(Z[j][1]+1,Z[i][0]);
      if(A[j] > A[i]) Z[i][1] = Math.max(Z[j][0]+1, Z[i][1]);
    }
    best = Math.max(best, Math.max(Z[i][0],Z[i][1]));
  }
  return best;
}