
bool check(int x){
    string s = "";
    while(x>0){
        s+=((x%10)+'0');
        x/=10;
    }
    rep(i , 0 , s.length()/2+1){
        if(s[i]!=s[s.length()-i-1])
            return false;
    }
    return true;

}

int32_t main(){
    __;
    int ans=0;
    rep(i , 100 ,1001){
        rep(j , 100 ,1001){
            if(check(i*j))
                ans = max(ans,i*j);
        }
    }
    tr(ans);
    return 0;
}
