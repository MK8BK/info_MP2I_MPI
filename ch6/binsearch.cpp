
std::optional<size_t> get_index_binsearch(const vector<int>& v, int x){
  size_t n{v.size()};
  if(n==0) return {};
  size_t r{n-1}, l{0};
  while(l<=r){
    size_t mid{l+(r-l)/2};
    if(v[mid]<x){
      l = mid+1;
    }else if(v[mid]>x){
      if(mid==0) return {};
      r = mid-1;
    }else{
      return mid;
    }
  }
  return {};
}
