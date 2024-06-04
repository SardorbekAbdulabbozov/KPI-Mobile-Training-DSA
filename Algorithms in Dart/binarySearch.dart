void main() {
  final List<int> arr = [0, 7, 10, 23, 24, 39, 45, 88];

  final int searchValue = 88;

  final index = binarySearch(searchValue, arr);

  print(
      index != -1 ? "$searchValue found at index $index." : "Value Not Found");
}

int binarySearch(int searchValue, List<int> arr) {
  int low = 0;
  int high = arr.length - 1;
  late int mid;

  while (low <= high) {
    mid = ((high + low) / 2).floor();

    if (arr[mid] == searchValue) {
      return mid;
    } else if (arr[mid] < searchValue) {
      low = mid + 1;
    } else if (arr[mid] > searchValue) {
      high = mid - 1;
    }
  }

  return -1;
}
