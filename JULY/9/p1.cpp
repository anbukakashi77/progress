
	int n; sd(n); int a[n]; rep(i,0,n) sd(a[i]);
	int curr = a[0];
	for(int i=1 ; i<n ; i++){
		curr^=a[i]; 
	}
	tr(curr);