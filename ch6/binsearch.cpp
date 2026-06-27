
// -1 if absent
long long contains(const vector<int>& v, int x){
  size_t n{v.size()};
  if(n==0) return -1;
  if(n==1) return (x==v[0])?(0):(-1);
  size_t l{}, r{n-1}, mid;
  while(l<=r){
    mid = l+(r-l)/2; 
    if(v[mid]==x) break;
    else if(v[mid]>x){
      if(mid==0) break;
      r = mid-1;
    }
    else l = mid+1;
  }
  if(v[mid]==x) return static_cast<long long>(mid);
  return -1;
}
