tuple<int, int, int> kadane(const vector<int>& v){
  int bestSubSum{std::numeric_limits<int>::min()}, bestLeft{}, bestRight{};
  int currentSum{}, currentLeft{};
  const int n{static_cast<int>(v.size())};
  if(n==0){
    return {0, -1, -1};
  }
  for(int i{}; i<n; ++i){
    if(currentSum<=0){
      currentSum = v[i];
      currentLeft = i;
    }else{
      currentSum += v[i];
    }
    if(currentSum>bestSubSum){
      bestSubSum = currentSum;
      bestLeft = currentLeft;
      bestRight = i;
    }
  }
  return {bestSubSum, bestLeft, bestRight};
}

