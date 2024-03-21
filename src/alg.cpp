// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value)
{
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if ((arr[i] + arr[j]) == value) {
        count++;
      }
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value)
{
  int l = 0, r = len - 1;
  int count = 0;
  while (arr[r] > value) {
    r--;
  }
  for (int i = 0; i < r; i++) {
    for (int j = r; j > i; j--) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  if (count != 0){
    return count; 
  }
  return 0;
}
int countPairs3(int *arr, int len, int value)
{
  int count = 0, key = 0;
  for (int i = 0; i < len; i++) {
    key = value - arr[i];
    int l = 0, r = len - 1;
    while ( l <= r) {
      int mid = (l + r) / 2;
      if (arr[mid] == key) {
        count++;
        int temp = mid - 1;
        while (temp >= 0 && arr[temp] == key) {
          count++;
          temp--;
        }
        temp = mid + 1;
        while (temp < len && arr[temp] == key) {
          count++;
          temp++;
        }
        return count;
      } else if (arr[mid] < key) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
  }
  return 0;
}
