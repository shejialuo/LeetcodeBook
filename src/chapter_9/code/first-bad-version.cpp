extern bool isBadVersion(int version);

int firstBadVersion(int n) {
  int start = 1, end = n;
  while (start < end) {
    int mid = (end - start) / 2 + start;
    if (isBadVersion(mid)) {
      end = mid;
    } else {
      start = mid + 1;
    }
  }
  return start;
}
