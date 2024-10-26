void mergeSort(vector<int> & arr, int low, int mid, int high){
  vector<int> temp;

  int i = low; 
  int j = mid+1;

  while(i <= mid  && j <= high ){
    if(arr[i] <= arr[j]){
      temp.push_back(arr[i]);
      i++;
    }else{
      temp.push_back(arr[j]);
      j++;
    }
  }

  while(i <= mid){
    temp.push_back(arr[i]);
  }

  while(j <= high){
    temp.push_back(arr[j]);
  }

  for(int i = low; i <= high; i++ ){
    arr[i] = temp[i - low];
  }
}

void merge(vector<int> &arr, int low, int high){
  if(low >= high) return;

  int mid = (low + high) / 2;
  // sort the left half
  merge(arr, low, mid);

  // sort the right half
  merge(arr, mid+1, high);

  // merge the array
  mergeSort(arr, low, mid, high);
}
